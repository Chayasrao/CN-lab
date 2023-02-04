from sys import maxsize as m
class graph:
    def __init__(self,v):
        self.v=v
        self.lst=[]
    def add_edge(self,src,dst,wt):
        self.lst.append([src,dst,wt])
    def bellmann(self,src):
        dist=[m]*self.v
        dist[src]=0
        for i in range(self.v - 1):
            for u, v, w in self.lst:
                if dist[u] != m and dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w
        for u, v, w in self.lst:
            if dist[u] != m and dist[u] + w < dist[v]:
                print("Graph contains negative weight cycle")  
                return
        print("Vertex\t\tDistance from source")
        for i in range(self.v):
            print(i,"\t\t", dist[i])

n,e=map(int,input("Enter the number of vertices and edges:").split())
g=graph(n)
print("Enter the edges as source destination weight:")
for i in range(e):
    s,d,w=map(int,input().split())
    g.add_edge(s,d,w)
src=int(input("Enter the start vertex:"))
g.bellmann(src)