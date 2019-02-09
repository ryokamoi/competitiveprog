#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int ps[100][2];

int main(){
    while(1){
        int n, W, D;
        cin >> n >> W >> D;

        if(W==0){
            break;
        }

        for(int i=0; i<n; i++){
            int p, s;
            cin >> p >> s;
            ps[i][0] = p;
            ps[i][1] = s;
        }

        vector<pair<int, int> > vec;
        pair<int, int> init = make_pair(W, D);
        vec.push_back(init);
        for(int i=0; i<n; i++){
            int p = ps[i][0];
            int s = ps[i][1];

            pair<int, int> wd = vec[p-1];
            vec.erase(vec.begin() + p - 1);
            int w = wd.first;
            int d = wd.second;

            int peri = w+d;
            s = s % peri;

            pair<int, int> wd1;
            pair<int, int> wd2;
            if(s < w){
                wd1.first = s;
                wd2.first = w - s;
                wd1.second = d;
                wd2.second = d;
            } else {
                wd1.first = w;
                wd2.first = w;
                wd1.second = s - w;
                wd2.second = d - wd1.second;
            }

            if(wd1.first * wd1.second < wd2.first * wd2.second){
                vec.push_back(wd1);
                vec.push_back(wd2);
            } else {
                vec.push_back(wd2);
                vec.push_back(wd1);
            }
        }

        vector<int> output(vec.size());
        for(int i=0; i<vec.size(); i++){
            pair<int, int> wd = vec[i];
            int w = wd.first;
            int d = wd.second;
            output[i] = w*d;
        }

        sort(output.begin(), output.end());
        for(int i=0; i<vec.size(); i++){
            if(i != 0){
                cout << " ";
            }
            cout << output[i];
        }
        cout << endl;
    }
}
