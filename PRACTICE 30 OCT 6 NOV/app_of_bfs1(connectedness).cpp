/*connectedness*/
#include<iostream>
#include<queue>
#define NODE 5
using namespace std;
int graph[NODE][NODE] = {
   {0, 1, 1, 0, 0},
   {1, 0, 1, 1, 0},
   {1, 1, 0, 1, 1},
   {0, 1, 1, 0, 1},
   {0, 0, 1, 1, 0}};
void traverse(int s, bool visited[]) {
   visited[s] = true; 
   queue<int> que;
   que.push(s);
   while(!que.empty()) {
      int u = que.front(); 
      que.pop();
      for(int i = 0; i < NODE; i++) {
         if(graph[i][u]) {
            
            if(!visited[i]) {
               visited[i] = true;
               que.push(i);
            }
         }
      }
   }
}
bool isConnected() {
   bool *vis = new bool[NODE];

   for(int u; u < NODE; u++) {
      for(int i = 0; i < NODE; i++)
         vis[i] = false; 
         traverse(u, vis);
      for(int i = 0; i < NODE; i++) {
         if(!vis[i]) 
            return false;
      }
   }
   return true;
}
int main() {
   if(isConnected())
      cout << "The Graph is connected.";
   else
      cout << "The Graph is not connected.";
}
