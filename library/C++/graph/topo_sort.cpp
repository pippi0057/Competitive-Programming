vector<int> topo_sort(Graph &g){
    int n = g.size();
    Graph copy(n);
    vector<int> deg(n);
    vector<int> order;
    queue<int> task;
    rep(n) for(auto v : g[i]){
        copy[v.to].push_back(Edge(i, v.cost));
        deg[i]++;
    }
    rep(n) if(!deg[i]) task.push(i);
    while(task.size()){
        int fv = task.front();
        task.pop();
        order.push_back(fv);
        for(auto nv : copy[fv]){
            deg[nv.to]--;
            if(!deg[nv.to]) task.push(nv.to);
        }
    }
    reverse(all(order));
    return order;
}
