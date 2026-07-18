# C++ 학습 간 기록

표준 라이브러리로 std 사용   
식별자 구분 용도로 namespace 사용   
namespace를 가리키기 위해 범위 지정 연산자 " :: " 사용   
   
ex )
```
std::cout << "hello world";
```

using namespace std; 를 추가해줌으로써 표준 라이브러리 문법에 std:: 생략 가능   
   
ex )   
```
using namespace std;
int main(){

  int pos = 10;
  cout << "현재 위치 : " << pos << "\n";
  return 0;
}
```

상수로 const 사용
