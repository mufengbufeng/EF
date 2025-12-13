#include "pch-cpp.hpp"





template <typename R, typename T1>
struct VirtualFuncInvoker1
{
	typedef R (*Func)(void*, T1, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};
struct InterfaceActionInvoker0
{
	typedef void (*Action)(void*, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename T1>
struct InterfaceActionInvoker1
{
	typedef void (*Action)(void*, T1, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};
template <typename T1, typename T2, typename T3>
struct InterfaceActionInvoker3
{
	typedef void (*Action)(void*, T1, T2, T3, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1, T2 p2, T3 p3)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj, p1, p2, p3, invokeData.method);
	}
};
template <typename R>
struct InterfaceFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename R, typename T1>
struct InterfaceFuncInvoker1
{
	typedef R (*Func)(void*, T1, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		return ((Func)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};
template <typename R, typename T1, typename T2>
struct InterfaceFuncInvoker2
{
	typedef R (*Func)(void*, T1, T2, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1, T2 p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		return ((Func)invokeData.methodPtr)(obj, p1, p2, invokeData.method);
	}
};
template <typename R, typename T1, typename T2>
struct GenericInterfaceFuncInvoker2
{
	typedef R (*Func)(void*, T1, T2, const RuntimeMethod*);

	static inline R Invoke (const RuntimeMethod* method, RuntimeObject* obj, T1 p1, T2 p2)
	{
		VirtualInvokeData invokeData;
		il2cpp_codegen_get_generic_interface_invoke_data(method, obj, &invokeData);
		return ((Func)invokeData.methodPtr)(obj, p1, p2, invokeData.method);
	}
};

struct Action_1_t8A357F9957A727C9D85A7C8D5B8FF423F7CD1B0D;
struct Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87;
struct Dictionary_2_tF57EC78AC6AF9267D58F2FD610EBACFB6A3BA485;
struct HashSet_1_t7A2C3D2AC6518F84ABF6D7D49F868A27763F533E;
struct IEnumerable_1_tF95C9E01A913DD50575531C8305932628663D9E9;
struct IEnumerable_1_t349E66EC5F09B881A8E52EE40A1AB9EC60E08E44;
struct IReadOnlyList_1_t7BB300FE9C8B0D3BCB34B752D2516BD12EB5E8CF;
struct List_1_t1BED237EBA2788604B1D39FC183B07E28F912A89;
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D;
struct List_1_t41E7BB3277E5E9E515E8B608D8B9F8ADF19B530D;
struct List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD;
struct FunctionPointer_1U5BU5D_t4FF44B7A00660580355F4138CA52C6EE9A1A1834;
struct AssemblyU5BU5D_t97B7B4E3FD4DA4944A4BFAA4DC484EA7D990B339;
struct AttributeU5BU5D_t0F73488E6F1249C889608E8DCC0BCC28A874E8F1;
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct Int64U5BU5D_tAEDFCBDB5414E2A140A6F34C0538BF97FCF67A1D;
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
struct TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB;
struct WorldSystemFilterFlagsU5BU5D_t434BBC7E739D7E01D618B9C6A685B473CB24F9CC;
struct SectionU5BU5D_t9D3017555FFF42E71BE91904A2486EAF429F24C4;
struct AOTGenericReferences_t7B8F9CD83F1EE53810C6F841826105D9416EA7C1;
struct Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07;
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263;
struct Assembly_t;
struct AssetHandle_tA226E2C9CFE7231AF71DFADFCBF947D4D1CC2AF3;
struct AssetInfo_t6646B3A8F405CC4B9221FB0F9F3E3DCDB98F1456;
struct AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C;
struct Attribute_tFDA8EFEFB0711976D22474794576DAF28F7440AA;
struct Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235;
struct CancellationTokenSource_tAAE1E0033BCFC233801F8CB4CED5C852B350CB7B;
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
struct Exception_t;
struct GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE;
struct HandleBase_t571827F810EAE331C05542D54B2C396C605DB4DA;
struct HotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016;
struct IAsyncResult_t7B9B5A0ECB35DCEC31B8A8122C37D687369253B5;
struct IAsyncStateMachine_t0680C7F905C553076B552D5A1A6E39E2F0F36AA2;
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
struct IResourceManager_t2D98FEEEA5A917E1A722327BB77EB19BCF1432DC;
struct IStateMachineRunnerPromise_t5CE1FDF2F619E55F7DCFBE22E2B97835C6781C7B;
struct IUniTaskSource_t5AF6C202B2616C72E989C90B6E76DFEC4118174D;
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C;
struct InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB;
struct MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553;
struct MethodBase_t;
struct MethodInfo_t;
struct MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71;
struct NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A;
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C;
struct ProviderOperation_t71913303D5FF65BABC7FFB845400A71EF8BA0A53;
struct Readme_tE17B99201D0F52BD5727638AD3F41072A65B3BBB;
struct ResourceManager_t66C02AB518045FFA776FDAB1AB6FF811155F51E6;
struct ResourceModeConfig_tA1EF1939CF0C50D62898DF0070094DD2D7928FA3;
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
struct ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A;
struct String_t;
struct TextAsset_t2C64E93DA366D9DE5A8209E1802FA4884AC1BD69;
struct Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4;
struct Type_t;
struct TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7;
struct UnitySourceGeneratedAssemblyMonoScriptTypes_v1_tC95F24D0C6E6B77389433852BB389F39C692926E;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
struct Section_t50C894D0A717C2368EBAAE5477D4E8626D0B5401;
struct TypeInfo_tD43B08A8D19156EEC98399693A96161F02139654;
struct BoxedGetHashCodeFn_t6FB594B3729237028A914FC35892E11F35EBD7A5;
struct GetBoxedEqualsFn_t1D3C86605A3BC070552B06B6F9C34588CB8BEA01;
struct GetBoxedEqualsPtrFn_t1902DF962742BD42AEC0802E437C41F357FC251C;
struct GetSystemAttributesFn_tFF3291428917181EF9DA36D06C3155DE423D30AA;
struct SetSharedTypeIndicesFn_t42DEBDCE57DA612BDBCC2CD1C7C6969F77858C0C;

IL2CPP_EXTERN_C RuntimeClass* AOTGenericReferences_t7B8F9CD83F1EE53810C6F841826105D9416EA7C1_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* AssemblyTypeRegistry_t38B36581EF406EB04A8CF7356B90E396D2EA34E5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* AwaiterActions_t5D05CAC006FDEBCF6B65E2B9224BC4B44783BBE5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* BoxedGetHashCodeFn_t6FB594B3729237028A914FC35892E11F35EBD7A5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Exception_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* GetBoxedEqualsFn_t1D3C86605A3BC070552B06B6F9C34588CB8BEA01_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* GetBoxedEqualsPtrFn_t1902DF962742BD42AEC0802E437C41F357FC251C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* GetSystemAttributesFn_tFF3291428917181EF9DA36D06C3155DE423D30AA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* HotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IResourceManager_t2D98FEEEA5A917E1A722327BB77EB19BCF1432DC_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IStateMachineRunnerPromise_t5CE1FDF2F619E55F7DCFBE22E2B97835C6781C7B_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IUniTaskSource_t5AF6C202B2616C72E989C90B6E76DFEC4118174D_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Int64U5BU5D_tAEDFCBDB5414E2A140A6F34C0538BF97FCF67A1D_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* List_1_t1BED237EBA2788604B1D39FC183B07E28F912A89_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* LoadImageErrorCode_tC778A2553ADB45B8C61EFE26C20837C23894FEB3_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ModuleSystem_tEB75335684504282F045968A3B212CE31057E32F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Readme_tE17B99201D0F52BD5727638AD3F41072A65B3BBB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ResourceManager_t66C02AB518045FFA776FDAB1AB6FF811155F51E6_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SetSharedTypeIndicesFn_t42DEBDCE57DA612BDBCC2CD1C7C6969F77858C0C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SharedTypeIndex_1_t2C32D65079DB63CC448E325FB9378851A676AE73_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SharedTypeIndex_1_t3F0C6DA9E27125602575D8B02FAEAE477DA08DFE_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SharedTypeIndex_1_t77C75304B99808772DAC7FE28A8C92DB2A4231BA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SharedTypeIndex_1_tF0C6371F19CE027D0F9CA9CE843704927F5E7581_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* TextAsset_t2C64E93DA366D9DE5A8209E1802FA4884AC1BD69_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeField* U3CPrivateImplementationDetailsU3E_t0F5473E849A5A5185A9F4C5246F0C32816C49FCA____22BF73DEE36321E969C3CB45397B37D9DAF8EF9643FEEC9781E187210B414FE9_FieldInfo_var;
IL2CPP_EXTERN_C RuntimeField* U3CPrivateImplementationDetailsU3E_t0F5473E849A5A5185A9F4C5246F0C32816C49FCA____FFCF93DEE207A03B9C747003659BB8BCAED1A2A78521B5C6B6B6BC5B63400A72_FieldInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral065A4520058461C386BC1A37D15716A5905D9F63;
IL2CPP_EXTERN_C String_t* _stringLiteral0B34DFC38793BF0AF6DEA9A94F7CCB4150E999A6;
IL2CPP_EXTERN_C String_t* _stringLiteral0E51F4817B1D8367D96FA6DABA71C29B7A6AF524;
IL2CPP_EXTERN_C String_t* _stringLiteral12B9EDD4E3C69EC048F22E3E86D8D681E8ED7990;
IL2CPP_EXTERN_C String_t* _stringLiteral1ECF4C0AFFCF469C57E42CE9A095A0874A861235;
IL2CPP_EXTERN_C String_t* _stringLiteral1F1133B46379B1B74780C17A916B994A3A4AAC57;
IL2CPP_EXTERN_C String_t* _stringLiteral26673D6CBCD1AA03BAC761AFC10C0A46A418CA32;
IL2CPP_EXTERN_C String_t* _stringLiteral2B07CB990D04DEF87288EEED87550482A1FE697C;
IL2CPP_EXTERN_C String_t* _stringLiteral30B46354175263168D67C65E9214DB098262BD73;
IL2CPP_EXTERN_C String_t* _stringLiteral3C74EE53B1AF65557F9BDF1EAF0C416BADC79DB9;
IL2CPP_EXTERN_C String_t* _stringLiteral3FFD62AED7E07D7CF72FD45AEB9373B7AC43D791;
IL2CPP_EXTERN_C String_t* _stringLiteral4D662484694B003BFD98792D0B13414D4CE7C1A2;
IL2CPP_EXTERN_C String_t* _stringLiteral4FE0A0ADA342BA701A04297D4C3D586C20AEFC03;
IL2CPP_EXTERN_C String_t* _stringLiteral55742341917859E61CC59E693B0B34D9F20DD7D4;
IL2CPP_EXTERN_C String_t* _stringLiteral5E153135A0B21174A583C1AB81197282B3C2D696;
IL2CPP_EXTERN_C String_t* _stringLiteral5F79BDEDF7F0A4A42173CCAF27F5C342A52DC260;
IL2CPP_EXTERN_C String_t* _stringLiteral60F856B7F965F851619A60BD211976AEF512315D;
IL2CPP_EXTERN_C String_t* _stringLiteral7EFD626CCF8D8CE5F1D228CC8AC91FCEAFBCDF7E;
IL2CPP_EXTERN_C String_t* _stringLiteral8097DA92B2FFC0CA2B1A7C337AFC83A6F765A072;
IL2CPP_EXTERN_C String_t* _stringLiteral8340619A905949B4B4F774604D29107ECCAA42E3;
IL2CPP_EXTERN_C String_t* _stringLiteral83DFE0CCE9E74A4499E55D2AEA4F20F44111613E;
IL2CPP_EXTERN_C String_t* _stringLiteral946BD80B231F5776B5307B385889C9ABB57D3D53;
IL2CPP_EXTERN_C String_t* _stringLiteral977A71115E05B54B449539D8B6701AE4DAD2B1BE;
IL2CPP_EXTERN_C String_t* _stringLiteralA3F029047BA90CC134023587DF7DCF444B38D009;
IL2CPP_EXTERN_C String_t* _stringLiteralB395EFD0354E31FE0F76908F4BE2E5A165319042;
IL2CPP_EXTERN_C String_t* _stringLiteralB7359FF4466AF47CB32CD42933A685AB7E322114;
IL2CPP_EXTERN_C String_t* _stringLiteralB98479915536FE59BC4FFE29FD1D03106286ED6D;
IL2CPP_EXTERN_C String_t* _stringLiteralBC755F9F3AD75230DD0DEEF00D323B0256FCDEC0;
IL2CPP_EXTERN_C String_t* _stringLiteralC7327B9D39E1F3D24630F049ED40C3A22EE84057;
IL2CPP_EXTERN_C String_t* _stringLiteralCBE317BE7D6A370B9E6FAB97110F085335AB682E;
IL2CPP_EXTERN_C String_t* _stringLiteralD49B73F5B4735001BCEBA5F02814D3AF0D14FDF2;
IL2CPP_EXTERN_C String_t* _stringLiteralD63C2F074FC917A4CDBC16CCF627AA2E687765AB;
IL2CPP_EXTERN_C String_t* _stringLiteralDF3B4424E614400CA8576744772CF0A4BE189BFB;
IL2CPP_EXTERN_C String_t* _stringLiteralE3C158842AF393BF0773EC375934F0013B168F86;
IL2CPP_EXTERN_C String_t* _stringLiteralEC4C5477D8BA260A27C36AFD7E8C1C289169E9CF;
IL2CPP_EXTERN_C String_t* _stringLiteralFD9218F87D9D2167DB92BA630674DC7A1DBAD834;
IL2CPP_EXTERN_C const RuntimeMethod* AssemblyTypeRegistry_BoxedGetHashCode_m51ABF56CB30C28866F9A1DD99686EE8FA066AA35_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* AssemblyTypeRegistry_Equals_m2A29416EF4DF96A3C8653EE9A5FD28D0F832888F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* AssemblyTypeRegistry_Equals_mC6FB3A844339CB7C644AD24D982A88DA1EFFE98D_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* AssemblyTypeRegistry_GetSystemAttributes_m745ECC27B9E20AA200CFB281D28E3A2F9C2E2C3C_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* AssemblyTypeRegistry_SetSharedStaticTypeIndices_m3DE4774BFFA0B87DE6BB2678A9C2737686BF6917_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* AsyncUniTaskMethodBuilder_AwaitUnsafeOnCompleted_TisAwaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956_TisU3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129_m65DA9E32C2BB838DA1CBBC1C0B8BE7B25E64C11C_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* AsyncUniTaskMethodBuilder_Start_TisU3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129_m5B101A1A0A29177A7195A0F7BA5BA027A4AC58E1_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_Dispose_m592BCCE7B7933454DED2130C810F059F8D85B1D7_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_Dispose_m93B736E6DBFFC747D775D68C8CA34947DAE8B1C2_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_MoveNext_m9360A25E040507C2A33C02E92ACE8AD5ABA3E0FB_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_MoveNext_mDB47EEC4531D33B9C33FD2E70BA15E1535A0F3ED_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_get_Current_m143541DD8FBCD313E7554EA738FA813B8F4DB11A_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_get_Current_mC25A7F22ACFD0C89749FD0D52C3A845228B2737F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* GameEntry_InvokeHotfixEntry_m4BB63989E22A673D5268F18D765639C89C593903_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* GameEntry_LoadDllBytes_m5D4614AFAEB0464FFA0DDCB52147F14BF8AF4D72_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* GameEntry_LoadHotfixConfig_m184C10567CEBD6A56FFCABFE11081EFFBDD37CF1_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* IResourceManager_LoadAssetSync_TisTextAsset_t2C64E93DA366D9DE5A8209E1802FA4884AC1BD69_mF011E03A43DB9CA43887C5E2A774AF08D82186FD_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_AddRange_m157DD7AD4D25423F82A21E533BC4686C83770D5E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_mC333738F45652C892517660DEE4B22270EF9D0A2_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_mF10DB1D3CBB0B14215F0E4F8AB4934A1955E5351_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Clear_m9C25692520A49715927D2C255A19820D042DD1C6_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_GetEnumerator_m7692B5F182858B7D5C72C920D09AD48738D1E70D_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_GetEnumerator_mAEAF74A8D17E88F088AB910E5A3FA8FA37488E7D_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1__ctor_m7F799D24C042923B6F560AF8FEA1CB00A1233888_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1__ctor_mCA8DD57EAC70C2B5923DBB9D5A77CEAC22E7068E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ModuleSystem_Get_TisIResourceManager_t2D98FEEEA5A917E1A722327BB77EB19BCF1432DC_mFDF242FFAD78D6645C1AA37A8EDF87AB00652CDB_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ModuleSystem_Register_TisIResourceManager_t2D98FEEEA5A917E1A722327BB77EB19BCF1432DC_m9E5D594363E1124D044614BFCB9D04DD4184BC4D_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Resources_Load_TisHotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016_m1D32AC03055E45095AEB79C68AEE61270BC63CCB_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SharedStatic_1_get_Data_m7B65B281F2D304BF7A408DDC24F8DA7DD99D9368_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeType* AOTGenericReferences_t7B8F9CD83F1EE53810C6F841826105D9416EA7C1_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* HotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* Readme_tE17B99201D0F52BD5727638AD3F41072A65B3BBB_0_0_0_var;
IL2CPP_EXTERN_C const char* AssemblyTypeRegistry_t38B36581EF406EB04A8CF7356B90E396D2EA34E5_StaticFields____Value0_RVAStorage;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;

struct AttributeU5BU5D_t0F73488E6F1249C889608E8DCC0BCC28A874E8F1;
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct Int64U5BU5D_tAEDFCBDB5414E2A140A6F34C0538BF97FCF67A1D;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
struct TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB;
struct WorldSystemFilterFlagsU5BU5D_t434BBC7E739D7E01D618B9C6A685B473CB24F9CC;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct U3CModuleU3E_tBB65183F1134474D09FF49B95625D25472B9BA8B 
{
};
struct List_1_t1BED237EBA2788604B1D39FC183B07E28F912A89  : public RuntimeObject
{
	AssemblyU5BU5D_t97B7B4E3FD4DA4944A4BFAA4DC484EA7D990B339* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D  : public RuntimeObject
{
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD  : public RuntimeObject
{
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct U3CPrivateImplementationDetailsU3E_t0F5473E849A5A5185A9F4C5246F0C32816C49FCA  : public RuntimeObject
{
};
struct AEFManager_t115A767C1C093E187E49A0439CB07E95A9E1A611  : public RuntimeObject
{
};
struct Assembly_t  : public RuntimeObject
{
};
struct Assembly_t_marshaled_pinvoke
{
};
struct Assembly_t_marshaled_com
{
};
struct AssemblyTypeRegistry_t38B36581EF406EB04A8CF7356B90E396D2EA34E5  : public RuntimeObject
{
};
struct Attribute_tFDA8EFEFB0711976D22474794576DAF28F7440AA  : public RuntimeObject
{
};
struct AwaiterActions_t5D05CAC006FDEBCF6B65E2B9224BC4B44783BBE5  : public RuntimeObject
{
};
struct HandleBase_t571827F810EAE331C05542D54B2C396C605DB4DA  : public RuntimeObject
{
	AssetInfo_t6646B3A8F405CC4B9221FB0F9F3E3DCDB98F1456* ____assetInfo;
	ProviderOperation_t71913303D5FF65BABC7FFB845400A71EF8BA0A53* ___U3CProviderU3Ek__BackingField;
};
struct MemberInfo_t  : public RuntimeObject
{
};
struct String_t  : public RuntimeObject
{
	int32_t ____stringLength;
	Il2CppChar ____firstChar;
};
struct TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7  : public RuntimeObject
{
	GetBoxedEqualsFn_t1D3C86605A3BC070552B06B6F9C34588CB8BEA01* ___BoxedEquals;
	GetBoxedEqualsPtrFn_t1902DF962742BD42AEC0802E437C41F357FC251C* ___BoxedEqualsPtr;
	BoxedGetHashCodeFn_t6FB594B3729237028A914FC35892E11F35EBD7A5* ___BoxedGetHashCode;
	SetSharedTypeIndicesFn_t42DEBDCE57DA612BDBCC2CD1C7C6969F77858C0C* ___SetSharedTypeIndices;
	GetSystemAttributesFn_tFF3291428917181EF9DA36D06C3155DE423D30AA* ___GetSystemAttributes;
	String_t* ___AssemblyName;
	TypeInfo_tD43B08A8D19156EEC98399693A96161F02139654* ___TypeInfosPtr;
	int32_t ___TypeInfosCount;
	int32_t* ___EntityOffsetsPtr;
	int32_t ___EntityOffsetsCount;
	int32_t* ___BlobAssetReferenceOffsetsPtr;
	int32_t ___BlobAssetReferenceOffsetsCount;
	int32_t* ___UnityObjectReferenceOffsetsPtr;
	int32_t ___UnityObjectReferenceOffsetsCount;
	int32_t* ___WeakAssetReferenceOffsetsPtr;
	int32_t ___WeakAssetReferenceOffsetsCount;
	TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* ___Types;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___TypeNames;
	TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* ___WriteGroups;
	TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* ___SystemTypes;
	WorldSystemFilterFlagsU5BU5D_t434BBC7E739D7E01D618B9C6A685B473CB24F9CC* ___SystemFilterFlags;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___SystemTypeNames;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___SystemTypeSizes;
	Int64U5BU5D_tAEDFCBDB5414E2A140A6F34C0538BF97FCF67A1D* ___SystemTypeHashes;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___SystemTypeFlags;
	FunctionPointer_1U5BU5D_t4FF44B7A00660580355F4138CA52C6EE9A1A1834* ___iRefCountedRetainFunctions;
	FunctionPointer_1U5BU5D_t4FF44B7A00660580355F4138CA52C6EE9A1A1834* ___iRefCountedReleaseFunctions;
	TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* ___FieldTypes;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___FieldNames;
};
struct UnitySourceGeneratedAssemblyMonoScriptTypes_v1_tC95F24D0C6E6B77389433852BB389F39C692926E  : public RuntimeObject
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};
struct Section_t50C894D0A717C2368EBAAE5477D4E8626D0B5401  : public RuntimeObject
{
	String_t* ___heading;
	String_t* ___text;
	String_t* ___linkText;
	String_t* ___url;
};
struct Enumerator_t2E011DE5D9C8DB2A137AE9CD1D7516D52F2A95AA 
{
	List_1_t1BED237EBA2788604B1D39FC183B07E28F912A89* ____list;
	int32_t ____index;
	int32_t ____version;
	Assembly_t* ____current;
};
struct Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A 
{
	List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* ____list;
	int32_t ____index;
	int32_t ____version;
	RuntimeObject* ____current;
};
struct Enumerator_tA7A4B718FE1ED1D87565680D8C8195EC8AEAB3D1 
{
	List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* ____list;
	int32_t ____index;
	int32_t ____version;
	String_t* ____current;
};
struct SharedStatic_1_t62C042BCA77D8653DB2FC705185F0809C8C59D84 
{
	void* ____buffer;
};
struct SharedTypeIndex_1_tF0C6371F19CE027D0F9CA9CE843704927F5E7581 
{
	union
	{
		struct
		{
		};
		uint8_t SharedTypeIndex_1_tD29B75C5C9D16D2B16B52AB9012D204D47CDD2D1__padding[1];
	};
};
struct SharedTypeIndex_1_t2C32D65079DB63CC448E325FB9378851A676AE73 
{
	union
	{
		struct
		{
		};
		uint8_t SharedTypeIndex_1_tD29B75C5C9D16D2B16B52AB9012D204D47CDD2D1__padding[1];
	};
};
struct SharedTypeIndex_1_t77C75304B99808772DAC7FE28A8C92DB2A4231BA 
{
	union
	{
		struct
		{
		};
		uint8_t SharedTypeIndex_1_tD29B75C5C9D16D2B16B52AB9012D204D47CDD2D1__padding[1];
	};
};
struct SharedTypeIndex_1_t3F0C6DA9E27125602575D8B02FAEAE477DA08DFE 
{
	union
	{
		struct
		{
		};
		uint8_t SharedTypeIndex_1_tD29B75C5C9D16D2B16B52AB9012D204D47CDD2D1__padding[1];
	};
};
struct AssetHandle_tA226E2C9CFE7231AF71DFADFCBF947D4D1CC2AF3  : public HandleBase_t571827F810EAE331C05542D54B2C396C605DB4DA
{
	Action_1_t8A357F9957A727C9D85A7C8D5B8FF423F7CD1B0D* ____callback;
};
struct AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0 
{
	RuntimeObject* ___runnerPromise;
	Exception_t* ___ex;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3 
{
	uint8_t ___m_value;
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2  : public ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_pinvoke
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_com
{
};
struct Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175 
{
	int16_t ___m_value;
};
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3 
{
	int64_t ___m_value;
};
struct IntPtr_t 
{
	void* ___m_value;
};
struct MethodBase_t  : public MemberInfo_t
{
};
struct ResourceManager_t66C02AB518045FFA776FDAB1AB6FF811155F51E6  : public AEFManager_t115A767C1C093E187E49A0439CB07E95A9E1A611
{
	Dictionary_2_tF57EC78AC6AF9267D58F2FD610EBACFB6A3BA485* ____packages;
	HashSet_1_t7A2C3D2AC6518F84ABF6D7D49F868A27763F533E* ____trackedHandles;
	ResourceModeConfig_tA1EF1939CF0C50D62898DF0070094DD2D7928FA3* ____config;
	String_t* ____defaultPackageName;
	bool ____isInitialized;
};
#pragma pack(push, tp, 1)
struct TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C 
{
	union
	{
		struct
		{
			union
			{
				#pragma pack(push, tp, 1)
				struct
				{
					int32_t ___Value;
				};
				#pragma pack(pop, tp)
				struct
				{
					int32_t ___Value_forAlignmentOnly;
				};
			};
		};
		uint8_t TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C__padding[4];
	};
};
#pragma pack(pop, tp)
struct UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B 
{
	uint32_t ___m_value;
};
struct UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270 
{
	RuntimeObject* ___source;
	int16_t ___token;
};
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915 
{
	union
	{
		struct
		{
		};
		uint8_t Void_t4861ACF8F4594C3437BB48B6E56783494B843915__padding[1];
	};
};
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D202_t41B6E33AD00E8A998F06BE18F77E2CEC9B6FA07F 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D202_t41B6E33AD00E8A998F06BE18F77E2CEC9B6FA07F__padding[202];
	};
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D99_t77FABFEEC23FFEB91ECA8869D642BC4D243BBDCA 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D99_t77FABFEEC23FFEB91ECA8869D642BC4D243BBDCA__padding[99];
	};
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct ConstantData0_t1F10138848E6A6434DF07663E3F6D55A4BAB7F40 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t ConstantData0_t1F10138848E6A6434DF07663E3F6D55A4BAB7F40__padding[416];
	};
};
#pragma pack(pop, tp)
struct MonoScriptData_t8F50E352855B96FFFC1D9CB07EACC90C99D73A3E 
{
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___FilePathsData;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___TypesData;
	int32_t ___TotalTypes;
	int32_t ___TotalFiles;
	bool ___IsEditorOnly;
};
struct MonoScriptData_t8F50E352855B96FFFC1D9CB07EACC90C99D73A3E_marshaled_pinvoke
{
	Il2CppSafeArray* ___FilePathsData;
	Il2CppSafeArray* ___TypesData;
	int32_t ___TotalTypes;
	int32_t ___TotalFiles;
	int32_t ___IsEditorOnly;
};
struct MonoScriptData_t8F50E352855B96FFFC1D9CB07EACC90C99D73A3E_marshaled_com
{
	Il2CppSafeArray* ___FilePathsData;
	Il2CppSafeArray* ___TypesData;
	int32_t ___TotalTypes;
	int32_t ___TotalFiles;
	int32_t ___IsEditorOnly;
};
struct BindingFlags_t5DC2835E4AE9C1862B3AD172EF35B6A5F4F1812C 
{
	int32_t ___value__;
};
struct Delegate_t  : public RuntimeObject
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	RuntimeObject* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	bool ___method_is_virtual;
};
struct Delegate_t_marshaled_pinvoke
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	Il2CppIUnknown* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	int32_t ___method_is_virtual;
};
struct Delegate_t_marshaled_com
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	Il2CppIUnknown* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	int32_t ___method_is_virtual;
};
struct Exception_t  : public RuntimeObject
{
	String_t* ____className;
	String_t* ____message;
	RuntimeObject* ____data;
	Exception_t* ____innerException;
	String_t* ____helpURL;
	RuntimeObject* ____stackTrace;
	String_t* ____stackTraceString;
	String_t* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	RuntimeObject* ____dynamicMethods;
	int32_t ____HResult;
	String_t* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_pinvoke
{
	char* ____className;
	char* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_pinvoke* ____innerException;
	char* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	char* ____stackTraceString;
	char* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	char* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_com
{
	Il2CppChar* ____className;
	Il2CppChar* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_com* ____innerException;
	Il2CppChar* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	Il2CppChar* ____stackTraceString;
	Il2CppChar* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	Il2CppChar* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct HomologousImageMode_tEC0F0043F595B001580D833592AE9E7FD4744548 
{
	int32_t ___value__;
};
struct LoadImageErrorCode_tC778A2553ADB45B8C61EFE26C20837C23894FEB3 
{
	int32_t ___value__;
};
struct MethodInfo_t  : public MethodBase_t
{
};
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C  : public RuntimeObject
{
	intptr_t ___m_CachedPtr;
};
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_pinvoke
{
	intptr_t ___m_CachedPtr;
};
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_com
{
	intptr_t ___m_CachedPtr;
};
struct ResourceMode_tE33B5A97253B83542AB74AC680A1CEA26C4D5A67 
{
	int32_t ___value__;
};
struct RuntimeFieldHandle_t6E4C45B6D2EA12FC99185805A7E77527899B25C5 
{
	intptr_t ___value;
};
struct RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B 
{
	intptr_t ___value;
};
struct UniTaskStatus_tC898C29839EBB5DB7055C3DF299A2C276237CB70 
{
	int32_t ___value__;
};
struct WorldSystemFilterFlags_t804CEC1CA2CCD49130BBE419AE8C1060B163A867 
{
	uint32_t ___value__;
};
struct TypeCategory_t94731637F2239CC5D222E482298E0D9A80AA2CD2 
{
	int32_t ___value__;
};
struct Awaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956 
{
	UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270 ___task;
};
struct Awaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956_marshaled_pinvoke
{
	UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270 ___task;
};
struct Awaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956_marshaled_com
{
	UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270 ___task;
};
struct Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};
struct MulticastDelegate_t  : public Delegate_t
{
	DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* ___delegates;
};
struct MulticastDelegate_t_marshaled_pinvoke : public Delegate_t_marshaled_pinvoke
{
	Delegate_t_marshaled_pinvoke** ___delegates;
};
struct MulticastDelegate_t_marshaled_com : public Delegate_t_marshaled_com
{
	Delegate_t_marshaled_com** ___delegates;
};
struct ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};
struct ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A_marshaled_pinvoke : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_pinvoke
{
};
struct ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A_marshaled_com : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_com
{
};
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};
struct TextAsset_t2C64E93DA366D9DE5A8209E1802FA4884AC1BD69  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};
struct Type_t  : public MemberInfo_t
{
	RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ____impl;
};
struct U3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129 
{
	int32_t ___U3CU3E1__state;
	AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0 ___U3CU3Et__builder;
	GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE* ___U3CU3E4__this;
	Awaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956 ___U3CU3Eu__1;
};
struct TypeInfo_tD43B08A8D19156EEC98399693A96161F02139654 
{
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___TypeIndex;
	int32_t ___SizeInChunk;
	int32_t ___ElementSize;
	int32_t ___BufferCapacity;
	uint64_t ___MemoryOrdering;
	uint64_t ___StableTypeHash;
	uint64_t ___BloomFilterMask;
	int32_t ___AlignmentInBytes;
	int32_t ___Category;
	int32_t ___EntityOffsetCount;
	int32_t ___EntityOffsetStartIndex;
	int32_t ____HasBlobAssetRefs;
	int32_t ____HasUnityObjectRefs;
	int32_t ___BlobAssetRefOffsetCount;
	int32_t ___BlobAssetRefOffsetStartIndex;
	int32_t ___WeakAssetRefOffsetCount;
	int32_t ___WeakAssetRefOffsetStartIndex;
	int32_t ___UnityObjectRefOffsetCount;
	int32_t ___UnityObjectRefOffsetStartIndex;
	int32_t ___WriteGroupCount;
	int32_t ___WriteGroupStartIndex;
	int32_t ___MaximumChunkCapacity;
	int32_t ___TypeSize;
};
struct Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87  : public MulticastDelegate_t
{
};
struct Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07  : public MulticastDelegate_t
{
};
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
	String_t* ____paramName;
};
struct Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA  : public Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3
{
};
struct HotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016  : public ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A
{
	List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* ___hotFixDlls;
	List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* ___aotMetaDlls;
};
struct InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct Readme_tE17B99201D0F52BD5727638AD3F41072A65B3BBB  : public ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A
{
	Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* ___icon;
	String_t* ___title;
	SectionU5BU5D_t9D3017555FFF42E71BE91904A2486EAF429F24C4* ___sections;
	bool ___loadedLayout;
};
struct ResourceModeConfig_tA1EF1939CF0C50D62898DF0070094DD2D7928FA3  : public ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A
{
	int32_t ____mode;
	int32_t ____bundleLoadingMaxConcurrency;
	List_1_t41E7BB3277E5E9E515E8B608D8B9F8ADF19B530D* ____packages;
};
struct BoxedGetHashCodeFn_t6FB594B3729237028A914FC35892E11F35EBD7A5  : public MulticastDelegate_t
{
};
struct GetBoxedEqualsFn_t1D3C86605A3BC070552B06B6F9C34588CB8BEA01  : public MulticastDelegate_t
{
};
struct GetBoxedEqualsPtrFn_t1902DF962742BD42AEC0802E437C41F357FC251C  : public MulticastDelegate_t
{
};
struct GetSystemAttributesFn_tFF3291428917181EF9DA36D06C3155DE423D30AA  : public MulticastDelegate_t
{
};
struct SetSharedTypeIndicesFn_t42DEBDCE57DA612BDBCC2CD1C7C6969F77858C0C  : public MulticastDelegate_t
{
};
struct MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71  : public Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA
{
	CancellationTokenSource_tAAE1E0033BCFC233801F8CB4CED5C852B350CB7B* ___m_CancellationTokenSource;
};
struct AOTGenericReferences_t7B8F9CD83F1EE53810C6F841826105D9416EA7C1  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
};
struct GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	List_1_t1BED237EBA2788604B1D39FC183B07E28F912A89* ____loadedHotfixAssemblies;
	RuntimeObject* ____resourceManager;
	HotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016* ____hotFixConfig;
};
struct List_1_t1BED237EBA2788604B1D39FC183B07E28F912A89_StaticFields
{
	AssemblyU5BU5D_t97B7B4E3FD4DA4944A4BFAA4DC484EA7D990B339* ___s_emptyArray;
};
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D_StaticFields
{
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___s_emptyArray;
};
struct List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD_StaticFields
{
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___s_emptyArray;
};
struct U3CPrivateImplementationDetailsU3E_t0F5473E849A5A5185A9F4C5246F0C32816C49FCA_StaticFields
{
	__StaticArrayInitTypeSizeU3D202_t41B6E33AD00E8A998F06BE18F77E2CEC9B6FA07F ___22BF73DEE36321E969C3CB45397B37D9DAF8EF9643FEEC9781E187210B414FE9;
	__StaticArrayInitTypeSizeU3D99_t77FABFEEC23FFEB91ECA8869D642BC4D243BBDCA ___FFCF93DEE207A03B9C747003659BB8BCAED1A2A78521B5C6B6B6BC5B63400A72;
};
struct AssemblyTypeRegistry_t38B36581EF406EB04A8CF7356B90E396D2EA34E5_StaticFields
{
	TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7* ___TypeRegistry;
	ConstantData0_t1F10138848E6A6434DF07663E3F6D55A4BAB7F40 ___Value0;
};
struct AwaiterActions_t5D05CAC006FDEBCF6B65E2B9224BC4B44783BBE5_StaticFields
{
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___InvokeContinuationDelegate;
};
struct String_t_StaticFields
{
	String_t* ___Empty;
};
struct SharedTypeIndex_1_tF0C6371F19CE027D0F9CA9CE843704927F5E7581_StaticFields
{
	SharedStatic_1_t62C042BCA77D8653DB2FC705185F0809C8C59D84 ___Ref;
};
struct SharedTypeIndex_1_t2C32D65079DB63CC448E325FB9378851A676AE73_StaticFields
{
	SharedStatic_1_t62C042BCA77D8653DB2FC705185F0809C8C59D84 ___Ref;
};
struct SharedTypeIndex_1_t77C75304B99808772DAC7FE28A8C92DB2A4231BA_StaticFields
{
	SharedStatic_1_t62C042BCA77D8653DB2FC705185F0809C8C59D84 ___Ref;
};
struct SharedTypeIndex_1_t3F0C6DA9E27125602575D8B02FAEAE477DA08DFE_StaticFields
{
	SharedStatic_1_t62C042BCA77D8653DB2FC705185F0809C8C59D84 ___Ref;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	String_t* ___TrueString;
	String_t* ___FalseString;
};
struct IntPtr_t_StaticFields
{
	intptr_t ___Zero;
};
struct UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270_StaticFields
{
	UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270 ___CanceledUniTask;
	UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270 ___CompletedTask;
};
struct Exception_t_StaticFields
{
	RuntimeObject* ___s_EDILock;
};
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_StaticFields
{
	int32_t ___OffsetOfInstanceIDInCPlusPlusObject;
};
struct Type_t_StaticFields
{
	Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235* ___s_defaultBinder;
	Il2CppChar ___Delimiter;
	TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* ___EmptyTypes;
	RuntimeObject* ___Missing;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterAttribute;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterName;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterNameIgnoreCase;
};
struct AOTGenericReferences_t7B8F9CD83F1EE53810C6F841826105D9416EA7C1_StaticFields
{
	RuntimeObject* ___PatchedAOTAssemblyList;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031  : public RuntimeArray
{
	ALIGN_FIELD (8) uint8_t m_Items[1];

	inline uint8_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline uint8_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, uint8_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline uint8_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline uint8_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, uint8_t value)
	{
		m_Items[index] = value;
	}
};
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918  : public RuntimeArray
{
	ALIGN_FIELD (8) RuntimeObject* m_Items[1];

	inline RuntimeObject* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, RuntimeObject* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline RuntimeObject* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, RuntimeObject* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB  : public RuntimeArray
{
	ALIGN_FIELD (8) Type_t* m_Items[1];

	inline Type_t* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Type_t** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Type_t* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline Type_t* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Type_t** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Type_t* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248  : public RuntimeArray
{
	ALIGN_FIELD (8) String_t* m_Items[1];

	inline String_t* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline String_t** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, String_t* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline String_t* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline String_t** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, String_t* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C  : public RuntimeArray
{
	ALIGN_FIELD (8) int32_t m_Items[1];

	inline int32_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline int32_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, int32_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline int32_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline int32_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, int32_t value)
	{
		m_Items[index] = value;
	}
};
struct WorldSystemFilterFlagsU5BU5D_t434BBC7E739D7E01D618B9C6A685B473CB24F9CC  : public RuntimeArray
{
	ALIGN_FIELD (8) uint32_t m_Items[1];

	inline uint32_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline uint32_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, uint32_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline uint32_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline uint32_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, uint32_t value)
	{
		m_Items[index] = value;
	}
};
struct Int64U5BU5D_tAEDFCBDB5414E2A140A6F34C0538BF97FCF67A1D  : public RuntimeArray
{
	ALIGN_FIELD (8) int64_t m_Items[1];

	inline int64_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline int64_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, int64_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline int64_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline int64_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, int64_t value)
	{
		m_Items[index] = value;
	}
};
struct AttributeU5BU5D_t0F73488E6F1249C889608E8DCC0BCC28A874E8F1  : public RuntimeArray
{
	ALIGN_FIELD (8) Attribute_tFDA8EFEFB0711976D22474794576DAF28F7440AA* m_Items[1];

