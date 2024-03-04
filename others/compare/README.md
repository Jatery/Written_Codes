# Comparing Files or Directories

This is a shell script for an anonymous course's homework, but unfortunately, it had some bugs while I handed it out...

Never mind. This shell script is for comparing files and directories, and with some options, you can choose to compare symbolic links and hidden files together, or only compare files with specific file names.

## How To Use It

Type `./compare.sh -h` for the following message:

```
usage: ./compare.sh [OPTION] <PATH A> <PATH B>
options:
-a: compare hidden files instead of ignoring them
-h: output information about compare.sh
-l: treat symlinks as files instead of ignoring them
-n <EXP>: compare only files whose paths follow the REGEX <EXP>
-r: compare directories recursively
```

The script compares two files if coming with no options:

```
$ ./compare.sh a.txt b.txt
changed: 40%
```

Noting that the number comes from calculating how many adding ($a$), deleting ($b$) lines to make them alike and how many common lines ($c$), with the formula $\lfloor \frac{100max(a,b)}{max(a,b)+c} \rfloor$, or $100$ for binary files.

Adding the option `-r`, it would compare the directories recursively, causing some of the messages below:

```
$ ./compare.sh -r dir1 dir2
delete a.out
code/main.c: changed 8%
create dir/text.txt
```

The `delete` or `create` message signifies that for the first directory to become alike as the second directory, which files should be deleted or created. The script only focus on the files instead of directories, so an empty directory might be ignored btw.

Adding `-a` to compare hidden files too, and `-l` to treat symlinks as files. The symlinks are differ when their results of `readlink` aren't the same, and none of the symlinks will be read into the files they symbolies.

```
$ ./compare.sh -r -a -l dir1 dir2
delete code/.gitignore
link: changed 100%
```

Adding `-n <EXP>` for only comparing the files whose filename satisfies the `<EXP>` expression.

```
$ ./compare.sh -r -n txt dir1 dir2
delete dir/a.txt
create dir/b.txt
dir/c.txt: changed 20%
```

Note that `-n` and `-a` options can only be used with the options `-r`.`
