int isLeap(int y){
    if ((y%4==0 && (y%100)>0) || y%400==0) return 1;
    return (0);
}
