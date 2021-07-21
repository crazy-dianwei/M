

* std::move
  * template<typename _Tp>
  * constexpr typename std::remove_reference<_Tp>::type&& move(_Tp&& __t) noexcept{
  * return static_cast<typename std::remove_reference<_Tp>::type&&>(__t);}


* std::forward
  * 完美转发，std::forward<T> u，做类型转换
  * T为左值引用时，u将被转换为T类型的左值
  * 否则u将被转换为T类型右值


* 生命周期
  * 一个变量的生命周期在超出作用域时结束。
  * 一个临时对象会在包含这个临时对象的完整表达式估值完成后，按生成顺序的逆序被销毁，除非有生命周期延长发生