	inline Attribute_tFDA8EFEFB0711976D22474794576DAF28F7440AA* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Attribute_tFDA8EFEFB0711976D22474794576DAF28F7440AA** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Attribute_tFDA8EFEFB0711976D22474794576DAF28F7440AA* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline Attribute_tFDA8EFEFB0711976D22474794576DAF28F7440AA* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Attribute_tFDA8EFEFB0711976D22474794576DAF28F7440AA** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Attribute_tFDA8EFEFB0711976D22474794576DAF28F7440AA* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};


IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ModuleSystem_Register_TisRuntimeObject_m7300520DC91DB9B09127D9E5FC1747BFF352B3ED_gshared (RuntimeObject* ___0_module, bool ___1_replace, bool ___2_exposeConcreteType, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ModuleSystem_Get_TisRuntimeObject_mEE32213CABC155EEA07594A151D15A0602395AEF_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void AsyncUniTaskMethodBuilder_Start_TisU3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129_m5B101A1A0A29177A7195A0F7BA5BA027A4AC58E1_gshared_inline (AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0* __this, U3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129* ___0_stateMachine, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Resources_Load_TisRuntimeObject_mD1AF6299B14F87ED1D1A6199A51480919F7C79D7_gshared (String_t* ___0_path, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A List_1_GetEnumerator_mD8294A7FA2BEB1929487127D476F8EC1CDC23BFC_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator_Dispose_mD9DC3E3C3697830A4823047AB29A77DBBB5ED419_gshared (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Enumerator_get_Current_m6330F15D18EE4F547C05DF9BF83C5EB710376027_gshared_inline (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerator_MoveNext_mE921CC8F29FBBDE7CC3209A0ED0D921D58D00BCB_gshared (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Clear_m16C1F2C61FED5955F10EB36BC1CB2DF34B128994_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void AsyncUniTaskMethodBuilder_AwaitUnsafeOnCompleted_TisAwaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956_TisU3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129_m65DA9E32C2BB838DA1CBBC1C0B8BE7B25E64C11C_gshared_inline (AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0* __this, Awaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956* ___0_awaiter, U3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129* ___1_stateMachine, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddRange_m1F76B300133150E6046C5FED00E88B5DE0A02E17_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C* SharedStatic_1_get_Data_m7B65B281F2D304BF7A408DDC24F8DA7DD99D9368_gshared (SharedStatic_1_t62C042BCA77D8653DB2FC705185F0809C8C59D84* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m79A9BF770BEF9C06BE40D5401E55E375F2726CC4_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AsyncUniTask_1_SetStateMachine_mAC4B51C33691C941ED75D31FC061D8470EEB1F0A_gshared (U3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129* ___0_stateMachine, RuntimeObject** ___1_runnerPromiseFieldRef, const RuntimeMethod* method) ;

IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ResourceManager__ctor_m83AB86D04323C4F50B332830646A2A3CF3597465 (ResourceManager_t66C02AB518045FFA776FDAB1AB6FF811155F51E6* __this, const RuntimeMethod* method) ;
inline void ModuleSystem_Register_TisIResourceManager_t2D98FEEEA5A917E1A722327BB77EB19BCF1432DC_m9E5D594363E1124D044614BFCB9D04DD4184BC4D (RuntimeObject* ___0_module, bool ___1_replace, bool ___2_exposeConcreteType, const RuntimeMethod* method)
{
	((  void (*) (RuntimeObject*, bool, bool, const RuntimeMethod*))ModuleSystem_Register_TisRuntimeObject_m7300520DC91DB9B09127D9E5FC1747BFF352B3ED_gshared)(___0_module, ___1_replace, ___2_exposeConcreteType, method);
}
inline RuntimeObject* ModuleSystem_Get_TisIResourceManager_t2D98FEEEA5A917E1A722327BB77EB19BCF1432DC_mFDF242FFAD78D6645C1AA37A8EDF87AB00652CDB (const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (const RuntimeMethod*))ModuleSystem_Get_TisRuntimeObject_mEE32213CABC155EEA07594A151D15A0602395AEF_gshared)(method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270 GameEntry_Init_m859801BF54A1DE1884AFC2620F97A18A8AB69B1D (GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UniTaskExtensions_Forget_m8F82202C3DB2020AAE7F874AE049DA711A01DF13 (UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270 ___0_task, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0 AsyncUniTaskMethodBuilder_Create_m882DFD5EE004FF6F84F182A3AC170AEDCA8C5327_inline (const RuntimeMethod* method) ;
inline void AsyncUniTaskMethodBuilder_Start_TisU3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129_m5B101A1A0A29177A7195A0F7BA5BA027A4AC58E1_inline (AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0* __this, U3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129* ___0_stateMachine, const RuntimeMethod* method)
{
	((  void (*) (AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0*, U3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129*, const RuntimeMethod*))AsyncUniTaskMethodBuilder_Start_TisU3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129_m5B101A1A0A29177A7195A0F7BA5BA027A4AC58E1_gshared_inline)(__this, ___0_stateMachine, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270 AsyncUniTaskMethodBuilder_get_Task_m11E43D69C4F85EB23AAC58143DE695309D1022EC_inline (AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___0_x, Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___1_y, const RuntimeMethod* method) ;
inline HotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016* Resources_Load_TisHotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016_m1D32AC03055E45095AEB79C68AEE61270BC63CCB (String_t* ___0_path, const RuntimeMethod* method)
{
	return ((  HotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016* (*) (String_t*, const RuntimeMethod*))Resources_Load_TisRuntimeObject_mD1AF6299B14F87ED1D1A6199A51480919F7C79D7_gshared)(___0_path, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___0_x, Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___1_y, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162 (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* __this, String_t* ___0_message, const RuntimeMethod* method) ;
inline Enumerator_tA7A4B718FE1ED1D87565680D8C8195EC8AEAB3D1 List_1_GetEnumerator_m7692B5F182858B7D5C72C920D09AD48738D1E70D (List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_tA7A4B718FE1ED1D87565680D8C8195EC8AEAB3D1 (*) (List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD*, const RuntimeMethod*))List_1_GetEnumerator_mD8294A7FA2BEB1929487127D476F8EC1CDC23BFC_gshared)(__this, method);
}
inline void Enumerator_Dispose_m592BCCE7B7933454DED2130C810F059F8D85B1D7 (Enumerator_tA7A4B718FE1ED1D87565680D8C8195EC8AEAB3D1* __this, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_tA7A4B718FE1ED1D87565680D8C8195EC8AEAB3D1*, const RuntimeMethod*))Enumerator_Dispose_mD9DC3E3C3697830A4823047AB29A77DBBB5ED419_gshared)(__this, method);
}
inline String_t* Enumerator_get_Current_m143541DD8FBCD313E7554EA738FA813B8F4DB11A_inline (Enumerator_tA7A4B718FE1ED1D87565680D8C8195EC8AEAB3D1* __this, const RuntimeMethod* method)
{
	return ((  String_t* (*) (Enumerator_tA7A4B718FE1ED1D87565680D8C8195EC8AEAB3D1*, const RuntimeMethod*))Enumerator_get_Current_m6330F15D18EE4F547C05DF9BF83C5EB710376027_gshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* GameEntry_LoadDllBytes_m5D4614AFAEB0464FFA0DDCB52147F14BF8AF4D72 (GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE* __this, String_t* ___0_dllName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RuntimeApi_LoadMetadataForAOTAssembly_mE1E398132DBF86D7DE042300E1EE6AC37B7649D8 (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_dllBytes, int32_t ___1_mode, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987 (String_t* ___0_format, RuntimeObject* ___1_arg0, RuntimeObject* ___2_arg1, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Log_Warning_m7FF0980010D110D5CDD69423319E1B01EE901AC3 (String_t* ___0_message, Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___1_context, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Concat_m9E3155FB84015C823606188F53B47CB44C444991 (String_t* ___0_str0, String_t* ___1_str1, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Log_Info_mE0A7D8A54E5A9315752D1B219753C5A29F40133C (String_t* ___0_message, Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___1_context, const RuntimeMethod* method) ;
inline bool Enumerator_MoveNext_mDB47EEC4531D33B9C33FD2E70BA15E1535A0F3ED (Enumerator_tA7A4B718FE1ED1D87565680D8C8195EC8AEAB3D1* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_tA7A4B718FE1ED1D87565680D8C8195EC8AEAB3D1*, const RuntimeMethod*))Enumerator_MoveNext_mE921CC8F29FBBDE7CC3209A0ED0D921D58D00BCB_gshared)(__this, method);
}
inline void List_1_Clear_m9C25692520A49715927D2C255A19820D042DD1C6_inline (List_1_t1BED237EBA2788604B1D39FC183B07E28F912A89* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_t1BED237EBA2788604B1D39FC183B07E28F912A89*, const RuntimeMethod*))List_1_Clear_m16C1F2C61FED5955F10EB36BC1CB2DF34B128994_gshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Assembly_t* Assembly_Load_mD9E9CED2EFF8BBE97ACDE83FB8ED492D1E42E975 (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_rawAssembly, const RuntimeMethod* method) ;
inline void List_1_Add_mC333738F45652C892517660DEE4B22270EF9D0A2_inline (List_1_t1BED237EBA2788604B1D39FC183B07E28F912A89* __this, Assembly_t* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t1BED237EBA2788604B1D39FC183B07E28F912A89*, Assembly_t*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
inline Enumerator_t2E011DE5D9C8DB2A137AE9CD1D7516D52F2A95AA List_1_GetEnumerator_mAEAF74A8D17E88F088AB910E5A3FA8FA37488E7D (List_1_t1BED237EBA2788604B1D39FC183B07E28F912A89* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_t2E011DE5D9C8DB2A137AE9CD1D7516D52F2A95AA (*) (List_1_t1BED237EBA2788604B1D39FC183B07E28F912A89*, const RuntimeMethod*))List_1_GetEnumerator_mD8294A7FA2BEB1929487127D476F8EC1CDC23BFC_gshared)(__this, method);
}
inline void Enumerator_Dispose_m93B736E6DBFFC747D775D68C8CA34947DAE8B1C2 (Enumerator_t2E011DE5D9C8DB2A137AE9CD1D7516D52F2A95AA* __this, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_t2E011DE5D9C8DB2A137AE9CD1D7516D52F2A95AA*, const RuntimeMethod*))Enumerator_Dispose_mD9DC3E3C3697830A4823047AB29A77DBBB5ED419_gshared)(__this, method);
}
inline Assembly_t* Enumerator_get_Current_mC25A7F22ACFD0C89749FD0D52C3A845228B2737F_inline (Enumerator_t2E011DE5D9C8DB2A137AE9CD1D7516D52F2A95AA* __this, const RuntimeMethod* method)
{
	return ((  Assembly_t* (*) (Enumerator_t2E011DE5D9C8DB2A137AE9CD1D7516D52F2A95AA*, const RuntimeMethod*))Enumerator_get_Current_m6330F15D18EE4F547C05DF9BF83C5EB710376027_gshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC (Type_t* ___0_left, Type_t* ___1_right, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MethodInfo_t* Type_GetMethod_m9E66B5053F150537A74C490C1DA5174A7875189D (Type_t* __this, String_t* ___0_name, int32_t ___1_bindingAttr, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool MethodInfo_op_Equality_m1466AB76300C9F07856E706E7E914062175189D1 (MethodInfo_t* ___0_left, MethodInfo_t* ___1_right, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* MethodBase_Invoke_mEEF3218648F111A8C338001A7804091A0747C826 (MethodBase_t* __this, RuntimeObject* ___0_obj, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___1_parameters, const RuntimeMethod* method) ;
inline bool Enumerator_MoveNext_m9360A25E040507C2A33C02E92ACE8AD5ABA3E0FB (Enumerator_t2E011DE5D9C8DB2A137AE9CD1D7516D52F2A95AA* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_t2E011DE5D9C8DB2A137AE9CD1D7516D52F2A95AA*, const RuntimeMethod*))Enumerator_MoveNext_mE921CC8F29FBBDE7CC3209A0ED0D921D58D00BCB_gshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Concat_m8855A6DE10F84DA7F4EC113CADDB59873A25573B (String_t* ___0_str0, String_t* ___1_str1, String_t* ___2_str2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HandleBase_Release_m1C1A6ADF9F7242BED32B5658281B3C44801E2AA7 (HandleBase_t571827F810EAE331C05542D54B2C396C605DB4DA* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* AssetHandle_get_AssetObject_mDB40AA493209F594A94232EAADA774B6889DAF86 (AssetHandle_tA226E2C9CFE7231AF71DFADFCBF947D4D1CC2AF3* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* TextAsset_get_bytes_m244B31755642C9623B570FC96B9A04523B1E5178 (TextAsset_t2C64E93DA366D9DE5A8209E1802FA4884AC1BD69* __this, const RuntimeMethod* method) ;
inline void List_1__ctor_m7F799D24C042923B6F560AF8FEA1CB00A1233888 (List_1_t1BED237EBA2788604B1D39FC183B07E28F912A89* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_t1BED237EBA2788604B1D39FC183B07E28F912A89*, const RuntimeMethod*))List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E (MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Awaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956 UniTask_GetAwaiter_mF05A09B81913BECFD58FC67A16C0251FFCCAC939_inline (UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Awaiter_get_IsCompleted_m2D01E3AB8A7C5AA8AA1E1EF58D92A6A095C00B9A_inline (Awaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956* __this, const RuntimeMethod* method) ;
inline void AsyncUniTaskMethodBuilder_AwaitUnsafeOnCompleted_TisAwaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956_TisU3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129_m65DA9E32C2BB838DA1CBBC1C0B8BE7B25E64C11C_inline (AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0* __this, Awaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956* ___0_awaiter, U3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129* ___1_stateMachine, const RuntimeMethod* method)
{
	((  void (*) (AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0*, Awaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956*, U3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129*, const RuntimeMethod*))AsyncUniTaskMethodBuilder_AwaitUnsafeOnCompleted_TisAwaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956_TisU3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129_m65DA9E32C2BB838DA1CBBC1C0B8BE7B25E64C11C_gshared_inline)(__this, ___0_awaiter, ___1_stateMachine, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Awaiter_GetResult_mC439993563D3BD49CEC67AAF6AFB3AEF72E916BD_inline (Awaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameEntry_LoadHotfixConfig_m184C10567CEBD6A56FFCABFE11081EFFBDD37CF1 (GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameEntry_LoadAotMetadataAssemblies_m23F4BBC7F91981546C4F89414DC062570B778399 (GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameEntry_LoadHotUpdateAssemblies_m74C1034D233B6F72CF14DAC74AED7C4ACC00E469 (GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameEntry_InvokeHotfixEntry_m4BB63989E22A673D5268F18D765639C89C593903 (GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8 (String_t* ___0_format, RuntimeObject* ___1_arg0, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Log_Error_mD79843A05F9947233E3AE358E98C063B86895B53 (String_t* ___0_message, Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___1_context, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void AsyncUniTaskMethodBuilder_SetException_m0D772D62D01CC371F4AB0F6943BBBE0FEAB19643_inline (AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0* __this, Exception_t* ___0_exception, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void AsyncUniTaskMethodBuilder_SetResult_mBBA527F0F21E04D65A269C0D02597CE5B2D1E9CB_inline (AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CInitU3Ed__6_MoveNext_mDBDB72E5E93D5EB8DD159440DF156C801E5AD0AF (U3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AsyncUniTaskMethodBuilder_SetStateMachine_m466E6779CB9DEC814C0A59E7766D95EC2C3268CF (AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0* __this, RuntimeObject* ___0_stateMachine, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CInitU3Ed__6_SetStateMachine_mFFC8211380B6F39E9F897BE540C5E43CD03ED80C (U3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129* __this, RuntimeObject* ___0_stateMachine, const RuntimeMethod* method) ;
inline void List_1__ctor_mCA8DD57EAC70C2B5923DBB9D5A77CEAC22E7068E (List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD*, const RuntimeMethod*))List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared)(__this, method);
}
inline void List_1_Add_mF10DB1D3CBB0B14215F0E4F8AB4934A1955E5351_inline (List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* __this, String_t* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD*, String_t*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ScriptableObject__ctor_mD037FDB0B487295EA47F79A4DB1BF1846C9087FF (ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RuntimeHelpers_InitializeArray_m751372AA3F24FBF6DA9B9D687CBFA2DE436CAB9B (RuntimeArray* ___0_array, RuntimeFieldHandle_t6E4C45B6D2EA12FC99185805A7E77527899B25C5 ___1_fldHandle, const RuntimeMethod* method) ;
inline void List_1_AddRange_m157DD7AD4D25423F82A21E533BC4686C83770D5E (List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method)
{
	((  void (*) (List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD*, RuntimeObject*, const RuntimeMethod*))List_1_AddRange_m1F76B300133150E6046C5FED00E88B5DE0A02E17_gshared)(__this, ___0_collection, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TypeRegistry__ctor_mA659C5403A2DC55AF2ACB47255F4D100B90D2A7F (TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57 (RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ___0_handle, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GetBoxedEqualsFn__ctor_mDC463EBA3EBEC465257344D7779A256962EB2FC5 (GetBoxedEqualsFn_t1D3C86605A3BC070552B06B6F9C34588CB8BEA01* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GetBoxedEqualsPtrFn__ctor_m3EAE6EFF779D92AB28B639EC0B511AD2CBC273B3 (GetBoxedEqualsPtrFn_t1902DF962742BD42AEC0802E437C41F357FC251C* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BoxedGetHashCodeFn__ctor_m17A49B9995CCAA53F90B4495B325F011B5EC4E60 (BoxedGetHashCodeFn_t6FB594B3729237028A914FC35892E11F35EBD7A5* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GetSystemAttributesFn__ctor_m9236C825F0DFD0303926C0D730374EDCA453609F (GetSystemAttributesFn_tFF3291428917181EF9DA36D06C3155DE423D30AA* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SetSharedTypeIndicesFn__ctor_m7C4E8AE7DC32AE4374058368A031F75266CD3F00 (SetSharedTypeIndicesFn_t42DEBDCE57DA612BDBCC2CD1C7C6969F77858C0C* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_MemCmp_mA0E0E1A93F715105E7B576F1603DCAB37717A5EF (void* ___0_ptr1, void* ___1_ptr2, int64_t ___2_size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* __this, String_t* ___0_message, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t XXHash_Hash32_mCA5C9D8E9CBF5556CB85DC6C9847152A6C658FC1 (uint8_t* ___0_buffer, int32_t ___1_bufferLength, uint32_t ___2_seed, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465 (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* __this, String_t* ___0_message, const RuntimeMethod* method) ;
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C* SharedStatic_1_get_Data_m7B65B281F2D304BF7A408DDC24F8DA7DD99D9368 (SharedStatic_1_t62C042BCA77D8653DB2FC705185F0809C8C59D84* __this, const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C* (*) (SharedStatic_1_t62C042BCA77D8653DB2FC705185F0809C8C59D84*, const RuntimeMethod*))SharedStatic_1_get_Data_m7B65B281F2D304BF7A408DDC24F8DA7DD99D9368_gshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270 UniTask_FromException_mC6AC508C727D591C6BE908F2014570963CE9E5EE (Exception_t* ___0_ex, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Awaiter__ctor_m4154A3A6D62BB1657D17A8106633CD9E1CE51F04_inline (Awaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956* __this, UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270* ___0_task, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UniTask_get_Status_mA15B0F13DE3CE36730357CF50F65AE99ADF564DA_inline (UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool UniTaskStatusExtensions_IsCompleted_mF43C41C9CEB640E381D1F7A8B40142843AED87AE_inline (int32_t ___0_status, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB (RuntimeArray* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
inline void List_1_AddWithResize_m79A9BF770BEF9C06BE40D5401E55E375F2726CC4 (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D*, RuntimeObject*, const RuntimeMethod*))List_1_AddWithResize_m79A9BF770BEF9C06BE40D5401E55E375F2726CC4_gshared)(__this, ___0_item, method);
}
inline void AsyncUniTask_1_SetStateMachine_mAC4B51C33691C941ED75D31FC061D8470EEB1F0A (U3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129* ___0_stateMachine, RuntimeObject** ___1_runnerPromiseFieldRef, const RuntimeMethod* method)
{
	((  void (*) (U3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129*, RuntimeObject**, const RuntimeMethod*))AsyncUniTask_1_SetStateMachine_mAC4B51C33691C941ED75D31FC061D8470EEB1F0A_gshared)(___0_stateMachine, ___1_runnerPromiseFieldRef, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Awaiter_UnsafeOnCompleted_m6C4775F8F4F2BEFB8118EBBA1EA621440CE84D62_inline (Awaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956* __this, Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___0_continuation, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_Invoke_m7126A54DACA72B845424072887B5F3A51FC3808E_inline (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* __this, const RuntimeMethod* method) ;
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 80674
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameEntry_Awake_m6BCF3EB877719892DB3CF986C303DD9C054AD1EE (GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ModuleSystem_Get_TisIResourceManager_t2D98FEEEA5A917E1A722327BB77EB19BCF1432DC_mFDF242FFAD78D6645C1AA37A8EDF87AB00652CDB_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ModuleSystem_Register_TisIResourceManager_t2D98FEEEA5A917E1A722327BB77EB19BCF1432DC_m9E5D594363E1124D044614BFCB9D04DD4184BC4D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ModuleSystem_tEB75335684504282F045968A3B212CE31057E32F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ResourceManager_t66C02AB518045FFA776FDAB1AB6FF811155F51E6_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:23>
		ResourceManager_t66C02AB518045FFA776FDAB1AB6FF811155F51E6* L_0 = (ResourceManager_t66C02AB518045FFA776FDAB1AB6FF811155F51E6*)il2cpp_codegen_object_new(ResourceManager_t66C02AB518045FFA776FDAB1AB6FF811155F51E6_il2cpp_TypeInfo_var);
		ResourceManager__ctor_m83AB86D04323C4F50B332830646A2A3CF3597465(L_0, NULL);
		il2cpp_codegen_runtime_class_init_inline(ModuleSystem_tEB75335684504282F045968A3B212CE31057E32F_il2cpp_TypeInfo_var);
		ModuleSystem_Register_TisIResourceManager_t2D98FEEEA5A917E1A722327BB77EB19BCF1432DC_m9E5D594363E1124D044614BFCB9D04DD4184BC4D(L_0, (bool)0, (bool)1, ModuleSystem_Register_TisIResourceManager_t2D98FEEEA5A917E1A722327BB77EB19BCF1432DC_m9E5D594363E1124D044614BFCB9D04DD4184BC4D_RuntimeMethod_var);
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:24>
		RuntimeObject* L_1;
		L_1 = ModuleSystem_Get_TisIResourceManager_t2D98FEEEA5A917E1A722327BB77EB19BCF1432DC_mFDF242FFAD78D6645C1AA37A8EDF87AB00652CDB(ModuleSystem_Get_TisIResourceManager_t2D98FEEEA5A917E1A722327BB77EB19BCF1432DC_mFDF242FFAD78D6645C1AA37A8EDF87AB00652CDB_RuntimeMethod_var);
		__this->____resourceManager = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____resourceManager), (void*)L_1);
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:25>
		UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270 L_2;
		L_2 = GameEntry_Init_m859801BF54A1DE1884AFC2620F97A18A8AB69B1D(__this, NULL);
		UniTaskExtensions_Forget_m8F82202C3DB2020AAE7F874AE049DA711A01DF13(L_2, NULL);
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:26>
		return;
	}
}
// Method Definition Index: 80675
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270 GameEntry_Init_m859801BF54A1DE1884AFC2620F97A18A8AB69B1D (GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AsyncUniTaskMethodBuilder_Start_TisU3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129_m5B101A1A0A29177A7195A0F7BA5BA027A4AC58E1_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	U3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0 L_0;
		L_0 = AsyncUniTaskMethodBuilder_Create_m882DFD5EE004FF6F84F182A3AC170AEDCA8C5327_inline(NULL);
		(&V_0)->___U3CU3Et__builder = L_0;
		Il2CppCodeGenWriteBarrier((void**)&(((&(&V_0)->___U3CU3Et__builder))->___runnerPromise), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&(&V_0)->___U3CU3Et__builder))->___ex), (void*)NULL);
		#endif
		(&V_0)->___U3CU3E4__this = __this;
		Il2CppCodeGenWriteBarrier((void**)(&(&V_0)->___U3CU3E4__this), (void*)__this);
		(&V_0)->___U3CU3E1__state = (-1);
		AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0* L_1 = (AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0*)(&(&V_0)->___U3CU3Et__builder);
		AsyncUniTaskMethodBuilder_Start_TisU3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129_m5B101A1A0A29177A7195A0F7BA5BA027A4AC58E1_inline(L_1, (&V_0), AsyncUniTaskMethodBuilder_Start_TisU3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129_m5B101A1A0A29177A7195A0F7BA5BA027A4AC58E1_RuntimeMethod_var);
		AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0* L_2 = (AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0*)(&(&V_0)->___U3CU3Et__builder);
		UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270 L_3;
		L_3 = AsyncUniTaskMethodBuilder_get_Task_m11E43D69C4F85EB23AAC58143DE695309D1022EC_inline(L_2, NULL);
		return L_3;
	}
}
// Method Definition Index: 80676
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameEntry_LoadHotfixConfig_m184C10567CEBD6A56FFCABFE11081EFFBDD37CF1 (GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Resources_Load_TisHotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016_m1D32AC03055E45095AEB79C68AEE61270BC63CCB_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral60F856B7F965F851619A60BD211976AEF512315D);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:51>
		HotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016* L_0 = __this->____hotFixConfig;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602(L_0, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_1)
		{
			goto IL_000f;
		}
	}
	{
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:53>
		return;
	}

IL_000f:
	{
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:56>
		HotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016* L_2;
		L_2 = Resources_Load_TisHotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016_m1D32AC03055E45095AEB79C68AEE61270BC63CCB(_stringLiteral60F856B7F965F851619A60BD211976AEF512315D, Resources_Load_TisHotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016_m1D32AC03055E45095AEB79C68AEE61270BC63CCB_RuntimeMethod_var);
		__this->____hotFixConfig = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____hotFixConfig), (void*)L_2);
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:57>
		HotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016* L_3 = __this->____hotFixConfig;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_4;
		L_4 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(L_3, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_4)
		{
			goto IL_0038;
		}
	}
	{
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:59>
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_5 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_5, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral5E153135A0B21174A583C1AB81197282B3C2D696)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_5, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&GameEntry_LoadHotfixConfig_m184C10567CEBD6A56FFCABFE11081EFFBDD37CF1_RuntimeMethod_var)));
	}

IL_0038:
	{
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:61>
		return;
	}
}
// Method Definition Index: 80677
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameEntry_LoadAotMetadataAssemblies_m23F4BBC7F91981546C4F89414DC062570B778399 (GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_Dispose_m592BCCE7B7933454DED2130C810F059F8D85B1D7_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_MoveNext_mDB47EEC4531D33B9C33FD2E70BA15E1535A0F3ED_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_get_Current_m143541DD8FBCD313E7554EA738FA813B8F4DB11A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_GetEnumerator_m7692B5F182858B7D5C72C920D09AD48738D1E70D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&LoadImageErrorCode_tC778A2553ADB45B8C61EFE26C20837C23894FEB3_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1ECF4C0AFFCF469C57E42CE9A095A0874A861235);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDF3B4424E614400CA8576744772CF0A4BE189BFB);
		s_Il2CppMethodInitialized = true;
	}
	Enumerator_tA7A4B718FE1ED1D87565680D8C8195EC8AEAB3D1 V_0;
	memset((&V_0), 0, sizeof(V_0));
	String_t* V_1 = NULL;
	int32_t V_2 = 0;
	{
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:65>
		HotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016* L_0 = __this->____hotFixConfig;
		NullCheck(L_0);
		List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* L_1 = L_0->___aotMetaDlls;
		NullCheck(L_1);
		Enumerator_tA7A4B718FE1ED1D87565680D8C8195EC8AEAB3D1 L_2;
		L_2 = List_1_GetEnumerator_m7692B5F182858B7D5C72C920D09AD48738D1E70D(L_1, List_1_GetEnumerator_m7692B5F182858B7D5C72C920D09AD48738D1E70D_RuntimeMethod_var);
		V_0 = L_2;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0061:
			{
				Enumerator_Dispose_m592BCCE7B7933454DED2130C810F059F8D85B1D7((&V_0), Enumerator_Dispose_m592BCCE7B7933454DED2130C810F059F8D85B1D7_RuntimeMethod_var);
				return;
			}
		});
		try
		{
			{
				goto IL_0056_1;
			}

IL_0013_1:
			{
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:65>
				String_t* L_3;
				L_3 = Enumerator_get_Current_m143541DD8FBCD313E7554EA738FA813B8F4DB11A_inline((&V_0), Enumerator_get_Current_m143541DD8FBCD313E7554EA738FA813B8F4DB11A_RuntimeMethod_var);
				V_1 = L_3;
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:67>
				String_t* L_4 = V_1;
				ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_5;
				L_5 = GameEntry_LoadDllBytes_m5D4614AFAEB0464FFA0DDCB52147F14BF8AF4D72(__this, L_4, NULL);
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:68>
				int32_t L_6;
				L_6 = RuntimeApi_LoadMetadataForAOTAssembly_mE1E398132DBF86D7DE042300E1EE6AC37B7649D8(L_5, 1, NULL);
				V_2 = L_6;
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:69>
				int32_t L_7 = V_2;
				if (!L_7)
				{
					goto IL_0045_1;
				}
			}
			{
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:71>
				String_t* L_8 = V_1;
				int32_t L_9 = V_2;
				int32_t L_10 = L_9;
				RuntimeObject* L_11 = Box(LoadImageErrorCode_tC778A2553ADB45B8C61EFE26C20837C23894FEB3_il2cpp_TypeInfo_var, &L_10);
				String_t* L_12;
				L_12 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteralDF3B4424E614400CA8576744772CF0A4BE189BFB, L_8, L_11, NULL);
				Log_Warning_m7FF0980010D110D5CDD69423319E1B01EE901AC3(L_12, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
				goto IL_0056_1;
			}

IL_0045_1:
			{
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:75>
				String_t* L_13 = V_1;
				String_t* L_14;
				L_14 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(_stringLiteral1ECF4C0AFFCF469C57E42CE9A095A0874A861235, L_13, NULL);
				Log_Info_mE0A7D8A54E5A9315752D1B219753C5A29F40133C(L_14, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
			}

IL_0056_1:
			{
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:65>
				bool L_15;
				L_15 = Enumerator_MoveNext_mDB47EEC4531D33B9C33FD2E70BA15E1535A0F3ED((&V_0), Enumerator_MoveNext_mDB47EEC4531D33B9C33FD2E70BA15E1535A0F3ED_RuntimeMethod_var);
				if (L_15)
				{
					goto IL_0013_1;
				}
			}
			{
				goto IL_006f;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_006f:
	{
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:78>
		return;
	}
}
// Method Definition Index: 80678
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameEntry_LoadHotUpdateAssemblies_m74C1034D233B6F72CF14DAC74AED7C4ACC00E469 (GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_Dispose_m592BCCE7B7933454DED2130C810F059F8D85B1D7_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_MoveNext_mDB47EEC4531D33B9C33FD2E70BA15E1535A0F3ED_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_get_Current_m143541DD8FBCD313E7554EA738FA813B8F4DB11A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mC333738F45652C892517660DEE4B22270EF9D0A2_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Clear_m9C25692520A49715927D2C255A19820D042DD1C6_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_GetEnumerator_m7692B5F182858B7D5C72C920D09AD48738D1E70D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralFD9218F87D9D2167DB92BA630674DC7A1DBAD834);
		s_Il2CppMethodInitialized = true;
	}
	Enumerator_tA7A4B718FE1ED1D87565680D8C8195EC8AEAB3D1 V_0;
	memset((&V_0), 0, sizeof(V_0));
	String_t* V_1 = NULL;
	Assembly_t* V_2 = NULL;
	{
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:82>
		List_1_t1BED237EBA2788604B1D39FC183B07E28F912A89* L_0 = __this->____loadedHotfixAssemblies;
		NullCheck(L_0);
		List_1_Clear_m9C25692520A49715927D2C255A19820D042DD1C6_inline(L_0, List_1_Clear_m9C25692520A49715927D2C255A19820D042DD1C6_RuntimeMethod_var);
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:84>
		HotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016* L_1 = __this->____hotFixConfig;
		NullCheck(L_1);
		List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* L_2 = L_1->___hotFixDlls;
		NullCheck(L_2);
		Enumerator_tA7A4B718FE1ED1D87565680D8C8195EC8AEAB3D1 L_3;
		L_3 = List_1_GetEnumerator_m7692B5F182858B7D5C72C920D09AD48738D1E70D(L_2, List_1_GetEnumerator_m7692B5F182858B7D5C72C920D09AD48738D1E70D_RuntimeMethod_var);
		V_0 = L_3;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_005b:
			{
				Enumerator_Dispose_m592BCCE7B7933454DED2130C810F059F8D85B1D7((&V_0), Enumerator_Dispose_m592BCCE7B7933454DED2130C810F059F8D85B1D7_RuntimeMethod_var);
				return;
			}
		});
		try
		{
			{
				goto IL_0050_1;
			}

IL_001e_1:
			{
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:84>
				String_t* L_4;
				L_4 = Enumerator_get_Current_m143541DD8FBCD313E7554EA738FA813B8F4DB11A_inline((&V_0), Enumerator_get_Current_m143541DD8FBCD313E7554EA738FA813B8F4DB11A_RuntimeMethod_var);
				V_1 = L_4;
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:86>
				String_t* L_5 = V_1;
				ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_6;
				L_6 = GameEntry_LoadDllBytes_m5D4614AFAEB0464FFA0DDCB52147F14BF8AF4D72(__this, L_5, NULL);
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:87>
				Assembly_t* L_7;
				L_7 = Assembly_Load_mD9E9CED2EFF8BBE97ACDE83FB8ED492D1E42E975(L_6, NULL);
				V_2 = L_7;
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:88>
				List_1_t1BED237EBA2788604B1D39FC183B07E28F912A89* L_8 = __this->____loadedHotfixAssemblies;
				Assembly_t* L_9 = V_2;
				NullCheck(L_8);
				List_1_Add_mC333738F45652C892517660DEE4B22270EF9D0A2_inline(L_8, L_9, List_1_Add_mC333738F45652C892517660DEE4B22270EF9D0A2_RuntimeMethod_var);
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:89>
				String_t* L_10 = V_1;
				String_t* L_11;
				L_11 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(_stringLiteralFD9218F87D9D2167DB92BA630674DC7A1DBAD834, L_10, NULL);
				Log_Info_mE0A7D8A54E5A9315752D1B219753C5A29F40133C(L_11, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
			}

IL_0050_1:
			{
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:84>
				bool L_12;
				L_12 = Enumerator_MoveNext_mDB47EEC4531D33B9C33FD2E70BA15E1535A0F3ED((&V_0), Enumerator_MoveNext_mDB47EEC4531D33B9C33FD2E70BA15E1535A0F3ED_RuntimeMethod_var);
				if (L_12)
				{
					goto IL_001e_1;
				}
			}
			{
				goto IL_0069;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0069:
	{
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:91>
		return;
	}
}
// Method Definition Index: 80679
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameEntry_InvokeHotfixEntry_m4BB63989E22A673D5268F18D765639C89C593903 (GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_Dispose_m93B736E6DBFFC747D775D68C8CA34947DAE8B1C2_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_MoveNext_m9360A25E040507C2A33C02E92ACE8AD5ABA3E0FB_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_get_Current_mC25A7F22ACFD0C89749FD0D52C3A845228B2737F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_GetEnumerator_mAEAF74A8D17E88F088AB910E5A3FA8FA37488E7D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0E51F4817B1D8367D96FA6DABA71C29B7A6AF524);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral3C74EE53B1AF65557F9BDF1EAF0C416BADC79DB9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralB7359FF4466AF47CB32CD42933A685AB7E322114);
		s_Il2CppMethodInitialized = true;
	}
	Enumerator_t2E011DE5D9C8DB2A137AE9CD1D7516D52F2A95AA V_0;
	memset((&V_0), 0, sizeof(V_0));
	Type_t* V_1 = NULL;
	MethodInfo_t* G_B5_0 = NULL;
	MethodInfo_t* G_B4_0 = NULL;
	{
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:98>
		List_1_t1BED237EBA2788604B1D39FC183B07E28F912A89* L_0 = __this->____loadedHotfixAssemblies;
		NullCheck(L_0);
		Enumerator_t2E011DE5D9C8DB2A137AE9CD1D7516D52F2A95AA L_1;
		L_1 = List_1_GetEnumerator_mAEAF74A8D17E88F088AB910E5A3FA8FA37488E7D(L_0, List_1_GetEnumerator_mAEAF74A8D17E88F088AB910E5A3FA8FA37488E7D_RuntimeMethod_var);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_006a:
			{
				Enumerator_Dispose_m93B736E6DBFFC747D775D68C8CA34947DAE8B1C2((&V_0), Enumerator_Dispose_m93B736E6DBFFC747D775D68C8CA34947DAE8B1C2_RuntimeMethod_var);
				return;
			}
		});
		try
		{
			{
				goto IL_005f_1;
			}

IL_000e_1:
			{
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:98>
				Assembly_t* L_2;
				L_2 = Enumerator_get_Current_mC25A7F22ACFD0C89749FD0D52C3A845228B2737F_inline((&V_0), Enumerator_get_Current_mC25A7F22ACFD0C89749FD0D52C3A845228B2737F_RuntimeMethod_var);
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:100>
				NullCheck(L_2);
				Type_t* L_3;
				L_3 = VirtualFuncInvoker1< Type_t*, String_t* >::Invoke(17, L_2, _stringLiteralB7359FF4466AF47CB32CD42933A685AB7E322114);
				V_1 = L_3;
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:101>
				Type_t* L_4 = V_1;
				il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
				bool L_5;
				L_5 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_4, (Type_t*)NULL, NULL);
				if (L_5)
				{
					goto IL_005f_1;
				}
			}
			{
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:106>
				Type_t* L_6 = V_1;
				NullCheck(L_6);
				MethodInfo_t* L_7;
				L_7 = Type_GetMethod_m9E66B5053F150537A74C490C1DA5174A7875189D(L_6, _stringLiteral3C74EE53B1AF65557F9BDF1EAF0C416BADC79DB9, ((int32_t)24), NULL);
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:107>
				MethodInfo_t* L_8 = L_7;
				bool L_9;
				L_9 = MethodInfo_op_Equality_m1466AB76300C9F07856E706E7E914062175189D1(L_8, (MethodInfo_t*)NULL, NULL);
				if (!L_9)
				{
					G_B5_0 = L_8;
					goto IL_004a_1;
				}
				G_B4_0 = L_8;
			}
			{
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:109>
				InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_10 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
				InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_10, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral83DFE0CCE9E74A4499E55D2AEA4F20F44111613E)), NULL);
				IL2CPP_RAISE_MANAGED_EXCEPTION(L_10, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&GameEntry_InvokeHotfixEntry_m4BB63989E22A673D5268F18D765639C89C593903_RuntimeMethod_var)));
			}

IL_004a_1:
			{
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:112>
				NullCheck(G_B5_0);
				RuntimeObject* L_11;
				L_11 = MethodBase_Invoke_mEEF3218648F111A8C338001A7804091A0747C826(G_B5_0, NULL, (ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)NULL, NULL);
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:113>
				Log_Info_mE0A7D8A54E5A9315752D1B219753C5A29F40133C(_stringLiteral0E51F4817B1D8367D96FA6DABA71C29B7A6AF524, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:114>
				goto IL_0083;
			}

IL_005f_1:
			{
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:98>
				bool L_12;
				L_12 = Enumerator_MoveNext_m9360A25E040507C2A33C02E92ACE8AD5ABA3E0FB((&V_0), Enumerator_MoveNext_m9360A25E040507C2A33C02E92ACE8AD5ABA3E0FB_RuntimeMethod_var);
				if (L_12)
				{
					goto IL_000e_1;
				}
			}
			{
				goto IL_0078;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0078:
	{
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:117>
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_13 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_13, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral7EFD626CCF8D8CE5F1D228CC8AC91FCEAFBCDF7E)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_13, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&GameEntry_InvokeHotfixEntry_m4BB63989E22A673D5268F18D765639C89C593903_RuntimeMethod_var)));
	}

IL_0083:
	{
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:118>
		return;
	}
}
// Method Definition Index: 80680
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* GameEntry_LoadDllBytes_m5D4614AFAEB0464FFA0DDCB52147F14BF8AF4D72 (GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE* __this, String_t* ___0_dllName, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IResourceManager_LoadAssetSync_TisTextAsset_t2C64E93DA366D9DE5A8209E1802FA4884AC1BD69_mF011E03A43DB9CA43887C5E2A774AF08D82186FD_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TextAsset_t2C64E93DA366D9DE5A8209E1802FA4884AC1BD69_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral4D662484694B003BFD98792D0B13414D4CE7C1A2);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralEC4C5477D8BA260A27C36AFD7E8C1C289169E9CF);
		s_Il2CppMethodInitialized = true;
	}
	String_t* V_0 = NULL;
	AssetHandle_tA226E2C9CFE7231AF71DFADFCBF947D4D1CC2AF3* V_1 = NULL;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_2 = NULL;
	TextAsset_t2C64E93DA366D9DE5A8209E1802FA4884AC1BD69* G_B5_0 = NULL;
	TextAsset_t2C64E93DA366D9DE5A8209E1802FA4884AC1BD69* G_B4_0 = NULL;
	{
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:122>
		String_t* L_0 = ___0_dllName;
		String_t* L_1;
		L_1 = String_Concat_m8855A6DE10F84DA7F4EC113CADDB59873A25573B(_stringLiteral4D662484694B003BFD98792D0B13414D4CE7C1A2, L_0, _stringLiteralEC4C5477D8BA260A27C36AFD7E8C1C289169E9CF, NULL);
		V_0 = L_1;
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:123>
		RuntimeObject* L_2 = __this->____resourceManager;
		String_t* L_3 = V_0;
		NullCheck(L_2);
		AssetHandle_tA226E2C9CFE7231AF71DFADFCBF947D4D1CC2AF3* L_4;
		L_4 = GenericInterfaceFuncInvoker2< AssetHandle_tA226E2C9CFE7231AF71DFADFCBF947D4D1CC2AF3*, String_t*, uint32_t >::Invoke(IResourceManager_LoadAssetSync_TisTextAsset_t2C64E93DA366D9DE5A8209E1802FA4884AC1BD69_mF011E03A43DB9CA43887C5E2A774AF08D82186FD_RuntimeMethod_var, L_2, L_3, 0);
		V_1 = L_4;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0060:
			{
				{
					//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:141>
					AssetHandle_tA226E2C9CFE7231AF71DFADFCBF947D4D1CC2AF3* L_5 = V_1;
					if (!L_5)
					{
						goto IL_0069;
					}
				}
				{
					AssetHandle_tA226E2C9CFE7231AF71DFADFCBF947D4D1CC2AF3* L_6 = V_1;
					NullCheck(L_6);
					HandleBase_Release_m1C1A6ADF9F7242BED32B5658281B3C44801E2AA7(L_6, NULL);
				}

IL_0069:
				{
					//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:142>
					return;
				}
			}
		});
		try
		{
			{
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:126>
				AssetHandle_tA226E2C9CFE7231AF71DFADFCBF947D4D1CC2AF3* L_7 = V_1;
				if (L_7)
				{
					goto IL_0033_1;
				}
			}
			{
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:128>
				String_t* L_8 = V_0;
				String_t* L_9;
				L_9 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralBC755F9F3AD75230DD0DEEF00D323B0256FCDEC0)), L_8, NULL);
				InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_10 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
				InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_10, L_9, NULL);
				IL2CPP_RAISE_MANAGED_EXCEPTION(L_10, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&GameEntry_LoadDllBytes_m5D4614AFAEB0464FFA0DDCB52147F14BF8AF4D72_RuntimeMethod_var)));
			}

IL_0033_1:
			{
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:131>
				AssetHandle_tA226E2C9CFE7231AF71DFADFCBF947D4D1CC2AF3* L_11 = V_1;
				NullCheck(L_11);
				Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* L_12;
				L_12 = AssetHandle_get_AssetObject_mDB40AA493209F594A94232EAADA774B6889DAF86(L_11, NULL);
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:132>
				TextAsset_t2C64E93DA366D9DE5A8209E1802FA4884AC1BD69* L_13 = ((TextAsset_t2C64E93DA366D9DE5A8209E1802FA4884AC1BD69*)IsInstClass((RuntimeObject*)L_12, TextAsset_t2C64E93DA366D9DE5A8209E1802FA4884AC1BD69_il2cpp_TypeInfo_var));
				il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
				bool L_14;
				L_14 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(L_13, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
				if (!L_14)
				{
					G_B5_0 = L_13;
					goto IL_0058_1;
				}
				G_B4_0 = L_13;
			}
			{
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:134>
				String_t* L_15 = V_0;
				String_t* L_16;
				L_16 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralBC755F9F3AD75230DD0DEEF00D323B0256FCDEC0)), L_15, NULL);
				InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_17 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
				InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_17, L_16, NULL);
				IL2CPP_RAISE_MANAGED_EXCEPTION(L_17, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&GameEntry_LoadDllBytes_m5D4614AFAEB0464FFA0DDCB52147F14BF8AF4D72_RuntimeMethod_var)));
			}

IL_0058_1:
			{
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:137>
				NullCheck(G_B5_0);
				ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_18;
				L_18 = TextAsset_get_bytes_m244B31755642C9623B570FC96B9A04523B1E5178(G_B5_0, NULL);
				V_2 = L_18;
				goto IL_006a;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_006a:
	{
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:143>
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_19 = V_2;
		return L_19;
	}
}
// Method Definition Index: 80681
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameEntry__ctor_mF3E2D2F725EDF1F57A59C278EF73AE75108BC4E4 (GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_m7F799D24C042923B6F560AF8FEA1CB00A1233888_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_t1BED237EBA2788604B1D39FC183B07E28F912A89_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:17>
		List_1_t1BED237EBA2788604B1D39FC183B07E28F912A89* L_0 = (List_1_t1BED237EBA2788604B1D39FC183B07E28F912A89*)il2cpp_codegen_object_new(List_1_t1BED237EBA2788604B1D39FC183B07E28F912A89_il2cpp_TypeInfo_var);
		List_1__ctor_m7F799D24C042923B6F560AF8FEA1CB00A1233888(L_0, List_1__ctor_m7F799D24C042923B6F560AF8FEA1CB00A1233888_RuntimeMethod_var);
		__this->____loadedHotfixAssemblies = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____loadedHotfixAssemblies), (void*)L_0);
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 80682
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CInitU3Ed__6_MoveNext_mDBDB72E5E93D5EB8DD159440DF156C801E5AD0AF (U3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AsyncUniTaskMethodBuilder_AwaitUnsafeOnCompleted_TisAwaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956_TisU3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129_m65DA9E32C2BB838DA1CBBC1C0B8BE7B25E64C11C_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IResourceManager_t2D98FEEEA5A917E1A722327BB77EB19BCF1432DC_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral30B46354175263168D67C65E9214DB098262BD73);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralB98479915536FE59BC4FFE29FD1D03106286ED6D);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralD63C2F074FC917A4CDBC16CCF627AA2E687765AB);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE* V_1 = NULL;
	Awaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956 V_2;
	memset((&V_2), 0, sizeof(V_2));
	UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270 V_3;
	memset((&V_3), 0, sizeof(V_3));
	Exception_t* V_4 = NULL;
	Exception_t* V_5 = NULL;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 2> __active_exceptions;
	{
		int32_t L_0 = __this->___U3CU3E1__state;
		V_0 = L_0;
		GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE* L_1 = __this->___U3CU3E4__this;
		V_1 = L_1;
	}
	try
	{
		{
			int32_t L_2 = V_0;
		}
		try
		{
			{
				int32_t L_3 = V_0;
				if (!L_3)
				{
					goto IL_0061_2;
				}
			}
			{
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:32>
				Log_Info_mE0A7D8A54E5A9315752D1B219753C5A29F40133C(_stringLiteral30B46354175263168D67C65E9214DB098262BD73, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:33>
				GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE* L_4 = V_1;
				NullCheck(L_4);
				RuntimeObject* L_5 = L_4->____resourceManager;
				NullCheck(L_5);
				UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270 L_6;
				L_6 = InterfaceFuncInvoker2< UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270, ResourceModeConfig_tA1EF1939CF0C50D62898DF0070094DD2D7928FA3*, RuntimeObject* >::Invoke(4, IResourceManager_t2D98FEEEA5A917E1A722327BB77EB19BCF1432DC_il2cpp_TypeInfo_var, L_5, (ResourceModeConfig_tA1EF1939CF0C50D62898DF0070094DD2D7928FA3*)NULL, (RuntimeObject*)NULL);
				V_3 = L_6;
				il2cpp_codegen_runtime_class_init_inline(UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270_il2cpp_TypeInfo_var);
				Awaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956 L_7;
				L_7 = UniTask_GetAwaiter_mF05A09B81913BECFD58FC67A16C0251FFCCAC939_inline((&V_3), NULL);
				V_2 = L_7;
				bool L_8;
				L_8 = Awaiter_get_IsCompleted_m2D01E3AB8A7C5AA8AA1E1EF58D92A6A095C00B9A_inline((&V_2), NULL);
				if (L_8)
				{
					goto IL_007d_2;
				}
			}
			{
				int32_t L_9 = 0;
				V_0 = L_9;
				__this->___U3CU3E1__state = L_9;
				Awaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956 L_10 = V_2;
				__this->___U3CU3Eu__1 = L_10;
				Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___U3CU3Eu__1))->___task))->___source), (void*)NULL);
				AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0* L_11 = (AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0*)(&__this->___U3CU3Et__builder);
				AsyncUniTaskMethodBuilder_AwaitUnsafeOnCompleted_TisAwaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956_TisU3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129_m65DA9E32C2BB838DA1CBBC1C0B8BE7B25E64C11C_inline(L_11, (&V_2), __this, AsyncUniTaskMethodBuilder_AwaitUnsafeOnCompleted_TisAwaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956_TisU3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129_m65DA9E32C2BB838DA1CBBC1C0B8BE7B25E64C11C_RuntimeMethod_var);
				goto IL_00f8;
			}

