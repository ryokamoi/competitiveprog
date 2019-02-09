#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

struct edge{
    int from, to;
    ll cost;
};

ll INF = 10e17;
edge es[2000];
ll d[1000];
int V, E; // vertex, edge

bool find_negative_loop(){
    REP(i, V) d[i] = 0;

    REP(i, V){
        REP(j, E){
            edge e = es[j];
            if(d[e.to]>d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;

                if(i == V-1) return true;
            }
        }
    }
    return false;
}

// type B
bool b(int s){
    REP(i, V) d[i] = INF;
    d[s] = 0;
    REP(i, V){
        REP(j, E){
            edge e = es[j];
            if(d[e.from]!=INF && d[e.to]>d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;

                if(i == V-1) return true;
            }
        }
    }
    return false;
}

// type C
bool shortest_path(int s, int t){ // t: destination
    REP(i, V) d[i] = INF;
    d[s] = 0;
    REP(i, 2*V){
        REP(j, E){
            edge e = es[j];
            if(d[e.from]!=INF && d[e.to]>d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;

                if(i>=V-1 && e.to==t) return true;
            }
        }
    }
    return false;
}

int main(){
    cin >> V >> E;
    REP(i, E){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a -= 1;
        b -= 1;
        edge e;
        e.from = a; e.to = b; e.cost = c;
        es[i] = e;
    }

    if(find_negative_loop()){
        cout << "A" << endl;
    }
    
    if(b(0)) cout << "B" << endl;
    
    bool flag = shortest_path(0, V-1);
    if(flag){
        cout << "-inf" << endl;
    } else {
        cout << d[V-1] << endl;
    }
}
