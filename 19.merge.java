import java.util.*;
public class merge{
    public static void merges(int[] arr,int left,int right){
        if(left<right){
        int mid=left+(right-left)/2;
        merges(arr,left,mid);
        merges(arr,mid+1,right);
        mer(arr,left,mid,right);
        }

    }
    public static void mer(int[] arr,int left,int mid,int right){
        int n1=mid-left+1;
        int n2=right-mid;
        int [] leftarr=new int [n1];
        int [] rightarr=new int[n2];
        for(int i=0;i<n1;i++){
            leftarr[i]=arr[left+i];
        }
        for(int j=0;j<n2;j++){
            rightarr[j]=arr[mid+1+j];
        }
        int i=0,j=0,k=left;
        while(i<n1 && j<n2){
            if(leftarr[i]<=rightarr[j]){
                arr[k]=leftarr[i];
                i++;
            }
            else{
                arr[k]=rightarr[j];
                j++;
            }
            k++;
        }
        while(i<n1){
            arr[k]=leftarr[i];
            i++;
            k++;

        }
        while(j<n2){
            arr[k]=rightarr[j];
            j++;
            k++;
        }


    }
    public static void main(String[] args){
        Scanner scanner=new Scanner(System.in);
        System.out.print("enter a number of elements");
        int n=scanner.nextInt();
        int[] arr=new int[n];
        System.out.print("enter a elements:");
        for(int i=0;i<n;i++){
        arr[i]=scanner.nextInt();
        }
        System.out.print("entered array:");
        for(int num :arr){
        System.out.print(num+" ");
        }
        System.out.println();
        merges(arr,0,n-1);
        System.out.print("sorted array:");
        for(int num:arr){
        System.out.print(num+" ");
        }
        System.out.println();
        scanner.close();
        }
        }