IL_0061_2:
			{
				Awaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956 L_12 = __this->___U3CU3Eu__1;
				V_2 = L_12;
				Awaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956* L_13 = (Awaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956*)(&__this->___U3CU3Eu__1);
				il2cpp_codegen_initobj(L_13, sizeof(Awaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956));
				int32_t L_14 = (-1);
				V_0 = L_14;
				__this->___U3CU3E1__state = L_14;
			}

IL_007d_2:
			{
				Awaiter_GetResult_mC439993563D3BD49CEC67AAF6AFB3AEF72E916BD_inline((&V_2), NULL);
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:34>
				Log_Info_mE0A7D8A54E5A9315752D1B219753C5A29F40133C(_stringLiteralD63C2F074FC917A4CDBC16CCF627AA2E687765AB, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:36>
				GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE* L_15 = V_1;
				NullCheck(L_15);
				GameEntry_LoadHotfixConfig_m184C10567CEBD6A56FFCABFE11081EFFBDD37CF1(L_15, NULL);
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:37>
				GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE* L_16 = V_1;
				NullCheck(L_16);
				GameEntry_LoadAotMetadataAssemblies_m23F4BBC7F91981546C4F89414DC062570B778399(L_16, NULL);
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:38>
				GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE* L_17 = V_1;
				NullCheck(L_17);
				GameEntry_LoadHotUpdateAssemblies_m74C1034D233B6F72CF14DAC74AED7C4ACC00E469(L_17, NULL);
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:39>
				GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE* L_18 = V_1;
				NullCheck(L_18);
				GameEntry_InvokeHotfixEntry_m4BB63989E22A673D5268F18D765639C89C593903(L_18, NULL);
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:41>
				Log_Info_mE0A7D8A54E5A9315752D1B219753C5A29F40133C(_stringLiteralB98479915536FE59BC4FFE29FD1D03106286ED6D, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
				//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:42>
				goto IL_00ca_1;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
			{
				IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
				goto CATCH_00b4_1;
			}
			throw e;
		}

CATCH_00b4_1:
		{
			Exception_t* L_19 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
			//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:43>
			V_4 = L_19;
			//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:45>
			Exception_t* L_20 = V_4;
			String_t* L_21;
			L_21 = String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC7327B9D39E1F3D24630F049ED40C3A22EE84057)), L_20, NULL);
			Log_Error_mD79843A05F9947233E3AE358E98C063B86895B53(L_21, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
			//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:46>
			IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
			goto IL_00ca_1;
		}

