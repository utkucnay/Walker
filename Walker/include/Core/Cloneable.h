namespace wkr
{
  template<typename T>
  class ICloneable
  {
    mem::Ref<T> CloneRef()
    {
      auto ret = mem::Ref<T>::Create();
      Clone(ret.Get());
      return ret;
    }

    mem::Scope<T> CloneScope()
    {
      auto ret = mem::Scope<T>::Create();
      Clone(ret.Get());
      return ret;
    }

    T* CloneRaw()
    {
      auto ret = new T();
      Clone(ret.Get());
      return ret;
    }

  protected:
    virtual void Clone(T&) = 0;
  };
}
