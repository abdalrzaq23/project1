 #include<iostream>

using namespace std;

int a[4][4]{
0,0,0,0,
0,0,0,1,
0,0,0,0,
0,0,0,0
};
///
int a1[4][4]={
3,2,-1,-1,
2,1,-1,-1,
1,0,-1,-1,
-1,-1,-1,-1};
///
int a3[4][4]={
0,0,0,0,
0,0,0,0,
0,0,1,0,
0,0,0,0
};
///
bool founded=0;
void recursion(int x,int y);
void recursion2(int x,int y);
int  recursion3(int x,int y);
int ans[4][4];
int main()
{

  ///بفرض يتم ادخال الغريد بحيث تكون الخلية اللي تحوي على الغرص تحوي الرقم 1 وباقي الخلايا اصفار

///  الخوارزمية التكرارية

    for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
        if(a[i][j]==1) {
            cout<<"object founded in row "<<i<<" and column "<<j<<endl;
        break ;
        }
    }
}
///time complixity of the previous algorithm is n*m in worst case
///
///recursin sollution with complixtu 2^ max(n,m)
/// we will use function called recursion to find the element
recursion(0,0);
/// الطلب التاني


  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
        if(a1[i][j]==0) {
            cout<<"object founded in row "<<i<<" and column "<<j<<endl;
        break ;
        }
    }
}
///قمنا بتعريفق تابع يدعى recursion2 لحل هاته المشكلة
founded=0;
recursion2(0,0);
///الطلب التالت
//

for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
        ans[i][j]=-1;
    }
}
recursion3(0,0);
for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
            if(ans[i][j]>=1e9) ans[i][j]=-1;
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}

}
//x هو الصف
//y هو العمود الحالي

void recursion(int x,int y){
if(x>=4 || y>=4 || founded==1) return ;
if(a[x][y]==1){
    cout<<"founded in row"<<x<<" and  column "<<y<<endl;
  founded=1;
  ///we used boolean called founded in order to if we found the element we will stop all recursion function
}
recursion(x+1,y);
recursion(x,y+1);
}
void recursion2(int x,int y){
if(x>=4  || y>=4 ||founded || a[x][y]==-1) return ;
if(a1[x][y]==0) {
        cout<<"founded in row "<<x<<" column  "<<y<<endl;
        founded=1;
        return ;
        };
        if(x+1<4 && y+1<4 && a[x+1][y]==a[x][y+1]){
           recursion2(x+1,y);
        }
        else{
recursion2(x+1,y);
recursion(x,y+1);
        }

}
///
int recursion3(int x,int y){
if(x>=4 || y>=4) return 1e9;
if(a3[x][y]==1){
        ans[x][y]=0;
        return 0;
}
if(ans[x][y]!=-1) return ans[x][y];
int k1=1+recursion3(x+1,y);
int k2=1+recursion3(x,y+1);
ans[x][y]=min(k1,k2);

return ans[x][y];
}
