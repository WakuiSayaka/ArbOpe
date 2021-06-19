#include<iostream>
#include "arb.h"
#include "arb_hypgeom.h"
#include "acb_hypgeom.h"
/*
演算の値にdouble型は許容していない。(構造体arb_tにdouble型の値を入れる関数はあるが,ゴミが混入してしまう為)
*/

ulong prec=256; //精度

class Arb {
	arb_t value; //private
public:
	// デストラクタ
	// 変数の寿命が来た時にクラスのメモリを解放する。
	~Arb(void) {};

	// obj は Arb型   obj.value は arb_t型
	/* インクリメント,デクリメント */

	//後置 後置はint型の実引数0が渡される
	//結果を返してからインクリメントされる必要がある為,返却用オブジェクトは別途作成する必要がある
	const Arb operator ++ (int);
	const Arb operator -- (int);

	//前置 先にインクリメントを行い自身の参照を返す
	Arb& operator ++ (void) {
		*this += 1;
		return *this;
	}

	Arb& operator -- (void) {
		*this -= 1;
		return *this;
	}

	/* 正号,負号 */
	inline const Arb operator + (void) const {
		return *this;
	}

	const Arb operator - (void) const;

	/* 算術演算子 */
	friend const Arb operator * (const Arb lhs,const Arb rhs) {
		Arb res;
    arb_mul(res.value,lhs.value,rhs.value,prec);
		return res;
	}
	friend const Arb operator * (const Arb lhs,const arb_t rhs) {
		Arb res;
		arb_mul(res.value,lhs.value,rhs,prec);
		return res;
	}
	friend const Arb operator * (const arb_t lhs,const Arb rhs) {
		Arb res;
		arb_mul(res.value,lhs,rhs.value,prec);
		return res;
	}
	friend const Arb operator * (const Arb lhs,const slong rhs) {
		Arb res;
		arb_mul_si(res.value,lhs.value,rhs,prec);
		return res;
	}
	friend const Arb operator * (const slong lhs,const Arb rhs) {
		Arb res;
		Arb temp;
		temp = lhs;
		arb_mul(res.value,temp.value,rhs.value,prec);
		return res;
	}
	friend const Arb operator * (const Arb lhs,const int rhs) {
		Arb res;
		Arb temp;
		temp = rhs;
		arb_mul(res.value,lhs.value,temp.value,prec);
		return res;
	}
	friend const Arb operator * (const int lhs,const Arb rhs) {
		Arb res;
		Arb temp;
		temp = lhs;
		arb_mul(res.value,temp.value,rhs.value,prec);
		return res;
	}

	friend const Arb operator / (const Arb lhs,const Arb rhs) {
		Arb res;
    arb_div(res.value,lhs.value,rhs.value,prec);
		return res;
	}
	friend const Arb operator / (const Arb lhs,const arb_t rhs) {
		Arb res;
		arb_div(res.value,lhs.value,rhs,prec);
		return res;
	}
	friend const Arb operator / (const arb_t lhs,const Arb rhs) {
		Arb res;
		arb_div(res.value,lhs,rhs.value,prec);
		return res;
	}
	friend const Arb operator / (const Arb lhs,const slong rhs) {
		Arb res;
		arb_div_si(res.value,lhs.value,rhs,prec);
		return res;
	}
	friend const Arb operator / (const slong lhs,const Arb rhs) {
		Arb res;
		Arb temp;
		temp = lhs;
		arb_div(res.value,temp.value,rhs.value,prec);
		return res;
	}
	friend const Arb operator / (const Arb lhs,const int rhs) {
		Arb res;
		Arb temp;
		temp = rhs;
		arb_div(res.value,lhs.value,temp.value,prec);
		return res;
	}
	friend const Arb operator / (const int lhs,const Arb rhs) {
		Arb res;
		Arb temp;
		temp = lhs;
		arb_div(res.value,temp.value,rhs.value,prec);
		return res;
	}

