 #include <stdio.h>
 
int abs(int k) {
    return k >= 0 ? k : -k;
}
 
struct parking_lot {
    int x;
    int y;
    int capacity;
    int num;
};
 
int main() {
    int n, m, x, y;
    scanf("%d", &n);
    struct parking_lot parks[n];
    for(int i = 0; i < n; ++i) {
        scanf("%d%d%d", &parks[i].x, &parks[i].y, &parks[i].capacity);
        parks[i].num = 0;
    }
    scanf("%d", &m);
    while(m--) {
        scanf("%d%d", &x, &y);
        int tmp = 0, x_dist = 20005, y_dist = 20005;
        for(int i = 0; i < n; ++i)
            if(parks[i].num < parks[i].capacity ) {
                if((abs(x - parks[i].x) + abs(y - parks[i].y) < x_dist + y_dist) || (abs(x - parks[i].x) + abs(y - parks[i].y) == x_dist + y_dist && parks[i].x < parks[tmp].x) || (abs(x - parks[i].x) + abs(y - parks[i].y) == x_dist + y_dist && parks[i].x == parks[tmp].x && parks[i].y < parks[tmp].y)) {
                    x_dist = abs(x - parks[i].x);
                    y_dist = abs(y - parks[i].y);
                    tmp = i;
                }
            }
        parks[tmp].num++;
    }
    for(int i = 0; i < n; ++i)
        printf("%d\n", parks[i].num);
}
