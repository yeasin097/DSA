#include<stdio.h>

void swap(int *a, int *b){
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;

}

void bubble_sort(int arr[], int n){
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                    //swap(&arr[i], &arr[j]);
                    int temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
            }
        }
    }
}


void print_array(int array[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}
int main(){

    int array[7]={2,1,4,8,3,5,0};
    print_array(array, 7);
    bubble_sort(array, 7);
    print_array(array, 7);
}