	friend const Arb operator + (const Arb lhs,const Arb rhs) {
		Arb res;
    arb_add(res.value,lhs.value,rhs.value,prec);
		return res;
	}
	friend const Arb operator + (const Arb lhs,const arb_t rhs) {
		Arb res;
		arb_add(res.value,lhs.value,rhs,prec);
		return res;
	}
	friend const Arb operator + (const arb_t lhs,const Arb rhs) {
		Arb res;
		arb_add(res.value,lhs,rhs.value,prec);
		return res;
	}
	friend const Arb operator + (const Arb lhs,const slong rhs) {
		Arb res;
		arb_add_si(res.value,lhs.value,rhs,prec);
		return res;
	}
	friend const Arb operator + (const slong lhs,const Arb rhs) {
		Arb res;
		Arb temp;
		temp = lhs;
		arb_add(res.value,temp.value,rhs.value,prec);
		return res;
	}
	friend const Arb operator + (const Arb lhs,const int rhs) {
		Arb res;
		Arb temp;
		temp = rhs;
		arb_add(res.value,lhs.value,temp.value,prec);
		return res;
	}
	friend const Arb operator + (const int lhs,const Arb rhs) {
		Arb res;
		Arb temp;
		temp = lhs;
		arb_add(res.value,temp.value,rhs.value,prec);
		return res;
	}

	friend const Arb operator - (const Arb lhs,const Arb rhs) {
		Arb res;
    arb_sub(res.value,lhs.value,rhs.value,prec);
		return res;
	}
	friend const Arb operator - (const Arb lhs,const arb_t rhs) {
		Arb res;
		arb_sub(res.value,lhs.value,rhs,prec);
		return res;
	}
	friend const Arb operator - (const arb_t lhs,const Arb rhs) {
		Arb res;
		arb_sub(res.value,lhs,rhs.value,prec);
		return res;
	}
	friend const Arb operator - (const Arb lhs,const slong rhs) {
		Arb res;
		arb_sub_si(res.value,lhs.value,rhs,prec);
		return res;
	}
	friend const Arb operator - (const slong lhs,const Arb rhs) {
		Arb res;
		Arb temp;
		temp = lhs;
		arb_sub(res.value,temp.value,rhs.value,prec);
		return res;
	}
	friend const Arb operator - (const Arb lhs,const int rhs) {
		Arb res;
		Arb temp;
		temp = rhs;
		arb_sub(res.value,lhs.value,temp.value,prec);
		return res;
	}
	friend const Arb operator - (const int lhs,const Arb rhs) {
		Arb res;
		Arb temp;
		temp = lhs;
		arb_sub(res.value,temp.value,rhs.value,prec);
		return res;
	}

	/* 比較演算子 */
	/* 対称性に注意 != と == , < と >= , など */

	friend const int operator < (const Arb lhs,const Arb rhs) {
		return arb_lt(lhs.value,rhs.value);
	}

	friend const int operator < (const Arb lhs,const arb_t rhs) {
		return arb_lt(lhs.value,rhs);
	}

	friend const int operator < (const arb_t lhs,const Arb rhs) {
		return arb_lt(lhs,rhs.value);
	}

	friend const int operator < (const Arb lhs,const slong rhs) {
		Arb temp;
		temp = rhs;
		return arb_lt(lhs.value,temp.value);
	}

	friend const int operator < (const slong lhs,const Arb rhs) {
		Arb temp;
		temp = lhs;
		return arb_lt(temp.value,rhs.value);
	}

	friend const int operator < (const Arb lhs,const int rhs) {
		Arb temp;
		temp = rhs;
		return arb_lt(lhs.value,temp.value);
	}

	friend const int operator < (const int lhs,const Arb rhs) {
		Arb temp;
		temp = lhs;
		return arb_lt(temp.value,rhs.value);
	}

