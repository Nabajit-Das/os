import java.util.*;
public class firstFit {
    public static void FirstFit(int[] blockSize,int m,int[] processSize,int n){
        int[] allocation=new int[n];
        for(int i=0;i<n;i++){
            allocation[i]=-1;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(blockSize[j]>=processSize[i]){
                    allocation[i]=j;
                    blockSize[j]-=processSize[i];
                    break;
                }
            }
        }

        System.out.println("Process No\t Process Size\t Block No.");
        for(int i=0;i<n;i++){
            System.out.print((i+1)+"\t\t"+processSize[i]);
            if(allocation[i]!=-1){
                System.out.print("\t\t"+(allocation[i]+1));
            }
            else{
                System.out.print("\t Not Allocated");
            }
            System.out.println();
        }
    }

    public static void main(String args[]){
        Scanner scanner=new Scanner(System.in);
        System.out.println("Enter the number of BlocksArray and ProcessArray respectively: ");
        int m=scanner.nextInt();
        int n=scanner.nextInt();
        System.out.println("Enter the values in ProcessArray: ");
        int processSize[]=new int[n];
        for(int i=0;i<n;i++){
            processSize[i]=scanner.nextInt();
        }

        System.out.println("Enter the values in BlockArray: ");
        int blockSize[]=new int[n];
        for(int i=0;i<m;i++){
            blockSize[i]=scanner.nextInt();
        }

        FirstFit(blockSize,m,processSize,n);
    }
}
