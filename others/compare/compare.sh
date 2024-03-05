#!/bin/bash

if [[ $(locale | grep LC_ALL | cut -d'=' -f2-) != "C" ]]; then
	lang=$(locale | grep LANG | cut -d'=' -f2-)
	export LC_ALL=C
fi

Help()
{
	echo "usage: ./compare.sh [OPTION] <PATH A> <PATH B>"
	echo "options:"
	echo "-a: compare hidden files instead of ignoring them"
	echo "-h: output information about compare.sh"
	echo "-l: treat symlinks as files instead of ignoring them"
	echo "-n <EXP>: compare only files whose paths follow the REGEX <EXP>"
	echo "-r: compare directories recursively"
	exit
}

optA=0;
optN=0;
optR=0;
optL=0;
regex=""
input1=""
input2=""

compareFile()
{	
	local difference=$(diff -d $1 $2)
	if [[ -n "$difference" ]]; then
		local x=0
		if [[ $difference == "binary"* ]] || [[ $difference == "Binary"* ]] || [[ $difference == "二元碼檔"* ]]; then
			x=100
		else
			local a=0
			local b=0
			local c=0
			IFS=$'\n'
			for line in $difference; do
				if [[ $line == \<* ]]; then
					((a++))
				elif [[ $line == \>* ]]; then
					((b++))
				fi
			done			
			c=$(diff --unchanged-group-format='%=' --old-group-format='' --new-group-format='' $1 $2 | wc -l)
			local max=$((a>b?a:b))
			((x=100*$max/($max+$c)))
		fi
		echo $x
	fi
}

reCur()
{
	local path=$1
	if [[ -d $path ]]; then
		for file in $(ls -a $path); do
			if [[ $file == "." ]] || [[ $file == ".." ]]; then
				continue
			elif [[ $file == .* ]] && [[ $optA -ne 1 ]]; then
				continue
			fi
			local infile=$path/$file
			if [[ -h $infile ]]; then
				if [[ $optL -eq 1 ]]; then
					if [[ $path == "$input1"* ]]; then
						echo delete ${infile#"$input1/"}
					else
						echo create ${infile#"$input2/"}
					fi
				fi
			elif [[ -f $infile ]]; then
				if [[ $path == "$input1"* ]]; then
					echo delete ${infile#"$input1/"}
				else
					echo create ${infile#"$input2/"}
				fi
			elif [[ -d $infile ]]; then
				reCur $infile
			fi
		done
	fi
}

compareDir()
{
	local difference=$(diff -x '.*' -rq --no-dereference $1 $2)
	if [[ $optA -eq 1 ]]; then
		difference=$(diff -rq --no-dereference $1 $2)
	fi
	if [[ -n "$difference" ]]; then
		IFS=$'\n'
		for line in $difference; do
			if [[ $line == "File"* ]] || [[ $line == "檔案"* ]]; then
				local file1=$(echo $line | cut -d' ' -f2)
				local file2=""
				if [[ $line == "Files"* ]] || [[ $line == "檔案"* ]]; then
					file2=$(echo $line | cut -d' ' -f4)
				else
					if [[ $(echo $line | cut -d' ' -f5) == "directory" ]]; then
						file2=$(echo $line | cut -d' ' -f8)
					else
						file2=$(echo $line | cut -d' ' -f9)
					fi
				fi
				if [[ -h $file1 ]] || [[ -h $file2 ]]; then
					if [[ $optL -eq 1 ]]; then
						echo ${file1#"$input1/"}: changed 100%
					else
						if [[ -h $file1 ]] && [[ -h $file2 ]]; then
							continue
						elif [[ -h $file1 ]]; then
							echo create ${file2#"$input2/"}
						elif [[ -h $file2 ]]; then
							echo delete ${file1#"$input1/"}
						fi
					fi
					continue
				elif [[ -f $file1 ]] && [[ -f $file2 ]]; then
					echo ${file1#"$input1/"}: changed $(compareFile $file1 $file2)%
				else
					if [[ -d $file1 ]]; then
						echo create ${file2#"$input2/"}
						reCur $file1
					else
						echo delete ${file1#"$input1/"}
						reCur $file2
					fi
				fi
			elif [[ $line == "Only in"* ]]; then
				local message=$(echo $line | cut -d' ' -f3)
				message=${message%":"}
				message=$(echo $message/$(echo $line | cut -d' ' -f4))
				if [[ -h $message ]]; then
					if [[ $optL -eq 1 ]]; then
						if [[ $message == "$input1"* ]]; then
							echo delete ${message#"$input1/"}						
						else
							echo create ${message#"$input2/"}
						fi
					fi
				elif [[ -d $message ]]; then
					reCur $message
				else
					if [[ $message == "$input1"* ]]; then
						echo delete ${message#"$input1/"}
					else
						echo create ${message#"$input2/"}
					fi
				fi
			elif [[ $line == "Symbolic"* ]]; then
				local file1=$(echo $line | cut -d' ' -f3)
				if [[ $optL -eq 1 ]]; then
					echo ${file1#"$input1/"}: changed 100%
				fi	
			fi
		done
	fi
}

while getopts ":ahln:r" option;
do
	case $option in
		a)	optA=1;;
		l) 	optL=1;;
		h)	Help;;
		n)  optN=1
			regex=$OPTARG
			if [[ -z "$regex" ]]; then
				Help;
			fi;;
		r) 	optR=1;;
		\?)	Help;;
	esac
done

shift $((OPTIND - 1))

if [[ $# -ne 2 ]]; then
	Help;
fi

input1=$1
input2=$2

if [[ $optR -eq 1 ]]; then
	if [[ ! -d $1 ]] || [[ ! -d $2 ]]; then
		Help;
	elif [[ -h $1 ]] || [[ -h $2 ]]; then
		Help;
	else
		if [[ -n "$regex" ]]; then
			filename=""
			IFS=$'\n'
			for line in $(compareDir $1 $2); do
				if [[ $line == "delete"* ]] || [[ $line == "create"* ]]; then
					filename=$(echo $line | rev | cut -d' ' -f1 | cut -d'/' -f1 | rev)
				else
					filename=$(echo $line | cut -d' ' -f1)
					filename=${filename%":"}
					filename=$(echo $filename | rev | cut -d'/' -f1 | rev)
				fi	
				if [[ "$filename" =~ "$regex" ]]; then
					echo $line
				fi
			done
		else
			compareDir $1 $2
		fi
	fi
else
	if [[ $optA -eq 1 ]] || [[ $optN -eq 1 ]]; then
		Help;
	elif [[ -d $1 ]] || [[ -d $2 ]]; then
		Help;
	elif [[ -h $1 ]] || [[ -h $2 ]]; then
		if [[ $optL -eq 1 ]]; then
			if [[ -h $1 ]] && [[ -h $2 ]]; then
				if [[ $(readlink $1) != $(readlink $2) ]]; then
					echo changed 100%
				fi
			else
				echo changed 100%
			fi
		else
			Help;
		fi
	elif [[ -f $1 ]] && [[ -f $2 ]]; then
		echo changed $(compareFile $1 $2)%
	else
		Help;
	fi
fi

if [[ -n "$lang" ]]; then
	export LC_ALL=$lang
fi