IL_00ca_1:
		{
			goto IL_00e5;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00cc;
		}
		throw e;
	}

CATCH_00cc:
	{
		Exception_t* L_22 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		V_5 = L_22;
		__this->___U3CU3E1__state = ((int32_t)-2);
		AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0* L_23 = (AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0*)(&__this->___U3CU3Et__builder);
		Exception_t* L_24 = V_5;
		AsyncUniTaskMethodBuilder_SetException_m0D772D62D01CC371F4AB0F6943BBBE0FEAB19643_inline(L_23, L_24, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00f8;
	}

IL_00e5:
	{
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/GameEntry.cs:47>
		__this->___U3CU3E1__state = ((int32_t)-2);
		AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0* L_25 = (AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0*)(&__this->___U3CU3Et__builder);
		AsyncUniTaskMethodBuilder_SetResult_mBBA527F0F21E04D65A269C0D02597CE5B2D1E9CB_inline(L_25, NULL);
	}

IL_00f8:
	{
		return;
	}
}
IL2CPP_EXTERN_C  void U3CInitU3Ed__6_MoveNext_mDBDB72E5E93D5EB8DD159440DF156C801E5AD0AF_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	U3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<U3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129*>(__this + _offset);
	U3CInitU3Ed__6_MoveNext_mDBDB72E5E93D5EB8DD159440DF156C801E5AD0AF(_thisAdjusted, method);
}
// Method Definition Index: 80683
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CInitU3Ed__6_SetStateMachine_mFFC8211380B6F39E9F897BE540C5E43CD03ED80C (U3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129* __this, RuntimeObject* ___0_stateMachine, const RuntimeMethod* method) 
{
	{
		AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0* L_0 = (AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0*)(&__this->___U3CU3Et__builder);
		RuntimeObject* L_1 = ___0_stateMachine;
		AsyncUniTaskMethodBuilder_SetStateMachine_m466E6779CB9DEC814C0A59E7766D95EC2C3268CF(L_0, L_1, NULL);
		return;
	}
}
IL2CPP_EXTERN_C  void U3CInitU3Ed__6_SetStateMachine_mFFC8211380B6F39E9F897BE540C5E43CD03ED80C_AdjustorThunk (RuntimeObject* __this, RuntimeObject* ___0_stateMachine, const RuntimeMethod* method)
{
	U3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<U3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129*>(__this + _offset);
	U3CInitU3Ed__6_SetStateMachine_mFFC8211380B6F39E9F897BE540C5E43CD03ED80C(_thisAdjusted, ___0_stateMachine, method);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 80684
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AOTGenericReferences_RefMethods_m17CF257D96D8BC2F232C4C1502905B792D17170C (AOTGenericReferences_t7B8F9CD83F1EE53810C6F841826105D9416EA7C1* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/HybridCLRGenerate/AOTGenericReferences.cs:68>
		return;
	}
}
// Method Definition Index: 80685
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AOTGenericReferences__ctor_m41CBD692FC9B521512E552575AFE7A385DEC71A6 (AOTGenericReferences_t7B8F9CD83F1EE53810C6F841826105D9416EA7C1* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
// Method Definition Index: 80686
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AOTGenericReferences__cctor_mA46BDC06A6577D725A2E5284A2A34C974CE65F68 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AOTGenericReferences_t7B8F9CD83F1EE53810C6F841826105D9416EA7C1_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mF10DB1D3CBB0B14215F0E4F8AB4934A1955E5351_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_mCA8DD57EAC70C2B5923DBB9D5A77CEAC22E7068E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0B34DFC38793BF0AF6DEA9A94F7CCB4150E999A6);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral3FFD62AED7E07D7CF72FD45AEB9373B7AC43D791);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralD49B73F5B4735001BCEBA5F02814D3AF0D14FDF2);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/HybridCLRGenerate/AOTGenericReferences.cs:6>
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/HybridCLRGenerate/AOTGenericReferences.cs:7>
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/HybridCLRGenerate/AOTGenericReferences.cs:8>
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/HybridCLRGenerate/AOTGenericReferences.cs:9>
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/HybridCLRGenerate/AOTGenericReferences.cs:10>
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/HybridCLRGenerate/AOTGenericReferences.cs:11>
		List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* L_0 = (List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD*)il2cpp_codegen_object_new(List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD_il2cpp_TypeInfo_var);
		List_1__ctor_mCA8DD57EAC70C2B5923DBB9D5A77CEAC22E7068E(L_0, List_1__ctor_mCA8DD57EAC70C2B5923DBB9D5A77CEAC22E7068E_RuntimeMethod_var);
		List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* L_1 = L_0;
		NullCheck(L_1);
		List_1_Add_mF10DB1D3CBB0B14215F0E4F8AB4934A1955E5351_inline(L_1, _stringLiteralD49B73F5B4735001BCEBA5F02814D3AF0D14FDF2, List_1_Add_mF10DB1D3CBB0B14215F0E4F8AB4934A1955E5351_RuntimeMethod_var);
		List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* L_2 = L_1;
		NullCheck(L_2);
		List_1_Add_mF10DB1D3CBB0B14215F0E4F8AB4934A1955E5351_inline(L_2, _stringLiteral3FFD62AED7E07D7CF72FD45AEB9373B7AC43D791, List_1_Add_mF10DB1D3CBB0B14215F0E4F8AB4934A1955E5351_RuntimeMethod_var);
		List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* L_3 = L_2;
		NullCheck(L_3);
		List_1_Add_mF10DB1D3CBB0B14215F0E4F8AB4934A1955E5351_inline(L_3, _stringLiteral0B34DFC38793BF0AF6DEA9A94F7CCB4150E999A6, List_1_Add_mF10DB1D3CBB0B14215F0E4F8AB4934A1955E5351_RuntimeMethod_var);
		((AOTGenericReferences_t7B8F9CD83F1EE53810C6F841826105D9416EA7C1_StaticFields*)il2cpp_codegen_static_fields_for(AOTGenericReferences_t7B8F9CD83F1EE53810C6F841826105D9416EA7C1_il2cpp_TypeInfo_var))->___PatchedAOTAssemblyList = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((AOTGenericReferences_t7B8F9CD83F1EE53810C6F841826105D9416EA7C1_StaticFields*)il2cpp_codegen_static_fields_for(AOTGenericReferences_t7B8F9CD83F1EE53810C6F841826105D9416EA7C1_il2cpp_TypeInfo_var))->___PatchedAOTAssemblyList), (void*)L_3);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 80687
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Readme__ctor_m69C325C4C171DCB0312B646A9034AA91EA8C39C6 (Readme_tE17B99201D0F52BD5727638AD3F41072A65B3BBB* __this, const RuntimeMethod* method) 
{
	{
		ScriptableObject__ctor_mD037FDB0B487295EA47F79A4DB1BF1846C9087FF(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 80688
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Section__ctor_m5F732533E4DFC0167D965E5F5DB332E46055399B (Section_t50C894D0A717C2368EBAAE5477D4E8626D0B5401* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 80689
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MonoScriptData_t8F50E352855B96FFFC1D9CB07EACC90C99D73A3E UnitySourceGeneratedAssemblyMonoScriptTypes_v1_Get_mBEB95BEB954BB63E9710BBC7AD5E78C4CB0A0033 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CPrivateImplementationDetailsU3E_t0F5473E849A5A5185A9F4C5246F0C32816C49FCA____22BF73DEE36321E969C3CB45397B37D9DAF8EF9643FEEC9781E187210B414FE9_FieldInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CPrivateImplementationDetailsU3E_t0F5473E849A5A5185A9F4C5246F0C32816C49FCA____FFCF93DEE207A03B9C747003659BB8BCAED1A2A78521B5C6B6B6BC5B63400A72_FieldInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	MonoScriptData_t8F50E352855B96FFFC1D9CB07EACC90C99D73A3E V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_initobj((&V_0), sizeof(MonoScriptData_t8F50E352855B96FFFC1D9CB07EACC90C99D73A3E));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)202));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = L_0;
		RuntimeFieldHandle_t6E4C45B6D2EA12FC99185805A7E77527899B25C5 L_2 = { reinterpret_cast<intptr_t> (U3CPrivateImplementationDetailsU3E_t0F5473E849A5A5185A9F4C5246F0C32816C49FCA____22BF73DEE36321E969C3CB45397B37D9DAF8EF9643FEEC9781E187210B414FE9_FieldInfo_var) };
		RuntimeHelpers_InitializeArray_m751372AA3F24FBF6DA9B9D687CBFA2DE436CAB9B((RuntimeArray*)L_1, L_2, NULL);
		(&V_0)->___FilePathsData = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&(&V_0)->___FilePathsData), (void*)L_1);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_3 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)99));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = L_3;
		RuntimeFieldHandle_t6E4C45B6D2EA12FC99185805A7E77527899B25C5 L_5 = { reinterpret_cast<intptr_t> (U3CPrivateImplementationDetailsU3E_t0F5473E849A5A5185A9F4C5246F0C32816C49FCA____FFCF93DEE207A03B9C747003659BB8BCAED1A2A78521B5C6B6B6BC5B63400A72_FieldInfo_var) };
		RuntimeHelpers_InitializeArray_m751372AA3F24FBF6DA9B9D687CBFA2DE436CAB9B((RuntimeArray*)L_4, L_5, NULL);
		(&V_0)->___TypesData = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&(&V_0)->___TypesData), (void*)L_4);
		(&V_0)->___TotalFiles = 4;
		(&V_0)->___TotalTypes = 5;
		(&V_0)->___IsEditorOnly = (bool)0;
		MonoScriptData_t8F50E352855B96FFFC1D9CB07EACC90C99D73A3E L_6 = V_0;
		return L_6;
	}
}
// Method Definition Index: 80690
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnitySourceGeneratedAssemblyMonoScriptTypes_v1__ctor_mE70FB23ACC1EA12ABC948AA22C2E78B2D0AA39B1 (UnitySourceGeneratedAssemblyMonoScriptTypes_v1_tC95F24D0C6E6B77389433852BB389F39C692926E* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C void MonoScriptData_t8F50E352855B96FFFC1D9CB07EACC90C99D73A3E_marshal_pinvoke(const MonoScriptData_t8F50E352855B96FFFC1D9CB07EACC90C99D73A3E& unmarshaled, MonoScriptData_t8F50E352855B96FFFC1D9CB07EACC90C99D73A3E_marshaled_pinvoke& marshaled)
{
	marshaled.___FilePathsData = il2cpp_codegen_com_marshal_safe_array(IL2CPP_VT_I1, unmarshaled.___FilePathsData);
	marshaled.___TypesData = il2cpp_codegen_com_marshal_safe_array(IL2CPP_VT_I1, unmarshaled.___TypesData);
	marshaled.___TotalTypes = unmarshaled.___TotalTypes;
	marshaled.___TotalFiles = unmarshaled.___TotalFiles;
	marshaled.___IsEditorOnly = static_cast<int32_t>(unmarshaled.___IsEditorOnly);
}
IL2CPP_EXTERN_C void MonoScriptData_t8F50E352855B96FFFC1D9CB07EACC90C99D73A3E_marshal_pinvoke_back(const MonoScriptData_t8F50E352855B96FFFC1D9CB07EACC90C99D73A3E_marshaled_pinvoke& marshaled, MonoScriptData_t8F50E352855B96FFFC1D9CB07EACC90C99D73A3E& unmarshaled)
{
	unmarshaled.___FilePathsData = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___FilePathsData);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___FilePathsData), (void*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___FilePathsData));
	unmarshaled.___TypesData = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___TypesData);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___TypesData), (void*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___TypesData));
	int32_t unmarshaledTotalTypes_temp_2 = 0;
	unmarshaledTotalTypes_temp_2 = marshaled.___TotalTypes;
	unmarshaled.___TotalTypes = unmarshaledTotalTypes_temp_2;
	int32_t unmarshaledTotalFiles_temp_3 = 0;
	unmarshaledTotalFiles_temp_3 = marshaled.___TotalFiles;
	unmarshaled.___TotalFiles = unmarshaledTotalFiles_temp_3;
	bool unmarshaledIsEditorOnly_temp_4 = false;
	unmarshaledIsEditorOnly_temp_4 = static_cast<bool>(marshaled.___IsEditorOnly);
	unmarshaled.___IsEditorOnly = unmarshaledIsEditorOnly_temp_4;
}
IL2CPP_EXTERN_C void MonoScriptData_t8F50E352855B96FFFC1D9CB07EACC90C99D73A3E_marshal_pinvoke_cleanup(MonoScriptData_t8F50E352855B96FFFC1D9CB07EACC90C99D73A3E_marshaled_pinvoke& marshaled)
{
	il2cpp_codegen_com_destroy_safe_array(marshaled.___FilePathsData);
	marshaled.___FilePathsData = NULL;
	il2cpp_codegen_com_destroy_safe_array(marshaled.___TypesData);
	marshaled.___TypesData = NULL;
}
IL2CPP_EXTERN_C void MonoScriptData_t8F50E352855B96FFFC1D9CB07EACC90C99D73A3E_marshal_com(const MonoScriptData_t8F50E352855B96FFFC1D9CB07EACC90C99D73A3E& unmarshaled, MonoScriptData_t8F50E352855B96FFFC1D9CB07EACC90C99D73A3E_marshaled_com& marshaled)
{
	marshaled.___FilePathsData = il2cpp_codegen_com_marshal_safe_array(IL2CPP_VT_I1, unmarshaled.___FilePathsData);
	marshaled.___TypesData = il2cpp_codegen_com_marshal_safe_array(IL2CPP_VT_I1, unmarshaled.___TypesData);
	marshaled.___TotalTypes = unmarshaled.___TotalTypes;
	marshaled.___TotalFiles = unmarshaled.___TotalFiles;
	marshaled.___IsEditorOnly = static_cast<int32_t>(unmarshaled.___IsEditorOnly);
}
IL2CPP_EXTERN_C void MonoScriptData_t8F50E352855B96FFFC1D9CB07EACC90C99D73A3E_marshal_com_back(const MonoScriptData_t8F50E352855B96FFFC1D9CB07EACC90C99D73A3E_marshaled_com& marshaled, MonoScriptData_t8F50E352855B96FFFC1D9CB07EACC90C99D73A3E& unmarshaled)
{
	unmarshaled.___FilePathsData = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___FilePathsData);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___FilePathsData), (void*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___FilePathsData));
	unmarshaled.___TypesData = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___TypesData);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___TypesData), (void*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___TypesData));
	int32_t unmarshaledTotalTypes_temp_2 = 0;
	unmarshaledTotalTypes_temp_2 = marshaled.___TotalTypes;
	unmarshaled.___TotalTypes = unmarshaledTotalTypes_temp_2;
	int32_t unmarshaledTotalFiles_temp_3 = 0;
	unmarshaledTotalFiles_temp_3 = marshaled.___TotalFiles;
	unmarshaled.___TotalFiles = unmarshaledTotalFiles_temp_3;
	bool unmarshaledIsEditorOnly_temp_4 = false;
	unmarshaledIsEditorOnly_temp_4 = static_cast<bool>(marshaled.___IsEditorOnly);
	unmarshaled.___IsEditorOnly = unmarshaledIsEditorOnly_temp_4;
}
IL2CPP_EXTERN_C void MonoScriptData_t8F50E352855B96FFFC1D9CB07EACC90C99D73A3E_marshal_com_cleanup(MonoScriptData_t8F50E352855B96FFFC1D9CB07EACC90C99D73A3E_marshaled_com& marshaled)
{
	il2cpp_codegen_com_destroy_safe_array(marshaled.___FilePathsData);
	marshaled.___FilePathsData = NULL;
	il2cpp_codegen_com_destroy_safe_array(marshaled.___TypesData);
	marshaled.___TypesData = NULL;
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 80691
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* HotFixConfig_GetAllDlls_m9C9B96DFA33BCC9345E93762654CB216D38B3443 (HotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_AddRange_m157DD7AD4D25423F82A21E533BC4686C83770D5E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_mCA8DD57EAC70C2B5923DBB9D5A77CEAC22E7068E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/HotFixConfig.cs:35>
		List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* L_0 = (List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD*)il2cpp_codegen_object_new(List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD_il2cpp_TypeInfo_var);
		List_1__ctor_mCA8DD57EAC70C2B5923DBB9D5A77CEAC22E7068E(L_0, List_1__ctor_mCA8DD57EAC70C2B5923DBB9D5A77CEAC22E7068E_RuntimeMethod_var);
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/HotFixConfig.cs:36>
		List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* L_1 = L_0;
		List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* L_2 = __this->___hotFixDlls;
		NullCheck(L_1);
		List_1_AddRange_m157DD7AD4D25423F82A21E533BC4686C83770D5E(L_1, L_2, List_1_AddRange_m157DD7AD4D25423F82A21E533BC4686C83770D5E_RuntimeMethod_var);
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/HotFixConfig.cs:37>
		List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* L_3 = L_1;
		List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* L_4 = __this->___aotMetaDlls;
		NullCheck(L_3);
		List_1_AddRange_m157DD7AD4D25423F82A21E533BC4686C83770D5E(L_3, L_4, List_1_AddRange_m157DD7AD4D25423F82A21E533BC4686C83770D5E_RuntimeMethod_var);
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/HotFixConfig.cs:38>
		return L_3;
	}
}
// Method Definition Index: 80692
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HotFixConfig__ctor_m88C9FEE20BEFF6CB59D8D5D74933828283DDCFD8 (HotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mF10DB1D3CBB0B14215F0E4F8AB4934A1955E5351_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_mCA8DD57EAC70C2B5923DBB9D5A77CEAC22E7068E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0B34DFC38793BF0AF6DEA9A94F7CCB4150E999A6);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral2B07CB990D04DEF87288EEED87550482A1FE697C);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral4FE0A0ADA342BA701A04297D4C3D586C20AEFC03);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral55742341917859E61CC59E693B0B34D9F20DD7D4);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral8340619A905949B4B4F774604D29107ECCAA42E3);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral946BD80B231F5776B5307B385889C9ABB57D3D53);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralA3F029047BA90CC134023587DF7DCF444B38D009);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralCBE317BE7D6A370B9E6FAB97110F085335AB682E);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralD49B73F5B4735001BCEBA5F02814D3AF0D14FDF2);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/HotFixConfig.cs:11>
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/HotFixConfig.cs:12>
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/HotFixConfig.cs:13>
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/HotFixConfig.cs:14>
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/HotFixConfig.cs:15>
		List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* L_0 = (List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD*)il2cpp_codegen_object_new(List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD_il2cpp_TypeInfo_var);
		List_1__ctor_mCA8DD57EAC70C2B5923DBB9D5A77CEAC22E7068E(L_0, List_1__ctor_mCA8DD57EAC70C2B5923DBB9D5A77CEAC22E7068E_RuntimeMethod_var);
		List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* L_1 = L_0;
		NullCheck(L_1);
		List_1_Add_mF10DB1D3CBB0B14215F0E4F8AB4934A1955E5351_inline(L_1, _stringLiteralCBE317BE7D6A370B9E6FAB97110F085335AB682E, List_1_Add_mF10DB1D3CBB0B14215F0E4F8AB4934A1955E5351_RuntimeMethod_var);
		List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* L_2 = L_1;
		NullCheck(L_2);
		List_1_Add_mF10DB1D3CBB0B14215F0E4F8AB4934A1955E5351_inline(L_2, _stringLiteral4FE0A0ADA342BA701A04297D4C3D586C20AEFC03, List_1_Add_mF10DB1D3CBB0B14215F0E4F8AB4934A1955E5351_RuntimeMethod_var);
		__this->___hotFixDlls = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___hotFixDlls), (void*)L_2);
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/HotFixConfig.cs:19>
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/HotFixConfig.cs:20>
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/HotFixConfig.cs:21>
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/HotFixConfig.cs:22>
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/HotFixConfig.cs:23>
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/HotFixConfig.cs:24>
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/HotFixConfig.cs:25>
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/HotFixConfig.cs:26>
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/HotFixConfig.cs:27>
		//<source_info:D:/UnityGame/Self/EasyFramework/UnityProject/Assets/GameScripts/Runtime/HotFixConfig.cs:28>
		List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* L_3 = (List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD*)il2cpp_codegen_object_new(List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD_il2cpp_TypeInfo_var);
		List_1__ctor_mCA8DD57EAC70C2B5923DBB9D5A77CEAC22E7068E(L_3, List_1__ctor_mCA8DD57EAC70C2B5923DBB9D5A77CEAC22E7068E_RuntimeMethod_var);
		List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* L_4 = L_3;
		NullCheck(L_4);
		List_1_Add_mF10DB1D3CBB0B14215F0E4F8AB4934A1955E5351_inline(L_4, _stringLiteral0B34DFC38793BF0AF6DEA9A94F7CCB4150E999A6, List_1_Add_mF10DB1D3CBB0B14215F0E4F8AB4934A1955E5351_RuntimeMethod_var);
		List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* L_5 = L_4;
		NullCheck(L_5);
		List_1_Add_mF10DB1D3CBB0B14215F0E4F8AB4934A1955E5351_inline(L_5, _stringLiteralA3F029047BA90CC134023587DF7DCF444B38D009, List_1_Add_mF10DB1D3CBB0B14215F0E4F8AB4934A1955E5351_RuntimeMethod_var);
		List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* L_6 = L_5;
		NullCheck(L_6);
		List_1_Add_mF10DB1D3CBB0B14215F0E4F8AB4934A1955E5351_inline(L_6, _stringLiteral946BD80B231F5776B5307B385889C9ABB57D3D53, List_1_Add_mF10DB1D3CBB0B14215F0E4F8AB4934A1955E5351_RuntimeMethod_var);
		List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* L_7 = L_6;
		NullCheck(L_7);
		List_1_Add_mF10DB1D3CBB0B14215F0E4F8AB4934A1955E5351_inline(L_7, _stringLiteral8340619A905949B4B4F774604D29107ECCAA42E3, List_1_Add_mF10DB1D3CBB0B14215F0E4F8AB4934A1955E5351_RuntimeMethod_var);
		List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* L_8 = L_7;
		NullCheck(L_8);
		List_1_Add_mF10DB1D3CBB0B14215F0E4F8AB4934A1955E5351_inline(L_8, _stringLiteral55742341917859E61CC59E693B0B34D9F20DD7D4, List_1_Add_mF10DB1D3CBB0B14215F0E4F8AB4934A1955E5351_RuntimeMethod_var);
		List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* L_9 = L_8;
		NullCheck(L_9);
		List_1_Add_mF10DB1D3CBB0B14215F0E4F8AB4934A1955E5351_inline(L_9, _stringLiteralD49B73F5B4735001BCEBA5F02814D3AF0D14FDF2, List_1_Add_mF10DB1D3CBB0B14215F0E4F8AB4934A1955E5351_RuntimeMethod_var);
		List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* L_10 = L_9;
		NullCheck(L_10);
		List_1_Add_mF10DB1D3CBB0B14215F0E4F8AB4934A1955E5351_inline(L_10, _stringLiteral2B07CB990D04DEF87288EEED87550482A1FE697C, List_1_Add_mF10DB1D3CBB0B14215F0E4F8AB4934A1955E5351_RuntimeMethod_var);
		__this->___aotMetaDlls = L_10;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___aotMetaDlls), (void*)L_10);
		ScriptableObject__ctor_mD037FDB0B487295EA47F79A4DB1BF1846C9087FF(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 80693
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AssemblyTypeRegistry__cctor_mAEB8E544765736377C7DE10C527674CD04E25439 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AOTGenericReferences_t7B8F9CD83F1EE53810C6F841826105D9416EA7C1_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssemblyTypeRegistry_BoxedGetHashCode_m51ABF56CB30C28866F9A1DD99686EE8FA066AA35_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssemblyTypeRegistry_Equals_m2A29416EF4DF96A3C8653EE9A5FD28D0F832888F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssemblyTypeRegistry_Equals_mC6FB3A844339CB7C644AD24D982A88DA1EFFE98D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssemblyTypeRegistry_GetSystemAttributes_m745ECC27B9E20AA200CFB281D28E3A2F9C2E2C3C_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssemblyTypeRegistry_SetSharedStaticTypeIndices_m3DE4774BFFA0B87DE6BB2678A9C2737686BF6917_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssemblyTypeRegistry_t38B36581EF406EB04A8CF7356B90E396D2EA34E5_StaticFields____Value0_RVAStorage);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssemblyTypeRegistry_t38B36581EF406EB04A8CF7356B90E396D2EA34E5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BoxedGetHashCodeFn_t6FB594B3729237028A914FC35892E11F35EBD7A5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GetBoxedEqualsFn_t1D3C86605A3BC070552B06B6F9C34588CB8BEA01_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GetBoxedEqualsPtrFn_t1902DF962742BD42AEC0802E437C41F357FC251C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GetSystemAttributesFn_tFF3291428917181EF9DA36D06C3155DE423D30AA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int64U5BU5D_tAEDFCBDB5414E2A140A6F34C0538BF97FCF67A1D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Readme_tE17B99201D0F52BD5727638AD3F41072A65B3BBB_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SetSharedTypeIndicesFn_t42DEBDCE57DA612BDBCC2CD1C7C6969F77858C0C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral12B9EDD4E3C69EC048F22E3E86D8D681E8ED7990);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1F1133B46379B1B74780C17A916B994A3A4AAC57);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral8097DA92B2FFC0CA2B1A7C337AFC83A6F765A072);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral977A71115E05B54B449539D8B6701AE4DAD2B1BE);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralB395EFD0354E31FE0F76908F4BE2E5A165319042);
		s_Il2CppMethodInitialized = true;
	}
	TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7* V_0 = NULL;
	{
		TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7* L_0 = (TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7*)il2cpp_codegen_object_new(TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7_il2cpp_TypeInfo_var);
		TypeRegistry__ctor_mA659C5403A2DC55AF2ACB47255F4D100B90D2A7F(L_0, NULL);
		V_0 = L_0;
		TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7* L_1 = V_0;
		NullCheck(L_1);
		L_1->___AssemblyName = _stringLiteral977A71115E05B54B449539D8B6701AE4DAD2B1BE;
		Il2CppCodeGenWriteBarrier((void**)(&L_1->___AssemblyName), (void*)_stringLiteral977A71115E05B54B449539D8B6701AE4DAD2B1BE);
		TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7* L_2 = V_0;
		NullCheck(L_2);
		L_2->___TypeInfosPtr = (TypeInfo_tD43B08A8D19156EEC98399693A96161F02139654*)((ConstantData0_t1F10138848E6A6434DF07663E3F6D55A4BAB7F40*)AssemblyTypeRegistry_t38B36581EF406EB04A8CF7356B90E396D2EA34E5_StaticFields____Value0_RVAStorage);
		TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7* L_3 = V_0;
		NullCheck(L_3);
		L_3->___TypeInfosCount = ((int32_t)4);
		TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7* L_4 = V_0;
		TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* L_5 = (TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB*)(TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB*)SZArrayNew(TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB_il2cpp_TypeInfo_var, (uint32_t)4);
		TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* L_6 = L_5;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_7 = { reinterpret_cast<intptr_t> (GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_8;
		L_8 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_7, NULL);
		NullCheck(L_6);
		ArrayElementTypeCheck (L_6, L_8);
		(L_6)->SetAt(static_cast<il2cpp_array_size_t>(0), (Type_t*)L_8);
		TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* L_9 = L_6;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_10 = { reinterpret_cast<intptr_t> (AOTGenericReferences_t7B8F9CD83F1EE53810C6F841826105D9416EA7C1_0_0_0_var) };
		Type_t* L_11;
		L_11 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_10, NULL);
		NullCheck(L_9);
		ArrayElementTypeCheck (L_9, L_11);
		(L_9)->SetAt(static_cast<il2cpp_array_size_t>(1), (Type_t*)L_11);
		TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* L_12 = L_9;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_13 = { reinterpret_cast<intptr_t> (Readme_tE17B99201D0F52BD5727638AD3F41072A65B3BBB_0_0_0_var) };
		Type_t* L_14;
		L_14 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_13, NULL);
		NullCheck(L_12);
		ArrayElementTypeCheck (L_12, L_14);
		(L_12)->SetAt(static_cast<il2cpp_array_size_t>(2), (Type_t*)L_14);
		TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* L_15 = L_12;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_16 = { reinterpret_cast<intptr_t> (HotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016_0_0_0_var) };
		Type_t* L_17;
		L_17 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_16, NULL);
		NullCheck(L_15);
		ArrayElementTypeCheck (L_15, L_17);
		(L_15)->SetAt(static_cast<il2cpp_array_size_t>(3), (Type_t*)L_17);
		NullCheck(L_4);
		L_4->___Types = L_15;
		Il2CppCodeGenWriteBarrier((void**)(&L_4->___Types), (void*)L_15);
		TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7* L_18 = V_0;
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_19 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)4);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_20 = L_19;
		NullCheck(L_20);
		(L_20)->SetAt(static_cast<il2cpp_array_size_t>(0), (String_t*)_stringLiteral1F1133B46379B1B74780C17A916B994A3A4AAC57);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_21 = L_20;
		NullCheck(L_21);
		(L_21)->SetAt(static_cast<il2cpp_array_size_t>(1), (String_t*)_stringLiteral12B9EDD4E3C69EC048F22E3E86D8D681E8ED7990);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_22 = L_21;
		NullCheck(L_22);
		(L_22)->SetAt(static_cast<il2cpp_array_size_t>(2), (String_t*)_stringLiteralB395EFD0354E31FE0F76908F4BE2E5A165319042);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_23 = L_22;
		NullCheck(L_23);
		(L_23)->SetAt(static_cast<il2cpp_array_size_t>(3), (String_t*)_stringLiteral8097DA92B2FFC0CA2B1A7C337AFC83A6F765A072);
		NullCheck(L_18);
		L_18->___TypeNames = L_23;
		Il2CppCodeGenWriteBarrier((void**)(&L_18->___TypeNames), (void*)L_23);
		TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7* L_24 = V_0;
		NullCheck(L_24);
		L_24->___EntityOffsetsPtr = (int32_t*)((uintptr_t)0);
		TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7* L_25 = V_0;
		NullCheck(L_25);
		L_25->___EntityOffsetsCount = ((int32_t)0);
		TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7* L_26 = V_0;
		NullCheck(L_26);
		L_26->___BlobAssetReferenceOffsetsPtr = (int32_t*)((uintptr_t)0);
		TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7* L_27 = V_0;
		NullCheck(L_27);
		L_27->___BlobAssetReferenceOffsetsCount = ((int32_t)0);
		TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7* L_28 = V_0;
		NullCheck(L_28);
		L_28->___UnityObjectReferenceOffsetsPtr = (int32_t*)((uintptr_t)0);
		TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7* L_29 = V_0;
		NullCheck(L_29);
		L_29->___UnityObjectReferenceOffsetsCount = ((int32_t)0);
		TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7* L_30 = V_0;
		NullCheck(L_30);
		L_30->___WeakAssetReferenceOffsetsPtr = (int32_t*)((uintptr_t)0);
		TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7* L_31 = V_0;
		NullCheck(L_31);
		L_31->___WeakAssetReferenceOffsetsCount = ((int32_t)0);
		TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7* L_32 = V_0;
		TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* L_33 = (TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB*)(TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB*)SZArrayNew(TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB_il2cpp_TypeInfo_var, (uint32_t)0);
		NullCheck(L_32);
		L_32->___WriteGroups = L_33;
		Il2CppCodeGenWriteBarrier((void**)(&L_32->___WriteGroups), (void*)L_33);
		TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7* L_34 = V_0;
		TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* L_35 = (TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB*)(TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB*)SZArrayNew(TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB_il2cpp_TypeInfo_var, (uint32_t)0);
		NullCheck(L_34);
		L_34->___SystemTypes = L_35;
		Il2CppCodeGenWriteBarrier((void**)(&L_34->___SystemTypes), (void*)L_35);
		TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7* L_36 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_37 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)0);
		NullCheck(L_36);
		L_36->___SystemFilterFlags = (WorldSystemFilterFlagsU5BU5D_t434BBC7E739D7E01D618B9C6A685B473CB24F9CC*)L_37;
		Il2CppCodeGenWriteBarrier((void**)(&L_36->___SystemFilterFlags), (void*)(WorldSystemFilterFlagsU5BU5D_t434BBC7E739D7E01D618B9C6A685B473CB24F9CC*)L_37);
		TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7* L_38 = V_0;
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_39 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)0);
		NullCheck(L_38);
		L_38->___SystemTypeNames = L_39;
		Il2CppCodeGenWriteBarrier((void**)(&L_38->___SystemTypeNames), (void*)L_39);
		TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7* L_40 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_41 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)0);
		NullCheck(L_40);
		L_40->___SystemTypeSizes = L_41;
		Il2CppCodeGenWriteBarrier((void**)(&L_40->___SystemTypeSizes), (void*)L_41);
		TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7* L_42 = V_0;
		Int64U5BU5D_tAEDFCBDB5414E2A140A6F34C0538BF97FCF67A1D* L_43 = (Int64U5BU5D_tAEDFCBDB5414E2A140A6F34C0538BF97FCF67A1D*)(Int64U5BU5D_tAEDFCBDB5414E2A140A6F34C0538BF97FCF67A1D*)SZArrayNew(Int64U5BU5D_tAEDFCBDB5414E2A140A6F34C0538BF97FCF67A1D_il2cpp_TypeInfo_var, (uint32_t)0);
		NullCheck(L_42);
		L_42->___SystemTypeHashes = L_43;
		Il2CppCodeGenWriteBarrier((void**)(&L_42->___SystemTypeHashes), (void*)L_43);
		TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7* L_44 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_45 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)0);
		NullCheck(L_44);
		L_44->___SystemTypeFlags = L_45;
		Il2CppCodeGenWriteBarrier((void**)(&L_44->___SystemTypeFlags), (void*)L_45);
		TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7* L_46 = V_0;
		GetBoxedEqualsFn_t1D3C86605A3BC070552B06B6F9C34588CB8BEA01* L_47 = (GetBoxedEqualsFn_t1D3C86605A3BC070552B06B6F9C34588CB8BEA01*)il2cpp_codegen_object_new(GetBoxedEqualsFn_t1D3C86605A3BC070552B06B6F9C34588CB8BEA01_il2cpp_TypeInfo_var);
		GetBoxedEqualsFn__ctor_mDC463EBA3EBEC465257344D7779A256962EB2FC5(L_47, NULL, (intptr_t)((void*)AssemblyTypeRegistry_Equals_mC6FB3A844339CB7C644AD24D982A88DA1EFFE98D_RuntimeMethod_var), NULL);
		NullCheck(L_46);
		L_46->___BoxedEquals = L_47;
		Il2CppCodeGenWriteBarrier((void**)(&L_46->___BoxedEquals), (void*)L_47);
		TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7* L_48 = V_0;
		GetBoxedEqualsPtrFn_t1902DF962742BD42AEC0802E437C41F357FC251C* L_49 = (GetBoxedEqualsPtrFn_t1902DF962742BD42AEC0802E437C41F357FC251C*)il2cpp_codegen_object_new(GetBoxedEqualsPtrFn_t1902DF962742BD42AEC0802E437C41F357FC251C_il2cpp_TypeInfo_var);
		GetBoxedEqualsPtrFn__ctor_m3EAE6EFF779D92AB28B639EC0B511AD2CBC273B3(L_49, NULL, (intptr_t)((void*)AssemblyTypeRegistry_Equals_m2A29416EF4DF96A3C8653EE9A5FD28D0F832888F_RuntimeMethod_var), NULL);
		NullCheck(L_48);
		L_48->___BoxedEqualsPtr = L_49;
		Il2CppCodeGenWriteBarrier((void**)(&L_48->___BoxedEqualsPtr), (void*)L_49);
		TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7* L_50 = V_0;
		BoxedGetHashCodeFn_t6FB594B3729237028A914FC35892E11F35EBD7A5* L_51 = (BoxedGetHashCodeFn_t6FB594B3729237028A914FC35892E11F35EBD7A5*)il2cpp_codegen_object_new(BoxedGetHashCodeFn_t6FB594B3729237028A914FC35892E11F35EBD7A5_il2cpp_TypeInfo_var);
		BoxedGetHashCodeFn__ctor_m17A49B9995CCAA53F90B4495B325F011B5EC4E60(L_51, NULL, (intptr_t)((void*)AssemblyTypeRegistry_BoxedGetHashCode_m51ABF56CB30C28866F9A1DD99686EE8FA066AA35_RuntimeMethod_var), NULL);
		NullCheck(L_50);
		L_50->___BoxedGetHashCode = L_51;
		Il2CppCodeGenWriteBarrier((void**)(&L_50->___BoxedGetHashCode), (void*)L_51);
		TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7* L_52 = V_0;
		GetSystemAttributesFn_tFF3291428917181EF9DA36D06C3155DE423D30AA* L_53 = (GetSystemAttributesFn_tFF3291428917181EF9DA36D06C3155DE423D30AA*)il2cpp_codegen_object_new(GetSystemAttributesFn_tFF3291428917181EF9DA36D06C3155DE423D30AA_il2cpp_TypeInfo_var);
		GetSystemAttributesFn__ctor_m9236C825F0DFD0303926C0D730374EDCA453609F(L_53, NULL, (intptr_t)((void*)AssemblyTypeRegistry_GetSystemAttributes_m745ECC27B9E20AA200CFB281D28E3A2F9C2E2C3C_RuntimeMethod_var), NULL);
		NullCheck(L_52);
		L_52->___GetSystemAttributes = L_53;
		Il2CppCodeGenWriteBarrier((void**)(&L_52->___GetSystemAttributes), (void*)L_53);
		TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7* L_54 = V_0;
		SetSharedTypeIndicesFn_t42DEBDCE57DA612BDBCC2CD1C7C6969F77858C0C* L_55 = (SetSharedTypeIndicesFn_t42DEBDCE57DA612BDBCC2CD1C7C6969F77858C0C*)il2cpp_codegen_object_new(SetSharedTypeIndicesFn_t42DEBDCE57DA612BDBCC2CD1C7C6969F77858C0C_il2cpp_TypeInfo_var);
		SetSharedTypeIndicesFn__ctor_m7C4E8AE7DC32AE4374058368A031F75266CD3F00(L_55, NULL, (intptr_t)((void*)AssemblyTypeRegistry_SetSharedStaticTypeIndices_m3DE4774BFFA0B87DE6BB2678A9C2737686BF6917_RuntimeMethod_var), NULL);
		NullCheck(L_54);
		L_54->___SetSharedTypeIndices = L_55;
		Il2CppCodeGenWriteBarrier((void**)(&L_54->___SetSharedTypeIndices), (void*)L_55);
		TypeRegistry_t7D7A11622D1BDE858376298E1F6822CF06F57FB7* L_56 = V_0;
		((AssemblyTypeRegistry_t38B36581EF406EB04A8CF7356B90E396D2EA34E5_StaticFields*)il2cpp_codegen_static_fields_for(AssemblyTypeRegistry_t38B36581EF406EB04A8CF7356B90E396D2EA34E5_il2cpp_TypeInfo_var))->___TypeRegistry = L_56;
		Il2CppCodeGenWriteBarrier((void**)(&((AssemblyTypeRegistry_t38B36581EF406EB04A8CF7356B90E396D2EA34E5_StaticFields*)il2cpp_codegen_static_fields_for(AssemblyTypeRegistry_t38B36581EF406EB04A8CF7356B90E396D2EA34E5_il2cpp_TypeInfo_var))->___TypeRegistry), (void*)L_56);
		return;
	}
}
// Method Definition Index: 80694
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool AssemblyTypeRegistry_Equals_mC6FB3A844339CB7C644AD24D982A88DA1EFFE98D (RuntimeObject* ___0_lhs, RuntimeObject* ___1_rhs, int32_t ___2_typeIndex, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AOTGenericReferences_t7B8F9CD83F1EE53810C6F841826105D9416EA7C1_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Readme_tE17B99201D0F52BD5727638AD3F41072A65B3BBB_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		int32_t L_0 = ___2_typeIndex;
		switch (L_0)
		{
			case 0:
			{
				goto IL_001b;
			}
			case 1:
			{
				goto IL_0039;
			}
			case 2:
			{
				goto IL_0057;
			}
			case 3:
			{
				goto IL_0075;
			}
		}
	}
	{
		goto IL_0093;
	}

