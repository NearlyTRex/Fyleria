// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_UTILITY_MACROS_H_
#define _GECKO_UTILITY_MACROS_H_

//=====================================================================================

#define CREATE_JAVASCRIPT_CLASS_CALLBACK(type, method)                              \
STDBindFunc(&type::method, this, STDPlaceholder1)

//=====================================================================================

#define SET_JSON_DATA(name)                                                         \
{                                                                                   \
    to_json(jsonData[#name], obj.Get##name());                                      \
}

#define SET_OBJ_DATA(name, value_type)                                              \
{                                                                                   \
    if(jsonData.find(#name) != jsonData.end())                                      \
    {                                                                               \
        obj.Set##name(jsonData[#name].get<value_type>());                           \
    }                                                                               \
    else                                                                            \
    {                                                                               \
        obj.Set##name({});                                                          \
    }                                                                               \
}

//=====================================================================================

#define MAKE_JSON_BASIC_TYPE_CONVERTERS_DECL(type)                                  \
void to_json(Json& jsonData, const type& obj);                                      \
void from_json(const Json& jsonData, type& obj);

#define MAKE_JSON_BASIC_TYPE_CONVERTERS_IMPL(type)                                  \
void to_json(Json& jsonData, const type& obj)                                       \
{                                                                                   \
    jsonData = obj;                                                                 \
}                                                                                   \
void from_json(const Json& jsonData, type& obj)                                     \
{                                                                                   \
    obj = jsonData.get<type>();                                                     \
}

#define MAKE_JSON_OBJ_TYPE_CONVERTERS_DECL(type)                                    \
void to_json(Json& jsonData, const type& obj);                                      \
void from_json(const Json& jsonData, type& obj);

#define MAKE_JSON_OBJ_TYPE_CONVERTERS_IMPL(type)                                    \
void to_json(Json& jsonData, const type& obj)                                       \
{                                                                                   \
    jsonData = obj.ToJson();                                                        \
}                                                                                   \
void from_json(const Json& jsonData, type& obj)                                     \
{                                                                                   \
    obj.FromJson(jsonData);                                                         \
}

#define MAKE_JSON_SEQUENCE_TYPE_CONVERTERS_DECL(type)                               \
void to_json(Json& jsonData, const type& obj);                                      \
void from_json(const Json& jsonData, type& obj);

#define MAKE_JSON_SEQUENCE_TYPE_CONVERTERS_IMPL(type)                               \
void to_json(Json& vJsonData, const type& vObj)                                     \
{                                                                                   \
    vJsonData = STDVector<Json>();                                                  \
    for(auto it = vObj.begin(); it != vObj.end(); it++)                             \
    {                                                                               \
        Json jsonData;                                                              \
        to_json(jsonData, *it);                                                     \
        vJsonData.push_back(jsonData);                                              \
    }                                                                               \
}                                                                                   \
void from_json(const Json& vJsonData, type& vObj)                                   \
{                                                                                   \
    for(auto it = vJsonData.begin(); it != vJsonData.end(); it++)                   \
    {                                                                               \
        type::value_type obj {};                                                    \
        from_json(*it, obj);                                                        \
        vObj.push_back(obj);                                                        \
    }                                                                               \
}

#define MAKE_JSON_MAP_TYPE_CONVERTERS_DECL(type)                                    \
void to_json(Json& jsonData, const type& obj);                                      \
void from_json(const Json& jsonData, type& obj);

#define MAKE_JSON_MAP_TYPE_CONVERTERS_IMPL(type)                                    \
void to_json(Json& tJsonData, const type& tObj)                                     \
{                                                                                   \
    tJsonData = STDMap<type::key_type, Json>();                                     \
    for(auto it = tObj.begin(); it != tObj.end(); it++)                             \
    {                                                                               \
        Json jsonData;                                                              \
        to_json(jsonData, it->second);                                              \
        tJsonData[it->first] = jsonData;                                            \
    }                                                                               \
}                                                                                   \
void from_json(const Json& tJsonData, type& tObj)                                   \
{                                                                                   \
    for(auto it = tJsonData.begin(); it != tJsonData.end(); it++)                   \
    {                                                                               \
        type::mapped_type obj {};                                                   \
        from_json(it.value(), obj);                                                 \
        tObj[it.key()] = obj;                                                       \
    }                                                                               \
}

//=====================================================================================

#define MAKE_TYPE_TYPEDEFS(type)                                                    \
typedef type* type##Ptr;                                                            \
typedef STDSharedPtr<type> type##SharedPtr;                                         \
typedef STDReferenceWrapper<type> type##Ref;                                        \
typedef STDVector<type> type##Array;                                                \
typedef STDVector<type##Ptr> type##PtrArray;                                        \
typedef STDVector<type##Ref> type##RefArray;                                        \
typedef STDVector<type##SharedPtr> type##SharedPtrArray

//=====================================================================================

#define MAKE_RAW_BASIC_TYPE_ACCESSORS(name, type)                                   \
type m_var##name {};                                                                \
type Get##name() const { return m_var##name; }                                      \
void Set##name(type varValue) { m_var##name = varValue; }

#define MAKE_RAW_OBJECT_TYPE_ACCESSORS(name, type)                                  \
type m_var##name {};                                                                \
const type& Get##name() const { return m_var##name; }                               \
type& Get##name() { return m_var##name; }                                           \
void Set##name(const type& varValue) { m_var##name = varValue; }

#define MAKE_RAW_GET_ONLY_BASIC_TYPE_ACCESSORS(name, type)                          \
type m_var##name {};                                                                \
type Get##name() const { return m_var##name; }

#define MAKE_RAW_GET_ONLY_OBJECT_TYPE_ACCESSORS(name, type)                         \
type m_var##name {};                                                                \
const type& Get##name() const { return m_var##name; }                               \
type& Get##name() { return m_var##name; }

//=====================================================================================

#define INITIALIZE_STAT_TYPE_NAMES(base, type)                                          \
{                                                                                       \
    for(auto& sType : base##_##type::_names())                                          \
    {                                                                                   \
        if(sType == (+base##_##type::None)._to_string())                                \
        {                                                                               \
            continue;                                                                   \
        }                                                                               \
        Get##type##StatNames()->insert(sType);                                          \
    }                                                                                   \
}

#define MAKE_STAT_TYPE_ACCESSORS(name, type)                                            \
type Get##name() const                                                                  \
{                                                                                       \
    type var##name {};                                                                  \
    GetStatMapValue<type>(Get##type##Stats(), String(#name), var##name);                \
    return var##name;                                                                   \
}                                                                                       \
void Set##name(const type& var##name)                                                   \
{                                                                                       \
    SetStatMapValue<type>(Get##type##Stats(), String(#name), var##name);                \
}

#define RESET_STAT_TYPE_VALUES(base, type)                                              \
{                                                                                       \
    for(auto& sType : base##_##type::_names())                                          \
    {                                                                                   \
        if(IsNoneTypeForEnum<base##_##type>(sType))                                     \
        {                                                                               \
            continue;                                                                   \
        }                                                                               \
        SetStatMapValue<type>(Get##type##Stats(), sType, type());                       \
    }                                                                                   \
}

#define SET_JSON_VALUES_FROM_STAT_TYPE_VALUES(base, type)                               \
{                                                                                       \
    for(auto& sStatTypeName : base##_##type::_names())                                  \
    {                                                                                   \
        if(IsNoneTypeForEnum<base##_##type>(sStatTypeName))                             \
        {                                                                               \
            continue;                                                                   \
        }                                                                               \
        type varStatValue {};                                                           \
        if(GetStatMapValue<type>(obj.Get##type##Stats(), sStatTypeName, varStatValue))  \
        {                                                                               \
            to_json(jsonData[sStatTypeName], varStatValue);                             \
        }                                                                               \
    }                                                                                   \
}

#define SET_STAT_TYPE_VALUES_FROM_JSON_VALUES(base, type)                               \
{                                                                                       \
    for(auto& sStatTypeName : base##_##type::_names())                                  \
    {                                                                                   \
        if(IsNoneTypeForEnum<base##_##type>(sStatTypeName))                             \
        {                                                                               \
            continue;                                                                   \
        }                                                                               \
        type varStatValue {};                                                           \
        from_json(jsonData[sStatTypeName], varStatValue);                               \
        SetStatMapValue<type>(obj.Get##type##Stats(), sStatTypeName, varStatValue);     \
    }                                                                                   \
}

//=====================================================================================

#define MAKE_DEFAULT_HTML_OPTION_LIST_STRING(type)                                                  \
String sOptionList_##type;                                                                          \
{                                                                                                   \
    for(auto& sTypeName : GetEnumNames<type>())                                                     \
    {                                                                                               \
        if(IsNoneTypeForEnum<type>(sTypeName))                                                      \
        {                                                                                           \
            continue;                                                                               \
        }                                                                                           \
        sOptionList_##type += "<option value=\"" + sTypeName + "\">" + sTypeName + "</option>";     \
    }                                                                                               \
}

#define MAKE_SELECTED_HTML_OPTION_LIST_STRING(prefix, type, selection)                              \
String s##prefix##_##type;                                                                          \
{                                                                                                   \
    for(auto& sTypeName : GetEnumNames<type>())                                                     \
    {                                                                                               \
        if(IsNoneTypeForEnum<type>(sTypeName))                                                      \
        {                                                                                           \
            continue;                                                                               \
        }                                                                                           \
        if(sTypeName == selection)                                                                  \
        {                                                                                           \
            s##prefix##_##type += "<option value=\"" + sTypeName + "\" selected=\"selected\">";     \
            s##prefix##_##type += sTypeName + "</option>";                                          \
        }                                                                                           \
        else                                                                                        \
        {                                                                                           \
            s##prefix##_##type += "<option value=\"" + sTypeName + "\">" + sTypeName + "</option>"; \
        }                                                                                           \
    }                                                                                               \
}

//=====================================================================================

#define MAKE_MODULE_RESULT_VARIANT(method)                                                                      \
void method##_StoreResult(const String& sResultID)                                                              \
{                                                                                                               \
    ResultManager::GetInstance()->StoreResult(sResultID, Json(method()).dump());                                \
}

#define MAKE_MODULE_RESULT_VARIANT_A1(method, at1)                                                              \
void method##_StoreResult(const String& sResultID, at1 av1)                                                     \
{                                                                                                               \
    ResultManager::GetInstance()->StoreResult(sResultID, Json(method(av1)).dump());                             \
}

#define MAKE_MODULE_RESULT_VARIANT_A2(method, at1, at2)                                                         \
void method##_StoreResult(const String& sResultID, at1 av1, at2 av2)                                            \
{                                                                                                               \
    ResultManager::GetInstance()->StoreResult(sResultID, Json(method(av1, av2)).dump());                        \
}

#define MAKE_MODULE_RESULT_VARIANT_A3(method, at1, at2, at3)                                                    \
void method##_StoreResult(const String& sResultID, at1 av1, at2 av2, at3 av3)                                   \
{                                                                                                               \
    ResultManager::GetInstance()->StoreResult(sResultID, Json(method(av1, av2, av3)).dump());                   \
}

#define MAKE_MODULE_RESULT_VARIANT_A4(method, at1, at2, at3, at4)                                               \
void method##_StoreResult(const String& sResultID, at1 av1, at2 av2, at3 av3, at4 av4)                          \
{                                                                                                               \
    ResultManager::GetInstance()->StoreResult(sResultID, Json(method(av1, av2, av3, av4)).dump());              \
}

//=====================================================================================

#define MAKE_MANAGER_RETURN_LAMBDA(manager, method, return_type)                                                        \
[]() -> return_type { return manager::GetInstance()->method(); }

#define MAKE_MANAGER_RETURN_LAMBDA_A1(manager, method, return_type, at1)                                                \
[](at1 av1) -> return_type { return manager::GetInstance()->method(av1); }

#define MAKE_MANAGER_RETURN_LAMBDA_A2(manager, method, return_type, at1, at2)                                           \
[](at1 av1, at2 av2) -> return_type { return manager::GetInstance()->method(av1, av2); }

#define MAKE_MANAGER_RETURN_LAMBDA_A3(manager, method, return_type, at1, at2, at3)                                      \
[](at1 av1, at2 av2, at3 av3) -> return_type { return manager::GetInstance()->method(av1, av2, av3); }

#define MAKE_MANAGER_RETURN_LAMBDA_A4(manager, method, return_type, at1, at2, at3, at4)                                 \
[](at1 av1, at2 av2, at3 av3, at4 av4) -> return_type { return manager::GetInstance()->method(av1, av2, av3, av4); }

#define MAKE_MANAGER_VOID_LAMBDA(manager, method)                                                                       \
[]() { manager::GetInstance()->method(); }

#define MAKE_MANAGER_VOID_LAMBDA_A1(manager, method, at1)                                                               \
[](at1 av1) { manager::GetInstance()->method(av1); }

#define MAKE_MANAGER_VOID_LAMBDA_A2(manager, method, at1, at2)                                                          \
[](at1 av1, at2 av2) { manager::GetInstance()->method(av1, av2); }

#define MAKE_MANAGER_VOID_LAMBDA_A3(manager, method, at1, at2, at3)                                                     \
[](at1 av1, at2 av2, at3 av3) { manager::GetInstance()->method(av1, av2, av3); }

#define MAKE_MANAGER_VOID_LAMBDA_A4(manager, method, at1, at2, at3, at4)                                                \
[](at1 av1, at2 av2, at3 av3, at4 av4) { manager::GetInstance()->method(av1, av2, av3, av4); }

//=====================================================================================

#define WRAPPING_ADD_CONSTRUCTOR_SIMPLE()                                                                   \
.def(PyBindInit<>())

#define WRAPPING_ADD_CONSTRUCTOR_ARGS(...)                                                                  \
.def(PyBindInit<__VA_ARGS__>())

#define WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(name, base)                                             \
.def_property_readonly(#name, &base::Get##name)

#define WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(name, base)                                           \
.def_property_readonly(#name, PyBindOverloadCast<>(&base::Get##name, PyBindConst))

#define WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(name, base)                                                      \
.def_property(#name, &base::Get##name, &base::Set##name)

#define WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(name, base)                                                    \
.def_property(#name, PyBindOverloadCast<>(&base::Get##name, PyBindConst), &base::Set##name)

#define WRAPPING_STANDALONE_LAMBDA(name, lambda)                                                            \
m.def(#name, lambda)

#define WRAPPING_STANDALONE_LAMBDA_POLICY(name, lambda, policy)                                             \
m.def(#name, lambda, policy)

#define WRAPPING_STANDALONE_LAMBDA_ARGS(name, lambda, ...)                                                  \
m.def(#name, lambda, __VA_ARGS__)

#define WRAPPING_STANDALONE_METHOD_SIMPLE(name, base)                                                       \
m.def(#name, &base::name)

#define WRAPPING_STANDALONE_METHOD_FUNC(name, func, base)                                                   \
m.def(#name, &base::func)

#define WRAPPING_STANDALONE_METHOD_POLICY(name, base, policy)                                               \
m.def(#name, &base::name, policy)

#define WRAPPING_ADD_METHOD_SIMPLE(name, base)                                                              \
.def(#name, &base::name)

#define WRAPPING_ADD_METHOD_STATIC_SIMPLE(name, base)                                                       \
.def_static(#name, &base::name)

#define WRAPPING_ADD_METHOD_FUNC(name, func, base)                                                          \
.def(#name, &base::func)

#define WRAPPING_ADD_METHOD_STATIC_FUNC(name, func, base)                                                   \
.def_static(#name, &base::func)

#define WRAPPING_ADD_METHOD_ARGS(name, base, ...)                                                           \
.def(#name, &base::name, __VA_ARGS__)

#define WRAPPING_ADD_METHOD_STATIC_ARGS(name, base, ...)                                                    \
.def_static(#name, &base::name, __VA_ARGS__)

#define WRAPPING_ADD_METHOD_POLICY(name, base, policy)                                                      \
.def(#name, &base::name, policy)

#define WRAPPING_ADD_METHOD_STATIC_POLICY(name, base, policy)                                               \
.def_static(#name, &base::name, policy)

#define WRAPPING_ADD_METHOD_OVERLOADED(name, base, ...)                                                     \
.def(#name, PyBindOverloadCast<__VA_ARGS__>(&base::name))

#define WRAPPING_ADD_METHOD_OVERLOADED_CONST(name, base, ...)                                               \
.def(#name, PyBindOverloadCast<__VA_ARGS__>(&base::name, PyBindConst))

#define WRAPPING_ADD_METHOD_OVERLOADED_POLICY(name, base, policy, ...)                                      \
.def(#name, PyBindOverloadCast<__VA_ARGS__>(&base::name), policy)

#define WRAPPING_ADD_METHOD_OVERLOADED_POLICY_CONST(name, base, policy, ...)                                \
.def(#name, PyBindOverloadCast<__VA_ARGS__>(&base::name, PyBindConst), policy)

//=====================================================================================

#endif
