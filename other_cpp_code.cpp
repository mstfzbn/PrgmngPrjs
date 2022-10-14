#include "includes.h"
 

static sigslot::signal<> sig;

static sigslot::signal<> sig_obj;

void foo() 
{
  std::cout << "foo\n";
}

void bar(int x)
{
  std::cout << "order: " << x << "\n";
}

void obj_echo()
{
  std::cout << "obj created" << "\n";
}


void pretty_func(){ std::cout << __PRETTY_FUNCTION__ << std::endl; }

struct some_struct
{
  static void echo() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
  static void static_echo(const int& num_to_show) { std::cout << __PRETTY_FUNCTION__ << " : number to show: " << num_to_show << std::endl; }
};

auto some_lambda = [](){ std::cout << __PRETTY_FUNCTION__ << std::endl; };


class obj
{
  public:
    obj( )
    {
      sig_obj.connect(obj_echo);
    }
};

class a_cs
{
  public: 
    a_cs(){};
    void s_e()
    {
      printf("s_echooo\n");
    }
};

int main() 
{
  // const int count{20};

  // for(size_t i{0}; i < count; ++i)
  // {
  //   task_mgr.queue([i](){ bar(i);});
  // }

  // task_mgr.start(count); //execute all threads

  // std::vector<int> numbers = {1,2,3,4,5};

  // auto to_erase = std::find(numbers.begin(), numbers.end(), 3);

  // numbers.erase(to_erase);

  // std::cout << "numbers's size: " << numbers.size() << std::endl;


  // const int num_to_arg{7};

  

  // sig.connect( some_lambda );
  // sig.connect( foo );
  // sig.connect( &some_struct::echo );

  // sigslot::signal<int> sig2;
  // sig2.connect( &some_struct::static_echo );

  // sig();
  // sig2(num_to_arg);

  // auto p_st = std::make_unique<some_struct>();


  // sigslot::signal<> sig_s;


  // sig_s.connect(foo);


  // if(p_st)
  //   sig_s();

  // p_st->static_echo(9);

  // obj a,b,c;

  // sig_obj();

  // { 
  //   a_cs an_o_a_cs;
   
  //   a_cs * p_a_cs = new a_cs;

  //   p_a_cs->s_e();
  // }
  

  std::promise<int> p;
  std::future<int> f = p.get_future();

  p.set_value(7);

  std::thread t([&p]{
    try{
      throw std::runtime_error("There is no value in p!");
    } catch(...)
    {
      try{
        p.set_exception(std::current_exception());
      } catch(...){}
    }
  });

  try{
    std::cout << f.get() << std::endl;
  } catch(const std::exception& e)
  {
    std::cout << "exception from the thread: " << e.what() << std::endl;
  }

  t.join();
 
 
 
  std::experimental::optional<std::string> t_optional{std::experimental::nullopt};

  if(!t_optional)
    std::cout << "the value of optional is:" << *t_optional << std::endl;

  t_optional = "something optional";

  if(t_optional)
    std::cout << "the value of optional is:" << *t_optional << std::endl;

  return 0;
}
