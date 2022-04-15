#include "Family.h"
#include "Luxury.h"
#include <string>
#include <vector>

class Rational
{
  public:
  Rational():m_num(0),m_den(1){};
  Rational(const long long int &num, const long long int &den) : m_num(num), m_den(den) {};
  Rational(const Rational& rhs)
  {
    m_num = rhs.m_num;
    m_den = rhs.m_den;
  };

  //make a sense when there is an allocated dynamic memory 
  //and mus be prevented to be copyed in heap memory
  Rational(Rational&& rhs) noexcept : m_num(rhs.m_num), m_den(rhs.m_den)
  {
    rhs.m_num = 0;
    rhs.m_den = 0;
  };
  //an ordinary destructor
  //there is no dynamicly allocated memory
  ~Rational(){};

  //setters and getters for memeber data
  inline void setNum( const long long int &_num ){ m_num = _num; }
  inline void setDen( const long long int &_den ){ m_den = _den; }

  inline long long int getNum() const { return m_num; }
  inline long long int getDen() const { return m_den; }

  //operator overloading
  bool operator==( const Rational& rhs )
  {
      return (m_num == rhs.m_num && m_den == rhs.m_den);
  }

  Rational& operator+=( const Rational &rhs )
  {
    m_num = m_num*rhs.m_den + m_den*rhs.m_num;
    m_den = m_den*rhs.m_den;

    return *this;
  }

  Rational& operator=( const Rational &rhs )
  {
    m_num = rhs.m_num;
    m_den = rhs.m_den;
  }

  Rational operator+( const Rational &rhs ) const
  {
    Rational to_return;
    
    to_return.m_num = m_num*rhs.m_den + m_den*rhs.m_num;
    to_return.m_den = m_den*rhs.m_den;

    return to_return;
  }

  private:
  long long int m_num;
  long long int m_den;
};

int main (){
	//                                         nomer shasi         razhod, izminati km, taksa za den, dni
	Family famKola1("VW", "Passat", "Sedan", "Black", 210695, "PB9595MK", 6.7, 600, 50, 4);
	Luxury luxKola ("Mercedes", "S320", "Sedan", "Black", 120690, "CM5475MC", 8.7, 600, 50, 4, "Vino");
	famKola1.getPayment();
	luxKola.getPayment();

	vector<Auto*> carsContainer(2);
	carsContainer[0] = &famKola1;
	carsContainer[1] = &luxKola;

	cout << endl;
	return 0;
}