	friend const int operator >= (const Arb lhs,const Arb rhs) {
		return !(lhs<rhs);
	}

	friend const int operator >= (const Arb lhs,const arb_t rhs) {
		return !(lhs<rhs);
	}

	friend const int operator >= (const arb_t lhs,const Arb rhs) {
		return !(lhs<rhs);
	}

	friend const int operator >= (const Arb lhs,const slong rhs) {
		return !(lhs<rhs);
	}

	friend const int operator >= (const slong lhs,const Arb rhs) {
		return !(lhs<rhs);
	}

	friend const int operator >= (const Arb lhs,const int rhs) {
		return !(lhs<rhs);
	}

	friend const int operator >= (const int lhs,const Arb rhs) {
		return !(lhs<rhs);
	}

	friend const int operator > (const Arb lhs,const Arb rhs) {
		return arb_gt(lhs.value,rhs.value);
	}

	friend const int operator > (const Arb lhs,const arb_t rhs) {
		return arb_gt(lhs.value,rhs);
	}

	friend const int operator > (const arb_t lhs,const Arb rhs) {
		return arb_gt(lhs,rhs.value);
	}

	friend const int operator > (const Arb lhs,const slong rhs) {
		Arb temp;
		temp = rhs;
		return arb_gt(lhs.value,temp.value);
	}

	friend const int operator > (const slong lhs,const Arb rhs) {
		Arb temp;
		temp = lhs;
		return arb_gt(temp.value,rhs.value);
	}

	friend const int operator > (const Arb lhs,const int rhs) {
		Arb temp;
		temp = rhs;
		return arb_gt(lhs.value,temp.value);
	}

	friend const int operator > (const int lhs,const Arb rhs) {
		Arb temp;
		temp = lhs;
		return arb_gt(temp.value,rhs.value);
	}

	friend const int operator <= (const Arb lhs,const Arb rhs) {
		return !(lhs>rhs);
	}

	friend const int operator <= (const Arb lhs,const arb_t rhs) {
		return !(lhs>rhs);
	}

	friend const int operator <= (const arb_t lhs,const Arb rhs) {
		return !(lhs>rhs);
	}

	friend const int operator <= (const Arb lhs,const slong rhs) {
		return !(lhs>rhs);
	}

	friend const int operator <= (const slong lhs,const Arb rhs) {
		return !(lhs>rhs);
	}

	friend const int operator <= (const Arb lhs,const int rhs) {
		return !(lhs>rhs);
	}

	friend const int operator <= (const int lhs,const Arb rhs) {
		return !(lhs>rhs);
	}

	friend const int operator == (const Arb lhs,const Arb rhs) {
		return arb_eq(lhs.value,rhs.value);
	}

	friend const int operator == (const Arb lhs,const arb_t rhs) {
		return arb_eq(lhs.value,rhs);
	}

	friend const int operator == (const arb_t lhs,const Arb rhs) {
		return arb_eq(lhs,rhs.value);
	}

	friend const int operator == (const Arb lhs,const slong rhs) {
		Arb temp;
		temp = rhs;
		return arb_eq(lhs.value,temp.value);
	}

	friend const int operator == (const slong lhs,const Arb rhs) {
		Arb temp;
		temp = lhs;
		return arb_eq(temp.value,rhs.value);
	}

	friend const int operator == (const Arb lhs,const int rhs) {
		Arb temp;
		temp = rhs;
		return arb_eq(lhs.value,temp.value);
	}

	friend const int operator == (const int lhs,const Arb rhs) {
		Arb temp;
		temp = lhs;
		return arb_eq(temp.value,rhs.value);
	}

	friend const int operator != (const Arb lhs,const Arb rhs) {
		return !(lhs==rhs);
	}

	friend const int operator != (const Arb lhs,const arb_t rhs) {
		return !(lhs==rhs);
	}

	friend const int operator != (const arb_t lhs,const Arb rhs) {
		return !(lhs==rhs);
	}

