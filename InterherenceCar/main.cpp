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
	
  //chained functions example
  inline Rational& acumulateNum( const long long int &_num )
  {
     m_num += _num; 
     return *this;
  }

  inline Rational& acumulateDen( const long long int &_den )
  {
     m_den += _den; 
     return *this;
  }

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

class String
{
  public:

  String() : m_data(nullptr), m_size(0) {};
  String( const char *_data )
  {
    printf("S constructed\n");

    m_size = strlen(_data);
    m_data = new char[m_size];
    std::memcpy( m_data, _data, m_size);
  }
  String( const String &rhs)
  {
    printf("S copyed\n");
    m_size = rhs.m_size;
    m_data = rhs.m_data;
  }
  String( String &&rhs) noexcept : m_size(rhs.m_size), m_data(rhs.m_data)
  {
    printf("S moved\n");
    rhs.m_size = 0;
    rhs.m_data = nullptr;
  }
  ~String()
  {
    printf("S destructed\n");
    delete[] m_data;
  }

  void Print()
  {
    for(size_t i{0}; i < m_size; ++i)
      printf("%c", m_data[i]);
  }

  private:
  char *m_data;
  unsigned short m_size;
};

class Entity
{
  public:

  Entity(String && rhs) : m_info(std::move(rhs)) {};
  
  void printEntitysInfo()
  {
    m_info.Print();   
  }


  private:
  String m_info;
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
