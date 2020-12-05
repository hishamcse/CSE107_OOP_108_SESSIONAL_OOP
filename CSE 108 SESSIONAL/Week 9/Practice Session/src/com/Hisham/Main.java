package com.Hisham;

import java.util.Arrays;
import java.util.Random;

class ParallelMax implements Runnable {
    public static int max=0;
    int[] numbers;
    Thread t;

    public ParallelMax(int[] numbers){
        this.numbers=numbers;
        t=new Thread(this);
        t.start();
    }

    @Override
    public void run() {
        for(int i = 0; i < numbers.length; i++) {
            if(max<numbers[i]){
                max=numbers[i];
            }
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Random random = new Random(1);
        int [] numbers = new int[1000];
        for (int i = 0; i < numbers.length; i++) {
            numbers[i] = random.nextInt();
        }
        ParallelMax [] parallelMax = new ParallelMax[5];
        parallelMax[0]=new ParallelMax(Arrays.copyOfRange(numbers,0,200));
        parallelMax[1]=new ParallelMax(Arrays.copyOfRange(numbers,201,400));
        parallelMax[2]=new ParallelMax(Arrays.copyOfRange(numbers,401,600));
        parallelMax[3]=new ParallelMax(Arrays.copyOfRange(numbers,601,800));
        parallelMax[4]=new ParallelMax(Arrays.copyOfRange(numbers,801,1000));

        try{
            for(int i=0;i<5;i++){
                parallelMax[i].t.join();
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        // your code here
        System.out.println(ParallelMax.max);
    }
}