	friend const int operator != (const Arb lhs,const slong rhs) {
		return !(lhs==rhs);
	}

	friend const int operator != (const slong lhs,const Arb rhs) {
		return !(lhs==rhs);
	}

	friend const int operator != (const Arb lhs,const int rhs) {
		return !(lhs==rhs);
	}

	friend const int operator != (const int lhs,const Arb rhs) {
		return !(lhs==rhs);
	}

	/* 代入演算子 */
	/* 右辺値:Arb,arb_t,slong(整数値) */
	/* *thisを参照として返すようにする. a=b=c; のような連続的な呼び出しを可能にする為  */
	Arb operator = (const Arb obj) {
		arb_set(this->value,obj.value);
		return *this;
	}

	/* 複合代入演算子 */
	/* 代入演算子と同様に *this を返す */
	/* 四則演算のみ */
	Arb operator += (const Arb obj) {
    arb_add(this->value,this->value,obj.value,prec);
		return *this;
	}

	Arb operator -= (const Arb obj) {
    arb_sub(this->value,this->value,obj.value,prec);
		return *this;
	}

	Arb operator *= (const Arb obj) {
    arb_mul(this->value,this->value,obj.value,prec);
		return *this;
	}

	Arb operator /= (const Arb obj) {
    arb_div(this->value,this->value,obj.value,prec);
		return *this;
	}

	/* 宣言時の処理 */
	/* 無名関数? コンストラクタ?*/
	/* 引数を指定した場合 Arb a(arb_t型の変数) のように初期値を入れられる。*/
  Arb(void) { arb_init(this->value); }

	Arb(const arb_t obj) {
		arb_init(this->value);
		arb_set(this->value,obj);
	}

	Arb(const slong obj) {
		arb_init(this->value);
		arb_set_si(this->value,obj);
	}

	Arb(const int obj) {
		arb_init(this->value);
		if (!obj) {
			arb_zero(this->value);
		} else {
			arb_set_si(this->value,obj);
		}
	}

	/* Arbクラスの変数からarb_t型で取り出す為の関数 */
	void get(arb_t obj) { arb_set(obj,this->value); }

	/* print */
	void printn(slong digit) { //こちらはもう必要ない 過去に書いたプログラムを動かすために残している
		 arb_printn(this->value,digit,0);
	}

	void printn(slong digit,ulong flag) {
		 arb_printn(this->value,digit,flag);
	}

	/*
	定数          : 戻り値 -> なし this-> 書き換え
	関数(引数なし) : 戻り値 -> Arb this-> 書き換えない
	*/

	/* 絶対値 */
	Arb abs(void) {
		Arb res;
		arb_abs(res.value,this->value);
		return res;
	}

	/* 逆数 */
 	Arb inv(void) {
		Arb res;
		arb_inv(res.value,this->value,prec);
		return res;
	}

	/* 定数 */
	void zero(void) { arb_zero(this->value); }
	void one(void) { arb_one(this->value); }

	/* 数学定数 */
	//π
	void const_pi(void) { arb_const_pi(this->value,prec); }
	//sqrt(π)
	void const_sqrt_pi(void) { arb_const_sqrt_pi(this->value,prec); }
	//log(sqrt(2*π))
	void const_log_sqrt_2pi(void) { arb_const_log_sqrt2pi(this->value,prec); }
	//log(2)
  void const_log2(void) { arb_const_log2(this->value,prec); }
	//log(10)
	void const_log10(void) { arb_const_log10(this->value,prec); }
	//exp(1)
	void const_e(void) { arb_const_e(this->value,prec); }

	/* 冪乗と乗根 */
	//sqrt
	Arb sqrt(void) {
		Arb res;
		arb_sqrt(res.value,this->value,prec);
		return res;
	}

	//pow  x^y  y>0
	Arb pow(const Arb y)   {
		Arb res;
		arb_pow(res.value,this->value,y.value,prec);
		return res;
	}