IL_001b:
	{
		RuntimeObject* L_1 = ___0_lhs;
		RuntimeObject* L_2 = ___1_rhs;
		int32_t L_3;
		L_3 = UnsafeUtility_MemCmp_mA0E0E1A93F715105E7B576F1603DCAB37717A5EF((void*)((GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE**)UnBox(L_1, GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE_il2cpp_TypeInfo_var)), (void*)((GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE**)UnBox(L_2, GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE_il2cpp_TypeInfo_var)), ((int64_t)0LL), NULL);
		return (bool)((((int32_t)L_3) == ((int32_t)0))? 1 : 0);
	}

IL_0039:
	{
		RuntimeObject* L_4 = ___0_lhs;
		RuntimeObject* L_5 = ___1_rhs;
		int32_t L_6;
		L_6 = UnsafeUtility_MemCmp_mA0E0E1A93F715105E7B576F1603DCAB37717A5EF((void*)((AOTGenericReferences_t7B8F9CD83F1EE53810C6F841826105D9416EA7C1**)UnBox(L_4, AOTGenericReferences_t7B8F9CD83F1EE53810C6F841826105D9416EA7C1_il2cpp_TypeInfo_var)), (void*)((AOTGenericReferences_t7B8F9CD83F1EE53810C6F841826105D9416EA7C1**)UnBox(L_5, AOTGenericReferences_t7B8F9CD83F1EE53810C6F841826105D9416EA7C1_il2cpp_TypeInfo_var)), ((int64_t)0LL), NULL);
		return (bool)((((int32_t)L_6) == ((int32_t)0))? 1 : 0);
	}

