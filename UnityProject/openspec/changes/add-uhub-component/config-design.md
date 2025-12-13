# UHub 配置系统设计

## ScriptableObject 配置文件

### UHubBindingConfig.cs
```csharp
using System;
using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// UHub 组件绑定配置文件
/// 通过后缀名定义组件类型的智能推断规则
/// </summary>
[CreateAssetMenu(fileName = "UHubBindingConfig", menuName = "EF/UI/UHub Binding Config", order = 0)]
public class UHubBindingConfig : ScriptableObject
{
    [Header("绑定规则配置")]
    [SerializeField] 
    private List<BindingRule> _bindingRules = new List<BindingRule>
    {
        // 默认规则
        new BindingRule { Suffixes = new[] { "Btn", "Button" }, ComponentTypeName = "UnityEngine.UI.Button" },
        new BindingRule { Suffixes = new[] { "Text", "Label" }, ComponentTypeName = "UnityEngine.UI.Text" },
        new BindingRule { Suffixes = new[] { "Img", "Image" }, ComponentTypeName = "UnityEngine.UI.Image" },
        new BindingRule { Suffixes = new[] { "Slider" }, ComponentTypeName = "UnityEngine.UI.Slider" },
        new BindingRule { Suffixes = new[] { "Toggle" }, ComponentTypeName = "UnityEngine.UI.Toggle" },
        new BindingRule { Suffixes = new[] { "Input", "InputField" }, ComponentTypeName = "UnityEngine.UI.InputField" },
        new BindingRule { Suffixes = new[] { "Dropdown" }, ComponentTypeName = "UnityEngine.UI.Dropdown" },
        new BindingRule { Suffixes = new[] { "Go", "Obj", "GameObject" }, ComponentTypeName = "UnityEngine.GameObject" }
    };

    [Header("全局配置")]
    [SerializeField] 
    private BindingFailureMode _failureMode = BindingFailureMode.Warning;
    
    [SerializeField] 
    private bool _enableTypeInference = true;
    
    [SerializeField] 
    private bool _caseSensitive = false;

    [Header("高级选项")]
    [SerializeField] 
    private bool _allowRuntimeOverride = true;

    /// <summary>
    /// 绑定规则列表
    /// </summary>
    public IReadOnlyList<BindingRule> BindingRules => _bindingRules;

    /// <summary>
    /// 绑定失败处理模式
    /// </summary>
    public BindingFailureMode FailureMode => _failureMode;

    /// <summary>
    /// 是否启用类型推断
    /// </summary>
    public bool EnableTypeInference => _enableTypeInference;

    /// <summary>
    /// 是否区分大小写
    /// </summary>
    public bool CaseSensitive => _caseSensitive;

    /// <summary>
    /// 是否允许运行时覆盖规则
    /// </summary>
    public bool AllowRuntimeOverride => _allowRuntimeOverride;

    /// <summary>
    /// 根据字段名后缀查找匹配的组件类型
    /// </summary>
    /// <param name="fieldName">字段名称</param>
    /// <returns>匹配的组件类型，如果未找到返回 null</returns>
    public Type GetComponentType(string fieldName)
    {
        if (!_enableTypeInference || string.IsNullOrEmpty(fieldName))
            return null;

        foreach (var rule in _bindingRules)
        {
            if (rule.IsMatch(fieldName, _caseSensitive))
            {
                return rule.GetComponentType();
            }
        }

        return null;
    }
}

/// <summary>
/// 绑定规则定义
/// </summary>
[Serializable]
public class BindingRule
{
    [Header("匹配规则")]
    [SerializeField] 
    private string[] _suffixes = new string[0];

    [SerializeField] 
    private string _componentTypeName;

    [Header("选项")]
    [SerializeField] 
    private bool _ignoreCase = true;

    [SerializeField] 
    private bool _requireExactMatch = false;

    /// <summary>
    /// 支持的后缀列表
    /// </summary>
    public string[] Suffixes
    {
        get => _suffixes;
        set => _suffixes = value;
    }

    /// <summary>
    /// 组件类型名称 (完整命名空间)
    /// </summary>
    public string ComponentTypeName
    {
        get => _componentTypeName;
        set => _componentTypeName = value;
    }

    /// <summary>
    /// 是否忽略大小写
    /// </summary>
    public bool IgnoreCase
    {
        get => _ignoreCase;
        set => _ignoreCase = value;
    }

    /// <summary>
    /// 是否需要精确匹配
    /// </summary>
    public bool RequireExactMatch
    {
        get => _requireExactMatch;
        set => _requireExactMatch = value;
    }

    /// <summary>
    /// 检查字段名是否匹配此规则
    /// </summary>
    /// <param name="fieldName">字段名称</param>
    /// <param name="globalCaseSensitive">全局大小写敏感设置</param>
    /// <returns>是否匹配</returns>
    public bool IsMatch(string fieldName, bool globalCaseSensitive)
    {
        if (string.IsNullOrEmpty(fieldName) || _suffixes == null)
            return false;

        bool caseSensitive = globalCaseSensitive && !_ignoreCase;
        var comparison = caseSensitive ? StringComparison.Ordinal : StringComparison.OrdinalIgnoreCase;

        // 移除下划线前缀 (如果存在)
        string cleanName = fieldName.StartsWith("_") ? fieldName.Substring(1) : fieldName;

        foreach (string suffix in _suffixes)
        {
            if (string.IsNullOrEmpty(suffix)) continue;

            if (_requireExactMatch)
            {
                if (string.Equals(cleanName, suffix, comparison))
                    return true;
            }
            else
            {
                if (cleanName.EndsWith(suffix, comparison))
                    return true;
            }
        }

        return false;
    }

    /// <summary>
    /// 获取组件类型
    /// </summary>
    /// <returns>组件类型，如果解析失败返回 null</returns>
    public Type GetComponentType()
    {
        if (string.IsNullOrEmpty(_componentTypeName))
            return null;

        try
        {
            return Type.GetType(_componentTypeName);
        }
        catch
        {
            Debug.LogError($"[UHubBindingConfig] 无法解析组件类型: {_componentTypeName}");
            return null;
        }
    }
}

/// <summary>
/// 绑定失败处理模式
/// </summary>
public enum BindingFailureMode
{
    /// <summary>
    /// 静默忽略
    /// </summary>
    Silent,

    /// <summary>
    /// 输出警告日志
    /// </summary>
    Warning,

    /// <summary>
    /// 抛出异常
    /// </summary>
    Exception
}
```