	/* 指数関数と対数関数 */
	// x = log(x)
	Arb log(void) {
		Arb res;
		arb_log(res.value,this->value,prec);
		return res;
	}

	// x = exp(x)
	Arb exp(void) {
		Arb res;
		arb_exp(res.value,this->value,prec);
		return res;
	}

	/* 三角関数 */
	// x = sin(x)
	Arb sin(void) {
		Arb res;
		arb_sin(res.value,this->value,prec);
		return res;
	}

	// x = cos(x)
	Arb cos(void) {
		Arb res;
		arb_cos(res.value,this->value,prec);
		return res;
	}

	// x = tan(x)
	Arb tan(void) {
		Arb res;
		arb_tan(res.value,this->value,prec);
		return res;
	}

	// x = csc(x) = 1/sin(x)
	Arb csc(void) {
		Arb res;
		arb_csc(res.value,this->value,prec);
		return res;
	}

	// x = sec(x) = 1/cos(x)
	Arb sec(void) {
		Arb res;
		arb_sec(res.value,this->value,prec);
		return res;
	}

	// x = cot(x) = 1/tan(x)
	Arb cot(void) {
		Arb res;
		arb_cot(res.value,this->value,prec);
		return res;
	}

	/* 双曲線関数 */
	// x = sinh(x)
	Arb sinh(void) {
		Arb res;
		arb_sinh(res.value,this->value,prec);
		return res;
	}

	// x = cosh(x)
	Arb cosh(void) {
		Arb res;
		arb_cosh(res.value,this->value,prec);
		return res;
	}

	// x = tanh(x)
	Arb tanh(void) {
		Arb res;
		arb_tanh(res.value,this->value,prec);
		return res;
	}

	// x = csch(x)
	Arb csch(void) {
		Arb res;
		arb_csch(res.value,this->value,prec);
		return res;
	}

	// x = sech(x)
	Arb sech(void) {
		Arb res;
		arb_sech(res.value,this->value,prec);
		return res;
	}

	// x = coth(x)
	Arb coth(void) {
		Arb res;
		arb_coth(res.value,this->value,prec);
		return res;
	}

	/* ガンマ関数と階乗 */
	// x = n!
	Arb fac_ui(const ulong n) {
		Arb res;
		arb_fac_ui(res.value,n,prec);
		return res;
	}

	// x = Γ(x)
	Arb gamma(void) {
		Arb res;
		arb_gamma(res.value,this->value,prec);
		return res;
	}

	// x = 1/Γ(x)
	Arb rgamma(void) {
		Arb res;
		arb_rgamma(res.value,this->value,prec);
		return res;
	}

	/* ガウスの超幾何関数 */
	// x = 2f1(a,b,c,z)
	Arb hypgeom_2f1(const Arb a,const Arb b,const Arb c,const Arb z) {
  	int	regularized=ACB_HYPGEOM_2F1_ABC;
		Arb res;
		arb_hypgeom_2f1(res.value,a.value,b.value,c.value,z.value,regularized,prec);
		return res;
	}
};

//後置は前置のインクリメントを呼び出す形で実装する
//効率を考えた場合オブジェクトのインクリメントは可能な限り前置の方が良い
const Arb Arb::operator ++ (int) {
	const Arb temp = *this;
	++(*this);
	return temp;
}

const Arb Arb::operator -- (int) {
	const Arb temp = *this;
	--(*this);
	return temp;
}

/* 負号 */
const Arb Arb::operator - (void) const{
	Arb res;
	--res;
	res *= *this;
	return res;
}

/* print */
void Arb_print(Arb x,const slong digit) {
	x.printn(digit,0);
}

void Arb_print(Arb x,const slong digit,const ulong flags) {
	x.printn(digit,flags);
}

void Arb_print_nl(Arb x,const slong digit) {
	x.printn(digit,0); flint_printf("\n");
}