IL_0057:
	{
		RuntimeObject* L_7 = ___0_lhs;
		RuntimeObject* L_8 = ___1_rhs;
		int32_t L_9;
		L_9 = UnsafeUtility_MemCmp_mA0E0E1A93F715105E7B576F1603DCAB37717A5EF((void*)((Readme_tE17B99201D0F52BD5727638AD3F41072A65B3BBB**)UnBox(L_7, Readme_tE17B99201D0F52BD5727638AD3F41072A65B3BBB_il2cpp_TypeInfo_var)), (void*)((Readme_tE17B99201D0F52BD5727638AD3F41072A65B3BBB**)UnBox(L_8, Readme_tE17B99201D0F52BD5727638AD3F41072A65B3BBB_il2cpp_TypeInfo_var)), ((int64_t)0LL), NULL);
		return (bool)((((int32_t)L_9) == ((int32_t)0))? 1 : 0);
	}

IL_0075:
	{
		RuntimeObject* L_10 = ___0_lhs;
		RuntimeObject* L_11 = ___1_rhs;
		int32_t L_12;
		L_12 = UnsafeUtility_MemCmp_mA0E0E1A93F715105E7B576F1603DCAB37717A5EF((void*)((HotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016**)UnBox(L_10, HotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016_il2cpp_TypeInfo_var)), (void*)((HotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016**)UnBox(L_11, HotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016_il2cpp_TypeInfo_var)), ((int64_t)0LL), NULL);
		return (bool)((((int32_t)L_12) == ((int32_t)0))? 1 : 0);
	}