## 配置文件使用示例

### 创建配置文件
1. 在 Project 窗口右键
2. 选择 Create > EF > UI > UHub Binding Config
3. 命名为 `DefaultUHubConfig`
4. 配置绑定规则

### 字段命名示例
```csharp
public class ExampleView : UIView
{
    // 智能类型推断示例
    private _startBtn;        // → Button (匹配 "Btn" 后缀)
    private _playerImg;       // → Image (匹配 "Img" 后缀)
    private _nameText;        // → Text (匹配 "Text" 后缀)
    private _volumeSlider;    // → Slider (匹配 "Slider" 后缀)
    private _enableToggle;    // → Toggle (匹配 "Toggle" 后缀)
    private _chatInput;       // → InputField (匹配 "Input" 后缀)
    
    // 自定义配置示例
    [UHubBind("SpecialButton", typeof(Button))]
    private _customBtn;
    
    // 排除自动绑定
    [UHubIgnore]
    private Button _manualBtn;
}
```

### 配置文件位置建议
```
Assets/
  Settings/
    UHub/
      DefaultBindingConfig.asset     // 项目默认配置
      UISpecificConfig.asset         // 特定 UI 模块配置
```

这个配置系统让开发者可以：
- 通过 Inspector 界面直观地配置绑定规则
- 支持多种后缀映射到同一组件类型
- 灵活控制大小写敏感性和匹配模式
- 在不同项目或模块中使用不同的配置文件