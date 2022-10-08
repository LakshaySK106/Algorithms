public class Main{
    public static void main(String[] args){
    Scanner scn=new Scanner(System.in);
        int n=scn.nextInt(); 
//         size of first array
        int m=scn.nextInt();
//         size of second array
        int[] nums1=new int[n];
        for(int i=0;i<n;i++){
            nums1[i]=scn.nextInt();
        }
        int[] nums2=new int[m];
        for(int i=0;i<m;i++){
            nums2[i]=scn.nextInt();
        }
        int[] arr=new int[n];
           arr=nextGreaterElement(nums1,nums2);
      System.out.println(Arrays.toString(arr));
    }
    public static int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int[] result = new int[nums1.length];
        Stack<Integer> stack=new Stack<>();
        Map<Integer, Integer> map = new HashMap<>();

        for(int num: nums2){            
            while(!stack.isEmpty() && num > stack.peek())
                map.put(stack.pop(), num);
            stack.push(num);            
        }
        
        int i=0;        
        for(int num : nums1)
            result[i++] = map.getOrDefault(num, -1);
        return result;
    }
}
