import java.util.*;
public class bestFit {
    public static void findFit(int[] blockSize,int m,int[] processSize,int n){
        int[] allocation=new int[n];
        for(int i=0;i<n;i++){
            allocation[i]=-1;
        }

        for(int i=0;i<n;i++){
            int bestIdx=-1;
            for(int j=0;j<m;j++){
                if(blockSize[j]>=processSize[i]){
                    if(bestIdx==-1){
                        bestIdx=j;
                    }
                    else if(blockSize[bestIdx]>blockSize[j]){
                        bestIdx=j;
                    }
                }
            }
            if(bestIdx!=-1){
                allocation[i]=bestIdx;
                blockSize[bestIdx]-=processSize[i];
            }
        }

        System.out.println("Process No\t Process Size\t Block No.");
        for(int i=0;i<n;i++){
            System.out.print((i+1)+"\t\t"+processSize[i]);
            if(allocation[i]!=-1){
                System.out.print("\t\t"+(allocation[i]+1));
            }
            else{
                System.out.print("\tNot Allocated");
            }
            System.out.println();
        }
    }

    public static void main(String args[]){
        Scanner scanner=new Scanner(System.in);

        System.out.println("Enter the number of BlocksArray and ProcessArray respectively: ");
        int m=scanner.nextInt();
        int n=scanner.nextInt();

        int processSize[]=new int[n];
        System.out.println("Enter the values in ProcessArray: ");
        for(int i=0;i<n;i++){
            processSize[i]=scanner.nextInt();
        }

        int blockSize[]=new int[m];
        System.out.println("Enter the values in BlockArray: ");
        for(int i=0;i<m;i++){
            blockSize[i]=scanner.nextInt();
        }

        findFit(blockSize,m,processSize,n);
    }
}
