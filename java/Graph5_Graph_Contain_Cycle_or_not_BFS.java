/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Striver;
import java.util.*;
/**
 *
 * @author Nitish Kumar Maurya
 */
class Node{
    int first;
    int parent;
    Node(int f,int p)
    {
        this.first=f;
        this.parent=p;
    }
}
public class Graph5_Graph_Contain_Cycle_or_not_BFS {
    public static boolean isCycle(int s,int v,ArrayList<ArrayList<Integer>>adj,boolean []vis)
    {
        Queue<Node>q1=new LinkedList<>();
        q1.add(new Node(s,-1));
        vis[s]=true;
        while(!q1.isEmpty())
        {
            int fir=q1.peek().first;
            int par=q1.peek().parent;
            q1.remove();
            for(Integer it:adj.get(fir))
            {
                if(vis[it]==false)
                {
                    q1.add(new Node(it,fir));
                    vis[it]=true;
                }
                else{
                    if(it!=par)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    public static boolean cycleGraph(int n,ArrayList<ArrayList<Integer>>adj)
    {
        boolean[]vis=new boolean[n+1];
        Arrays.fill(vis,false);
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                if(isCycle(i,n,adj,vis))
                    return true;
            }
        }
        return false;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter no of vertex");
        int n=sc.nextInt();
        System.out.println("Enter no of edges");
        int e=sc.nextInt();
        ArrayList<ArrayList<Integer>>adj=new ArrayList<ArrayList<Integer>>();        
        for(int i=0;i<=n;i++)
        {
            adj.add(new ArrayList<Integer>());
        }
        for(int i=0;i<e;i++)
        {
            int u=sc.nextInt(),v=sc.nextInt();
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        boolean cycle=cycleGraph(n,adj);
        if(cycle)
            System.out.println("Cycle is present");
        else
            System.out.println("Cycle not present");
    }
}
