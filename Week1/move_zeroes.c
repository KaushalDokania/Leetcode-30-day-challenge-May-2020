void moveZeroes(int* a, int numsSize){
    int i=0, j=0;
    while (i<numsSize && j<=i)
    {
        if(a[i]!=0)
            a[j++] = a[i];
        ++i;
        
    }
    while(j<numsSize)
        a[j++] = 0;
}
