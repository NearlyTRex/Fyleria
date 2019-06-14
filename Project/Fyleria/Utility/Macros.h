// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_UTILITY_MACROS_H_
#define _GECKO_UTILITY_MACROS_H_

//=====================================================================================

#define CALL_MEMBER_FN_PTR(object, ptrToMember)     ((object).*(ptrToMember))
#define CALL_SELF_MEMBER_FN_PTR(ptrToMember)        ((*this).*(ptrToMember))

//=====================================================================================

#define MAKE_CURRENT_CONFIG_SHORTCUT_STRING(name)                                   \
String Get##name() const                                                            \
{                                                                                   \
    String sBasePath = GetUserConfigFolder();                                       \
    String sFuncPath = GetCurrentConfig().Get##name();                              \
    return GetCanonicalPath(JoinPaths(sBasePath, sFuncPath));                       \
}

#define MAKE_CURRENT_DATA_SHORTCUT_STRING(name)                                     \
String Get##name() const                                                            \
{                                                                                   \
    String sBasePath = GetUserDataFolder();                                         \
    String sFuncPath = GetCurrentConfig().Get##name();                              \
    return GetCanonicalPath(JoinPaths(sBasePath, sFuncPath));                       \
}

//=====================================================================================

#define SET_JSON_DATA(name)                                                         \
{                                                                                   \
    to_json(jsonData[#name], obj.Get##name());                                      \
}

#define SET_OBJ_DATA(name, value_type, value_default)                               \
{                                                                                   \
    if(jsonData.find(#name) != jsonData.end())                                      \
    {                                                                               \
        obj.Set##name(jsonData[#name].get<value_type>());                           \
    }                                                                               \
    else                                                                            \
    {                                                                               \
        obj.Set##name(value_default);                                               \
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
    obj = jsonData;                                                                 \
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
        type::value_type obj;                                                       \
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
        type::mapped_type obj;                                                      \
        from_json(it.value(), obj);                                                 \
        tObj[it.key()] = obj;                                                       \
    }                                                                               \
}

#define MAKE_JSON_GENERIC_TYPE_CONVERTERS_DECL(name, type)                          \
String Convert##name##ToJsonString(const type& obj);                                \
String Convert##name##ArrayToJsonString(const STDVector<type>& vObjs);              \
type Get##name##FromJsonString(const String& jsonString);                           \
STDVector<type> Get##name##ArrayFromJsonString(const String& jsonString);

#define MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(name, type)                          \
String Convert##name##ToJsonString(const type& obj)                                 \
{                                                                                   \
    Json jsonData = obj;                                                            \
    return jsonData.dump();                                                         \
}                                                                                   \
String Convert##name##ArrayToJsonString(const STDVector<type>& vObjs)               \
{                                                                                   \
    Json jsonData = vObjs;                                                          \
    return jsonData.dump();                                                         \
}                                                                                   \
type Get##name##FromJsonString(const String& jsonString)                            \
{                                                                                   \
    Json jsonData = JsonParse(jsonString);                                          \
    return jsonData.get<type>();                                                    \
}                                                                                   \
STDVector<type> Get##name##ArrayFromJsonString(const String& jsonString)            \
{                                                                                   \
    Json jsonData = JsonParse(jsonString);                                          \
    return jsonData.get<STDVector<type>>();                                         \
}

//=====================================================================================

#define MAKE_ENUM_GETSTRINGARRAY_DECL(type)                                         \
StringArray Get##type##Names();

#define MAKE_ENUM_GETSTRINGARRAY_IMPL(type)                                         \
StringArray Get##type##Names()                                                      \
{                                                                                   \
    StringArray vTypeNames;                                                         \
    for (const char* name : type::_names())                                         \
    {                                                                               \
        vTypeNames.push_back(name);                                                 \
    }                                                                               \
    return vTypeNames;                                                              \
}

#define MAKE_ENUM_CONVERTERS_DECL(type)                                             \
type StringTo##type(const String& sType);                                           \
type StringTo##type##OrNone(const String& sType);                                   \
Bool IsValid##type(const String& sType);

#define MAKE_ENUM_CONVERTERS_IMPL(type)                                             \
type StringTo##type(const String& sType)                                            \
{                                                                                   \
    ASSERT_ERROR(type::_is_valid(sType.c_str()),                                    \
        "Type '%s' was not a valid enum string for type", sType.c_str());           \
    return type::_from_string(sType.c_str());                                       \
}                                                                                   \
type StringTo##type##OrNone(const String& sType)                                    \
{                                                                                   \
    if(type::_is_valid(sType.c_str()))                                              \
    {                                                                               \
        return type::_from_string(sType.c_str());                                   \
    }                                                                               \
    return +type::None;                                                             \
}                                                                                   \
Bool IsValid##type(const String& sType)                                             \
{                                                                                   \
    return type::_is_valid(sType.c_str());                                          \
}

//=====================================================================================

#define MAKE_RAW_BASIC_TYPE_ACCESSORS(name, type)                                   \
type m_var##name = type();                                                          \
type Get##name() const { return m_var##name; }                                      \
void Set##name(type varValue) { m_var##name = varValue; }

#define MAKE_RAW_OBJECT_TYPE_ACCESSORS(name, type)                                  \
type m_var##name;                                                                   \
const type& Get##name() const { return m_var##name; }                               \
type& Get##name() { return m_var##name; }                                           \
void Set##name(const type& varValue) { m_var##name = varValue; }

#define MAKE_RAW_GET_ONLY_BASIC_TYPE_ACCESSORS(name, type)                          \
type m_var##name = type();                                                          \
type Get##name() const { return m_var##name; }

#define MAKE_RAW_GET_ONLY_OBJECT_TYPE_ACCESSORS(name, type)                         \
type m_var##name;                                                                   \
const type& Get##name() const { return m_var##name; }                               \
type& Get##name() { return m_var##name; }

//=====================================================================================

#define MAKE_JSON_BASIC_TYPE_ACCESSORS(name, type)                                  \
Bool IsValid##name() const { return m_Data.find(#name) != m_Data.end(); }           \
type Get##name() const                                                              \
{                                                                                   \
    if(m_Data.find(#name) != m_Data.end())                                          \
    {                                                                               \
        return m_Data[#name];                                                       \
    }                                                                               \
    return type();                                                                  \
}                                                                                   \
void Set##name(const type& varValue) { m_Data[#name] = varValue; }

//=====================================================================================

#define INITIALIZE_STAT_TYPE_NAMES(base, type)                                      \
{                                                                                   \
    for(auto& sType : base##_##type::_names())                                      \
    {                                                                               \
        if(sType == (+base##_##type::None)._to_string())                            \
        {                                                                           \
            continue;                                                               \
        }                                                                           \
        Get##type##StatNames()->insert(sType);                                      \
    }                                                                               \
}

#define MAKE_STAT_TYPE_ACCESSORS(name, type)                                        \
type Get##name() const                                                              \
{                                                                                   \
    type var##name = type();                                                        \
    GetStatValue<type>(GetStats(), String(#name), var##name);                       \
    return var##name;                                                               \
}                                                                                   \
void Set##name(const type& var##name)                                               \
{                                                                                   \
    SetStatValue<type>(GetStats(), String(#name), var##name);                       \
}

#define RESET_STAT_TYPE_VALUES(base, type)                                          \
{                                                                                   \
    for(auto& sType : base##_##type::_names())                                      \
    {                                                                               \
        if(sType == (+base##_##type::None)._to_string())                            \
        {                                                                           \
            continue;                                                               \
        }                                                                           \
        SetStatValue<type>(GetStats(), sType, type());                              \
    }                                                                               \
}

#define SET_JSON_VALUES_FROM_STAT_TYPE_VALUES(base, type)                           \
{                                                                                   \
    for(auto& sType : base##_##type::_names())                                      \
    {                                                                               \
        if(sType == (+base##_##type::None)._to_string())                            \
        {                                                                           \
            continue;                                                               \
        }                                                                           \
        type varStatValue = type();                                                 \
        String varStatName = sType;                                                 \
        if(GetStatValue<type>(obj.GetStats(), varStatName, varStatValue))           \
        {                                                                           \
            jsonData[sType] = varStatValue;                                         \
        }                                                                           \
    }                                                                               \
}

#define SET_STAT_TYPE_VALUES_FROM_JSON_VALUES(base, type)                           \
{                                                                                   \
    for(auto& sType : base##_##type::_names())                                      \
    {                                                                               \
        if(sType == (+base##_##type::None)._to_string())                            \
        {                                                                           \
            continue;                                                               \
        }                                                                           \
        type varStatValue = jsonData[sType];                                        \
        String varStatName = sType;                                                 \
        SetStatValue<type>(obj.GetStats(), varStatName, varStatValue);              \
    }                                                                               \
}

//=====================================================================================

#define MAKE_SEGMENTED_STAT_VALUE_ACCESSORS(type)                                                                   \
Bool Get##type##StatValue(const String& sSegment, const String& sStat, type& varValue) const                        \
{                                                                                                                   \
    const CharacterBasicData& basicData = GetBasicData();                                                           \
    const CharacterProgressData& progressData = GetProgressDataSegment(sSegment);                                   \
    const CharacterBattleData& battleData = GetBattleDataSegment(sSegment);                                         \
    return (basicData.Get##type##StatValue(sStat, varValue) ||                                                      \
            progressData.Get##type##StatValue(sStat, varValue) ||                                                   \
            battleData.Get##type##StatValue(sStat, varValue));                                                      \
}                                                                                                                   \
Bool Set##type##StatValue(const String& sSegment, const String& sStat, const type& varValue)                        \
{                                                                                                                   \
    CharacterBasicData& basicData = GetBasicData();                                                                 \
    CharacterProgressData& progressData = GetProgressDataSegment(sSegment);                                         \
    CharacterBattleData& battleData = GetBattleDataSegment(sSegment);                                               \
    return (basicData.Set##type##StatValue(sStat, varValue) ||                                                      \
            progressData.Set##type##StatValue(sStat, varValue) ||                                                   \
            battleData.Set##type##StatValue(sStat, varValue));                                                      \
}

//=====================================================================================

#define MAKE_MODULE_RESULT_VARIANT(method)                                                                      \
void method##_StoreResult(const String& sResultID)                                                              \
{                                                                                                               \
    ModuleResultManager::GetInstance()->StoreResult(sResultID, Json(method()).dump());                          \
}

#define MAKE_MODULE_RESULT_VARIANT_A1(method, at1, av1)                                                         \
void method##_StoreResult(const String& sResultID, at1 av1)                                                     \
{                                                                                                               \
    ModuleResultManager::GetInstance()->StoreResult(sResultID, Json(method(av1)).dump());                       \
}

#define MAKE_MODULE_RESULT_VARIANT_A2(method, at1, av1, at2, av2)                                               \
void method##_StoreResult(const String& sResultID, at1 av1, at2 av2)                                            \
{                                                                                                               \
    ModuleResultManager::GetInstance()->StoreResult(sResultID, Json(method(av1, av2)).dump());                  \
}

#define MAKE_MODULE_RESULT_VARIANT_A3(method, at1, av1, at2, av2, at3, av3)                                     \
void method##_StoreResult(const String& sResultID, at1 av1, at2 av2, at3 av3)                                   \
{                                                                                                               \
    ModuleResultManager::GetInstance()->StoreResult(sResultID, Json(method(av1, av2, av3)).dump());             \
}

#define MAKE_MODULE_RESULT_VARIANT_A4(method, at1, av1, at2, av2, at3, av3, at4, av4)                           \
void method##_StoreResult(const String& sResultID, at1 av1, at2 av2, at3 av3, at4 av4)                          \
{                                                                                                               \
    ModuleResultManager::GetInstance()->StoreResult(sResultID, Json(method(av1, av2, av3, av4)).dump());        \
}

//=====================================================================================

#define MAKE_HTML_OPTION_LIST_STRING(type)                                                          \
String sOptionList_##type;                                                                          \
{                                                                                                   \
    for(auto& sTypeName : Get##type##Names())                                                       \
    {                                                                                               \
        if(sTypeName == "None")                                                                     \
        {                                                                                           \
            continue;                                                                               \
        }                                                                                           \
        sOptionList_##type += "<option value=\"" + sTypeName + "\">" + sTypeName + "</option>";     \
    }                                                                                               \
}

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
