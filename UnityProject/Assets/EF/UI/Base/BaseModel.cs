using System.Collections.Generic;
using System;

namespace EF
{
    public abstract class BaseModel<T> : BehaviourSingleton<T>, IUIModel where T : BaseModel<T>
    {

    }
}