IL_0093:
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_13 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_13, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral065A4520058461C386BC1A37D15716A5905D9F63)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_13, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&AssemblyTypeRegistry_Equals_mC6FB3A844339CB7C644AD24D982A88DA1EFFE98D_RuntimeMethod_var)));
	}
}
// Method Definition Index: 80695
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool AssemblyTypeRegistry_Equals_m2A29416EF4DF96A3C8653EE9A5FD28D0F832888F (RuntimeObject* ___0_lhs, void* ___1_rhs, int32_t ___2_typeIndex, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AOTGenericReferences_t7B8F9CD83F1EE53810C6F841826105D9416EA7C1_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Readme_tE17B99201D0F52BD5727638AD3F41072A65B3BBB_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		int32_t L_0 = ___2_typeIndex;
		switch (L_0)
		{
			case 0:
			{
				goto IL_001b;
			}
			case 1:
			{
				goto IL_0034;
			}
			case 2:
			{
				goto IL_004d;
			}
			case 3:
			{
				goto IL_0066;
			}
		}
	}
	{
		goto IL_007f;
	}

IL_001b:
	{
		RuntimeObject* L_1 = ___0_lhs;
		void* L_2 = ___1_rhs;
		int32_t L_3;
		L_3 = UnsafeUtility_MemCmp_mA0E0E1A93F715105E7B576F1603DCAB37717A5EF((void*)((GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE**)UnBox(L_1, GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE_il2cpp_TypeInfo_var)), L_2, ((int64_t)0LL), NULL);
		return (bool)((((int32_t)L_3) == ((int32_t)0))? 1 : 0);
	}

IL_0034:
	{
		RuntimeObject* L_4 = ___0_lhs;
		void* L_5 = ___1_rhs;
		int32_t L_6;
		L_6 = UnsafeUtility_MemCmp_mA0E0E1A93F715105E7B576F1603DCAB37717A5EF((void*)((AOTGenericReferences_t7B8F9CD83F1EE53810C6F841826105D9416EA7C1**)UnBox(L_4, AOTGenericReferences_t7B8F9CD83F1EE53810C6F841826105D9416EA7C1_il2cpp_TypeInfo_var)), L_5, ((int64_t)0LL), NULL);
		return (bool)((((int32_t)L_6) == ((int32_t)0))? 1 : 0);
	}

IL_004d:
	{
		RuntimeObject* L_7 = ___0_lhs;
		void* L_8 = ___1_rhs;
		int32_t L_9;
		L_9 = UnsafeUtility_MemCmp_mA0E0E1A93F715105E7B576F1603DCAB37717A5EF((void*)((Readme_tE17B99201D0F52BD5727638AD3F41072A65B3BBB**)UnBox(L_7, Readme_tE17B99201D0F52BD5727638AD3F41072A65B3BBB_il2cpp_TypeInfo_var)), L_8, ((int64_t)0LL), NULL);
		return (bool)((((int32_t)L_9) == ((int32_t)0))? 1 : 0);
	}

IL_0066:
	{
		RuntimeObject* L_10 = ___0_lhs;
		void* L_11 = ___1_rhs;
		int32_t L_12;
		L_12 = UnsafeUtility_MemCmp_mA0E0E1A93F715105E7B576F1603DCAB37717A5EF((void*)((HotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016**)UnBox(L_10, HotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016_il2cpp_TypeInfo_var)), L_11, ((int64_t)0LL), NULL);
		return (bool)((((int32_t)L_12) == ((int32_t)0))? 1 : 0);
	}

IL_007f:
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_13 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_13, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral065A4520058461C386BC1A37D15716A5905D9F63)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_13, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&AssemblyTypeRegistry_Equals_m2A29416EF4DF96A3C8653EE9A5FD28D0F832888F_RuntimeMethod_var)));
	}
}
// Method Definition Index: 80696
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t AssemblyTypeRegistry_BoxedGetHashCode_m51ABF56CB30C28866F9A1DD99686EE8FA066AA35 (RuntimeObject* ___0_val, int32_t ___1_typeIndex, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AOTGenericReferences_t7B8F9CD83F1EE53810C6F841826105D9416EA7C1_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Readme_tE17B99201D0F52BD5727638AD3F41072A65B3BBB_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		int32_t L_0 = ___1_typeIndex;
		switch (L_0)
		{
			case 0:
			{
				goto IL_001b;
			}
			case 1:
			{
				goto IL_002d;
			}
			case 2:
			{
				goto IL_003f;
			}
			case 3:
			{
				goto IL_0051;
			}
		}
	}
	{
		goto IL_0063;
	}

IL_001b:
	{
		RuntimeObject* L_1 = ___0_val;
		uint32_t L_2;
		L_2 = XXHash_Hash32_mCA5C9D8E9CBF5556CB85DC6C9847152A6C658FC1((uint8_t*)((GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE**)UnBox(L_1, GameEntry_tC78C4E3FAE9BB0B134A5BF963AE6A8B96ACB34AE_il2cpp_TypeInfo_var)), ((int32_t)0), 0, NULL);
		return L_2;
	}

IL_002d:
	{
		RuntimeObject* L_3 = ___0_val;
		uint32_t L_4;
		L_4 = XXHash_Hash32_mCA5C9D8E9CBF5556CB85DC6C9847152A6C658FC1((uint8_t*)((AOTGenericReferences_t7B8F9CD83F1EE53810C6F841826105D9416EA7C1**)UnBox(L_3, AOTGenericReferences_t7B8F9CD83F1EE53810C6F841826105D9416EA7C1_il2cpp_TypeInfo_var)), ((int32_t)0), 0, NULL);
		return L_4;
	}

IL_003f:
	{
		RuntimeObject* L_5 = ___0_val;
		uint32_t L_6;
		L_6 = XXHash_Hash32_mCA5C9D8E9CBF5556CB85DC6C9847152A6C658FC1((uint8_t*)((Readme_tE17B99201D0F52BD5727638AD3F41072A65B3BBB**)UnBox(L_5, Readme_tE17B99201D0F52BD5727638AD3F41072A65B3BBB_il2cpp_TypeInfo_var)), ((int32_t)0), 0, NULL);
		return L_6;
	}

IL_0051:
	{
		RuntimeObject* L_7 = ___0_val;
		uint32_t L_8;
		L_8 = XXHash_Hash32_mCA5C9D8E9CBF5556CB85DC6C9847152A6C658FC1((uint8_t*)((HotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016**)UnBox(L_7, HotFixConfig_tC505F4EE934416CF9FCE21AF5922D8250B73B016_il2cpp_TypeInfo_var)), ((int32_t)0), 0, NULL);
		return L_8;
	}

