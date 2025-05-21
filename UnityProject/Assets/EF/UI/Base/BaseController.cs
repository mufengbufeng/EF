namespace EF
{
    public abstract class BaseController<T> : BehaviourSingleton<T>, IUIController where T : BaseController<T>
    {

    }
}