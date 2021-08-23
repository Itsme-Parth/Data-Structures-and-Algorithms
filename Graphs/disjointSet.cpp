int parent[100000];
int rank[100000];

void makeSet()
{
    for (int i = 1; i <= N; i++) //1 - indexed graph
    {
        parent[i] = i;
        rank[i] = 0;
    }
}
//7->6->4->3
void findPar(int node)
{
    if (node == parent[node]) //the ultimate parent
    {
        return node;
    }

    /* return findPar(parent[node]); otherwise lets go around and find the parent */
    return parent[node] = findPar(parent[node]); //Path Compression as storing the super parent directly
}

void union(int u, int v)
{
    u = findPar(u);
    v = findPar(v);

    if (rank[u] < rank[v]) //hence we'll attach u to v
    {
        parent[u] = v; //now parent of u becomes v as rank[u] < rank[v]
    }
    else if (rank[v] < rank[u]) //here we'll attach v to u
    {
        parent[v] = u; //now parent of v becomes u as rank[v] < rank[u]
    }
    else
    {
        parent[u] = v;
        rank[v]++; //here when both ranks are equal we can attach to any one of them and the level will increase here
    }
}
int main()
{
    makeSet();
    return 0;
    //if 2 and 3 belong to the same component or not, just check if they have same parents
    if (findPar(2) != findPar(3))
    {
        return false;
    }
    else
        return true;
}