IL_0063:
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_9 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_9, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral26673D6CBCD1AA03BAC761AFC10C0A46A418CA32)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_9, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&AssemblyTypeRegistry_BoxedGetHashCode_m51ABF56CB30C28866F9A1DD99686EE8FA066AA35_RuntimeMethod_var)));
	}
}
// Method Definition Index: 80697
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AttributeU5BU5D_t0F73488E6F1249C889608E8DCC0BCC28A874E8F1* AssemblyTypeRegistry_GetSystemAttributes_m745ECC27B9E20AA200CFB281D28E3A2F9C2E2C3C (Type_t* ___0_systemType, const RuntimeMethod* method) 
{
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_0 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral5F79BDEDF7F0A4A42173CCAF27F5C342A52DC260)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&AssemblyTypeRegistry_GetSystemAttributes_m745ECC27B9E20AA200CFB281D28E3A2F9C2E2C3C_RuntimeMethod_var)));
	}
}
// Method Definition Index: 80698
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AssemblyTypeRegistry_SetSharedStaticTypeIndices_m3DE4774BFFA0B87DE6BB2678A9C2737686BF6917 (int32_t* ___0_pTypeInfos, int32_t ___1_count, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SharedStatic_1_get_Data_m7B65B281F2D304BF7A408DDC24F8DA7DD99D9368_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SharedTypeIndex_1_t2C32D65079DB63CC448E325FB9378851A676AE73_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SharedTypeIndex_1_t3F0C6DA9E27125602575D8B02FAEAE477DA08DFE_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SharedTypeIndex_1_t77C75304B99808772DAC7FE28A8C92DB2A4231BA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SharedTypeIndex_1_tF0C6371F19CE027D0F9CA9CE843704927F5E7581_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		int32_t L_0 = ___1_count;
		if ((((int32_t)L_0) == ((int32_t)((int32_t)4))))
		{
			goto IL_0016;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_1 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE3C158842AF393BF0773EC375934F0013B168F86)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&AssemblyTypeRegistry_SetSharedStaticTypeIndices_m3DE4774BFFA0B87DE6BB2678A9C2737686BF6917_RuntimeMethod_var)));
	}

IL_0016:
	{
		il2cpp_codegen_runtime_class_init_inline(SharedTypeIndex_1_t2C32D65079DB63CC448E325FB9378851A676AE73_il2cpp_TypeInfo_var);
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C* L_2;
		L_2 = SharedStatic_1_get_Data_m7B65B281F2D304BF7A408DDC24F8DA7DD99D9368((&((SharedTypeIndex_1_t2C32D65079DB63CC448E325FB9378851A676AE73_StaticFields*)il2cpp_codegen_static_fields_for(SharedTypeIndex_1_t2C32D65079DB63CC448E325FB9378851A676AE73_il2cpp_TypeInfo_var))->___Ref), SharedStatic_1_get_Data_m7B65B281F2D304BF7A408DDC24F8DA7DD99D9368_RuntimeMethod_var);
		int32_t* L_3 = ___0_pTypeInfos;
		int32_t L_4 = (*(((int32_t*)il2cpp_codegen_add((intptr_t)L_3, ((int32_t)il2cpp_codegen_multiply(((int32_t)0), 4))))));
		*((int32_t*)L_2) = (int32_t)L_4;
		il2cpp_codegen_runtime_class_init_inline(SharedTypeIndex_1_tF0C6371F19CE027D0F9CA9CE843704927F5E7581_il2cpp_TypeInfo_var);
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C* L_5;
		L_5 = SharedStatic_1_get_Data_m7B65B281F2D304BF7A408DDC24F8DA7DD99D9368((&((SharedTypeIndex_1_tF0C6371F19CE027D0F9CA9CE843704927F5E7581_StaticFields*)il2cpp_codegen_static_fields_for(SharedTypeIndex_1_tF0C6371F19CE027D0F9CA9CE843704927F5E7581_il2cpp_TypeInfo_var))->___Ref), SharedStatic_1_get_Data_m7B65B281F2D304BF7A408DDC24F8DA7DD99D9368_RuntimeMethod_var);
		int32_t* L_6 = ___0_pTypeInfos;
		int32_t L_7 = (*(((int32_t*)il2cpp_codegen_add((intptr_t)L_6, ((int32_t)il2cpp_codegen_multiply(((int32_t)1), 4))))));
		*((int32_t*)L_5) = (int32_t)L_7;
		il2cpp_codegen_runtime_class_init_inline(SharedTypeIndex_1_t3F0C6DA9E27125602575D8B02FAEAE477DA08DFE_il2cpp_TypeInfo_var);
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C* L_8;
		L_8 = SharedStatic_1_get_Data_m7B65B281F2D304BF7A408DDC24F8DA7DD99D9368((&((SharedTypeIndex_1_t3F0C6DA9E27125602575D8B02FAEAE477DA08DFE_StaticFields*)il2cpp_codegen_static_fields_for(SharedTypeIndex_1_t3F0C6DA9E27125602575D8B02FAEAE477DA08DFE_il2cpp_TypeInfo_var))->___Ref), SharedStatic_1_get_Data_m7B65B281F2D304BF7A408DDC24F8DA7DD99D9368_RuntimeMethod_var);
		int32_t* L_9 = ___0_pTypeInfos;
		int32_t L_10 = (*(((int32_t*)il2cpp_codegen_add((intptr_t)L_9, ((int32_t)il2cpp_codegen_multiply(((int32_t)2), 4))))));
		*((int32_t*)L_8) = (int32_t)L_10;
		il2cpp_codegen_runtime_class_init_inline(SharedTypeIndex_1_t77C75304B99808772DAC7FE28A8C92DB2A4231BA_il2cpp_TypeInfo_var);
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C* L_11;
		L_11 = SharedStatic_1_get_Data_m7B65B281F2D304BF7A408DDC24F8DA7DD99D9368((&((SharedTypeIndex_1_t77C75304B99808772DAC7FE28A8C92DB2A4231BA_StaticFields*)il2cpp_codegen_static_fields_for(SharedTypeIndex_1_t77C75304B99808772DAC7FE28A8C92DB2A4231BA_il2cpp_TypeInfo_var))->___Ref), SharedStatic_1_get_Data_m7B65B281F2D304BF7A408DDC24F8DA7DD99D9368_RuntimeMethod_var);
		int32_t* L_12 = ___0_pTypeInfos;
		int32_t L_13 = (*(((int32_t*)il2cpp_codegen_add((intptr_t)L_12, ((int32_t)il2cpp_codegen_multiply(((int32_t)3), 4))))));
		*((int32_t*)L_11) = (int32_t)L_13;
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
// Method Definition Index: 56235
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0 AsyncUniTaskMethodBuilder_Create_m882DFD5EE004FF6F84F182A3AC170AEDCA8C5327_inline (const RuntimeMethod* method) 
{
	AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/CompilerServices/AsyncUniTaskMethodBuilder.cs:23>
		il2cpp_codegen_initobj((&V_0), sizeof(AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0));
		AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0 L_0 = V_0;
		return L_0;
	}
}
// Method Definition Index: 56236
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270 AsyncUniTaskMethodBuilder_get_Task_m11E43D69C4F85EB23AAC58143DE695309D1022EC_inline (AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IStateMachineRunnerPromise_t5CE1FDF2F619E55F7DCFBE22E2B97835C6781C7B_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/CompilerServices/AsyncUniTaskMethodBuilder.cs:33>
		RuntimeObject* L_0 = __this->___runnerPromise;
		if (!L_0)
		{
			goto IL_0014;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/CompilerServices/AsyncUniTaskMethodBuilder.cs:35>
		RuntimeObject* L_1 = __this->___runnerPromise;
		NullCheck(L_1);
		UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270 L_2;
		L_2 = InterfaceFuncInvoker0< UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270 >::Invoke(1, IStateMachineRunnerPromise_t5CE1FDF2F619E55F7DCFBE22E2B97835C6781C7B_il2cpp_TypeInfo_var, L_1);
		return L_2;
	}

IL_0014:
	{
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/CompilerServices/AsyncUniTaskMethodBuilder.cs:37>
		Exception_t* L_3 = __this->___ex;
		if (!L_3)
		{
			goto IL_0028;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/CompilerServices/AsyncUniTaskMethodBuilder.cs:39>
		Exception_t* L_4 = __this->___ex;
		il2cpp_codegen_runtime_class_init_inline(UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270_il2cpp_TypeInfo_var);
		UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270 L_5;
		L_5 = UniTask_FromException_mC6AC508C727D591C6BE908F2014570963CE9E5EE(L_4, NULL);
		return L_5;
	}

IL_0028:
	{
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/CompilerServices/AsyncUniTaskMethodBuilder.cs:43>
		il2cpp_codegen_runtime_class_init_inline(UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270_il2cpp_TypeInfo_var);
		UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270 L_6 = ((UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270_StaticFields*)il2cpp_codegen_static_fields_for(UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270_il2cpp_TypeInfo_var))->___CompletedTask;
		return L_6;
	}
}
// Method Definition Index: 53207
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Awaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956 UniTask_GetAwaiter_mF05A09B81913BECFD58FC67A16C0251FFCCAC939_inline (UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/UniTask.cs:62>
		Awaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Awaiter__ctor_m4154A3A6D62BB1657D17A8106633CD9E1CE51F04_inline((&L_0), __this, NULL);
		return L_0;
	}
}
// Method Definition Index: 53357
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Awaiter_get_IsCompleted_m2D01E3AB8A7C5AA8AA1E1EF58D92A6A095C00B9A_inline (Awaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/UniTask.cs:307>
		UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270* L_0 = (UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270*)(&__this->___task);
		il2cpp_codegen_runtime_class_init_inline(UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270_il2cpp_TypeInfo_var);
		int32_t L_1;
		L_1 = UniTask_get_Status_mA15B0F13DE3CE36730357CF50F65AE99ADF564DA_inline(L_0, NULL);
		bool L_2;
		L_2 = UniTaskStatusExtensions_IsCompleted_mF43C41C9CEB640E381D1F7A8B40142843AED87AE_inline(L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 53358
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Awaiter_GetResult_mC439993563D3BD49CEC67AAF6AFB3AEF72E916BD_inline (Awaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IUniTaskSource_t5AF6C202B2616C72E989C90B6E76DFEC4118174D_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/UniTask.cs:315>
		UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270* L_0 = (UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270*)(&__this->___task);
		RuntimeObject* L_1 = L_0->___source;
		if (L_1)
		{
			goto IL_000e;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/UniTask.cs:315>
		return;
	}

IL_000e:
	{
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/UniTask.cs:316>
		UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270* L_2 = (UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270*)(&__this->___task);
		RuntimeObject* L_3 = L_2->___source;
		UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270* L_4 = (UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270*)(&__this->___task);
		int16_t L_5 = L_4->___token;
		NullCheck(L_3);
		InterfaceActionInvoker1< int16_t >::Invoke(2, IUniTaskSource_t5AF6C202B2616C72E989C90B6E76DFEC4118174D_il2cpp_TypeInfo_var, L_3, L_5);
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/UniTask.cs:317>
		return;
	}
}
// Method Definition Index: 56237
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void AsyncUniTaskMethodBuilder_SetException_m0D772D62D01CC371F4AB0F6943BBBE0FEAB19643_inline (AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0* __this, Exception_t* ___0_exception, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IStateMachineRunnerPromise_t5CE1FDF2F619E55F7DCFBE22E2B97835C6781C7B_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/CompilerServices/AsyncUniTaskMethodBuilder.cs:53>
		RuntimeObject* L_0 = __this->___runnerPromise;
		if (L_0)
		{
			goto IL_0010;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/CompilerServices/AsyncUniTaskMethodBuilder.cs:55>
		Exception_t* L_1 = ___0_exception;
		__this->___ex = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___ex), (void*)L_1);
		return;
	}

IL_0010:
	{
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/CompilerServices/AsyncUniTaskMethodBuilder.cs:59>
		RuntimeObject* L_2 = __this->___runnerPromise;
		Exception_t* L_3 = ___0_exception;
		NullCheck(L_2);
		InterfaceActionInvoker1< Exception_t* >::Invoke(3, IStateMachineRunnerPromise_t5CE1FDF2F619E55F7DCFBE22E2B97835C6781C7B_il2cpp_TypeInfo_var, L_2, L_3);
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/CompilerServices/AsyncUniTaskMethodBuilder.cs:61>
		return;
	}
}
// Method Definition Index: 56238
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void AsyncUniTaskMethodBuilder_SetResult_mBBA527F0F21E04D65A269C0D02597CE5B2D1E9CB_inline (AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IStateMachineRunnerPromise_t5CE1FDF2F619E55F7DCFBE22E2B97835C6781C7B_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/CompilerServices/AsyncUniTaskMethodBuilder.cs:68>
		RuntimeObject* L_0 = __this->___runnerPromise;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/CompilerServices/AsyncUniTaskMethodBuilder.cs:70>
		RuntimeObject* L_1 = __this->___runnerPromise;
		NullCheck(L_1);
		InterfaceActionInvoker0::Invoke(2, IStateMachineRunnerPromise_t5CE1FDF2F619E55F7DCFBE22E2B97835C6781C7B_il2cpp_TypeInfo_var, L_1);
	}

IL_0013:
	{
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/CompilerServices/AsyncUniTaskMethodBuilder.cs:72>
		return;
	}
}
// Method Definition Index: 56241
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void AsyncUniTaskMethodBuilder_Start_TisU3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129_m5B101A1A0A29177A7195A0F7BA5BA027A4AC58E1_gshared_inline (AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0* __this, U3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129* ___0_stateMachine, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/CompilerServices/AsyncUniTaskMethodBuilder.cs:111>
		U3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129* L_0 = ___0_stateMachine;
		U3CInitU3Ed__6_MoveNext_mDBDB72E5E93D5EB8DD159440DF156C801E5AD0AF(L_0, il2cpp_rgctx_method(method->rgctx_data, 2));
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/CompilerServices/AsyncUniTaskMethodBuilder.cs:112>
		return;
	}
}
// Method Definition Index: 9831
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Enumerator_get_Current_m6330F15D18EE4F547C05DF9BF83C5EB710376027_gshared_inline (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->____current;
		return L_0;
	}
}
// Method Definition Index: 9777
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Clear_m16C1F2C61FED5955F10EB36BC1CB2DF34B128994_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
	}
	{
		int32_t L_1 = __this->____size;
		V_0 = L_1;
		__this->____size = 0;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) <= ((int32_t)0)))
		{
			goto IL_003c;
		}
	}
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_3 = __this->____items;
		int32_t L_4 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_3, 0, L_4, NULL);
		return;
	}

IL_003c:
	{
		return;
	}
}
// Method Definition Index: 9769
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_4 = V_0;
		NullCheck(L_4);
		if ((!(((uint32_t)L_3) < ((uint32_t)((int32_t)(((RuntimeArray*)L_4)->max_length))))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_5 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_5, 1));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_6 = V_0;
		int32_t L_7 = V_1;
		RuntimeObject* L_8 = ___0_item;
		NullCheck(L_6);
		(L_6)->SetAt(static_cast<il2cpp_array_size_t>(L_7), (RuntimeObject*)L_8);
		return;
	}

IL_0034:
	{
		RuntimeObject* L_9 = ___0_item;
		List_1_AddWithResize_m79A9BF770BEF9C06BE40D5401E55E375F2726CC4(__this, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		return;
	}
}
// Method Definition Index: 56240
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void AsyncUniTaskMethodBuilder_AwaitUnsafeOnCompleted_TisAwaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956_TisU3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129_m65DA9E32C2BB838DA1CBBC1C0B8BE7B25E64C11C_gshared_inline (AsyncUniTaskMethodBuilder_t490751EC621C472E098B12103AF16BC549912BB0* __this, Awaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956* ___0_awaiter, U3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129* ___1_stateMachine, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IStateMachineRunnerPromise_t5CE1FDF2F619E55F7DCFBE22E2B97835C6781C7B_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	{
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/CompilerServices/AsyncUniTaskMethodBuilder.cs:97>
		RuntimeObject* L_0 = __this->___runnerPromise;
		if (L_0)
		{
			goto IL_0014;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/CompilerServices/AsyncUniTaskMethodBuilder.cs:99>
		U3CInitU3Ed__6_tD712C755775EF1AF211BAC1D0581D74381C5F129* L_1 = ___1_stateMachine;
		RuntimeObject** L_2 = (RuntimeObject**)(&__this->___runnerPromise);
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 2));
		AsyncUniTask_1_SetStateMachine_mAC4B51C33691C941ED75D31FC061D8470EEB1F0A(L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
	}

IL_0014:
	{
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/CompilerServices/AsyncUniTaskMethodBuilder.cs:102>
		Awaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956* L_3 = ___0_awaiter;
		RuntimeObject* L_4 = __this->___runnerPromise;
		NullCheck(L_4);
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_5;
		L_5 = InterfaceFuncInvoker0< Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* >::Invoke(0, IStateMachineRunnerPromise_t5CE1FDF2F619E55F7DCFBE22E2B97835C6781C7B_il2cpp_TypeInfo_var, L_4);
		Awaiter_UnsafeOnCompleted_m6C4775F8F4F2BEFB8118EBBA1EA621440CE84D62_inline(L_3, L_5, il2cpp_rgctx_method(method->rgctx_data, 5));
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/CompilerServices/AsyncUniTaskMethodBuilder.cs:103>
		return;
	}
}
// Method Definition Index: 53356
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Awaiter__ctor_m4154A3A6D62BB1657D17A8106633CD9E1CE51F04_inline (Awaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956* __this, UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270* ___0_task, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/UniTask.cs:298>
		UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270* L_0 = ___0_task;
		UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270 L_1 = (*(UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270*)L_0);
		__this->___task = L_1;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___task))->___source), (void*)NULL);
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/UniTask.cs:299>
		return;
	}
}
// Method Definition Index: 53206
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UniTask_get_Status_mA15B0F13DE3CE36730357CF50F65AE99ADF564DA_inline (UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IUniTaskSource_t5AF6C202B2616C72E989C90B6E76DFEC4118174D_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/UniTask.cs:53>
		RuntimeObject* L_0 = __this->___source;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/UniTask.cs:53>
		return (int32_t)(1);
	}

IL_000a:
	{
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/UniTask.cs:54>
		RuntimeObject* L_1 = __this->___source;
		int16_t L_2 = __this->___token;
		NullCheck(L_1);
		int32_t L_3;
		L_3 = InterfaceFuncInvoker1< int32_t, int16_t >::Invoke(0, IUniTaskSource_t5AF6C202B2616C72E989C90B6E76DFEC4118174D_il2cpp_TypeInfo_var, L_1, L_2);
		return L_3;
	}
}
// Method Definition Index: 53084
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool UniTaskStatusExtensions_IsCompleted_mF43C41C9CEB640E381D1F7A8B40142843AED87AE_inline (int32_t ___0_status, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/IUniTaskSource.cs:102>
		int32_t L_0 = ___0_status;
		return (bool)((!(((uint32_t)L_0) <= ((uint32_t)0)))? 1 : 0);
	}
}
// Method Definition Index: 53360
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Awaiter_UnsafeOnCompleted_m6C4775F8F4F2BEFB8118EBBA1EA621440CE84D62_inline (Awaiter_tFACD37B3B2ACD03C61DB949FD0E4FAB189A1D956* __this, Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___0_continuation, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AwaiterActions_t5D05CAC006FDEBCF6B65E2B9224BC4B44783BBE5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IUniTaskSource_t5AF6C202B2616C72E989C90B6E76DFEC4118174D_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/UniTask.cs:337>
		UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270* L_0 = (UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270*)(&__this->___task);
		RuntimeObject* L_1 = L_0->___source;
		if (L_1)
		{
			goto IL_0014;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/UniTask.cs:339>
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_2 = ___0_continuation;
		NullCheck(L_2);
		Action_Invoke_m7126A54DACA72B845424072887B5F3A51FC3808E_inline(L_2, NULL);
		return;
	}

IL_0014:
	{
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/UniTask.cs:343>
		UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270* L_3 = (UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270*)(&__this->___task);
		RuntimeObject* L_4 = L_3->___source;
		il2cpp_codegen_runtime_class_init_inline(AwaiterActions_t5D05CAC006FDEBCF6B65E2B9224BC4B44783BBE5_il2cpp_TypeInfo_var);
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_5 = ((AwaiterActions_t5D05CAC006FDEBCF6B65E2B9224BC4B44783BBE5_StaticFields*)il2cpp_codegen_static_fields_for(AwaiterActions_t5D05CAC006FDEBCF6B65E2B9224BC4B44783BBE5_il2cpp_TypeInfo_var))->___InvokeContinuationDelegate;
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_6 = ___0_continuation;
		UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270* L_7 = (UniTask_t8E1453C1D8424B1FC22B0E51B017D3B028E17270*)(&__this->___task);
		int16_t L_8 = L_7->___token;
		NullCheck(L_4);
		InterfaceActionInvoker3< Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*, RuntimeObject*, int16_t >::Invoke(1, IUniTaskSource_t5AF6C202B2616C72E989C90B6E76DFEC4118174D_il2cpp_TypeInfo_var, L_4, L_5, L_6, L_8);
		//<source_info:./Library/PackageCache/com.cysharp.unitask@0dda4ba29591/Runtime/UniTask.cs:345>
		return;
	}
}
// Method Definition Index: 719
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_Invoke_m7126A54DACA72B845424072887B5F3A51FC3808E_inline (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* __this, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
