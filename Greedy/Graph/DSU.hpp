#if !defined(DSU_H)
#define DSU_H

 class DisjointSU
 {
 private:
     int parent[1000007], size[1000007];
 public:
     void makeSet(int a);
     int king(int a);
     void unionbysize(int a, int b);

 };





int King(int par[],int a);
void Union(int par[],int u,int v);


#endif //