void Arb_print_nl(Arb x,const slong digit,ulong flags) {
	x.printn(digit,flags); flint_printf("\n");
}

/* 定数 */
void Arb_zero(Arb& res) {
	res.zero();
}
void Arb_one(Arb& res) {
	res.one();
}

/* 数学定数 */
//π
void Arb_pi(Arb& res) {
	res.const_pi();
}
//sqrt(π)
void Arb_sqrt_pi(Arb& res) {
	res.const_sqrt_pi();
}
//log(sqrt(2*π))
void Arb_log_sqrt_2pi(Arb& res) {
	res.const_log_sqrt_2pi();
}
//log(2)
void Arb_log2(Arb& res) {
	res.const_log2();
}
//log(10)
void Arb_log10(Arb& res) {
	res.const_log10();
}
//exp(1)
void Arb_e(Arb& res) {
	res.const_e();
}

/* 絶対値,逆数,入れ替え */
Arb Arb_abs(const Arb x) {
	Arb res;
	res = x;
	res = res.abs();
	return res;
}

Arb Arb_inv(const Arb x) {
	Arb res;
	res = x;
	res = res.inv();
	return res;
}

void Arb_swap(Arb& x,Arb& y) {
	Arb temp;
	temp = x;
	x = y;
	y = temp;
}

/* 関数 */
Arb Arb_sqrt(const Arb x) {
	Arb res;
	res = x;
	res = res.sqrt();
	return res;
}

Arb Arb_pow(const Arb x,const Arb y) {
	Arb res,temp;
	res  = x;
	temp = y;
	res  = res.pow(temp);
	return res;
}

Arb Arb_log(const Arb x) {
	Arb res;
	res = x;
	res = res.log();
	return res;
}

Arb Arb_exp(const Arb x) {
	Arb res;
	res = x;
	res = res.exp();
	return res;
}

Arb Arb_sin(const Arb x) {
	Arb res;
	res = x;
	res = res.sin();
	return res;
}

Arb Arb_cos(const Arb x) {
	Arb res;
	res = x;
	res = res.cos();
	return res;
}

Arb Arb_tan(const Arb x) {
	Arb res;
	res = x;
	res = res.tan();
	return res;
}

Arb Arb_csc(const Arb x) {
	Arb res;
	res = x;
	res = res.csc();
	return res;
}

Arb Arb_sec(const Arb x) {
	Arb res;
	res = x;
	res = res.sec();
	return res;
}

Arb Arb_cot(const Arb x) {
	Arb res;
	res = x;
	res = res.cot();
	return res;
}

Arb Arb_sinh(const Arb x) {
	Arb res;
	res = x;
	res = res.sinh();
	return res;
}

Arb Arb_cosh(const Arb x) {
	Arb res;
	res = x;
	res = res.cosh();
	return res;
}

Arb Arb_tanh(const Arb x) {
	Arb res;
	res = x;
	res = res.tanh();
	return res;
}

Arb Arb_csch(const Arb x) {
	Arb res;
	res = x;
	res = res.csch();
	return res;
}

Arb Arb_sech(const Arb x) {
	Arb res;
	res = x;
	res = res.sech();
	return res;
}

Arb Arb_coth(const Arb x) {
	Arb res;
	res = x;
	res = res.coth();
	return res;
}

Arb Arb_fac_ui(const Arb x,ulong n) {
	Arb res;
	res = x;
	res = res.fac_ui(n);
	return res;
}

Arb Arb_gamma(const Arb x) {
	Arb res;
	res = x;
	res = res.gamma();
	return res;
}

Arb Arb_rgamma(const Arb x) {
	Arb res;
	res = x;
	res = res.rgamma();
	return res;
}

Arb Arb_hypgeom_2f1(const Arb a,const Arb b,const Arb c,const Arb z) {
	Arb res;
	res = res.hypgeom_2f1(a,b,c,z);
	return res;
}
