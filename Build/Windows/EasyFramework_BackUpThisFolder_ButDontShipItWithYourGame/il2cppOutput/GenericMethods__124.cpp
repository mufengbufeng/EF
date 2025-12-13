#include "pch-cpp.hpp"





template <typename R, typename T1, typename T2>
struct VirtualFuncInvoker2
{
	typedef R (*Func)(void*, T1, T2, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1, T2 p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, p1, p2, invokeData.method);
	}
};
template <typename R, typename T1, typename T2>
struct VirtualFuncInvoker2Invoker;
template <typename R, typename T1, typename T2>
struct VirtualFuncInvoker2Invoker<R, T1*, T2*>
{
	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1* p1, T2* p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		R ret;
		void* params[2] = { p1, p2 };
		invokeData.method->invoker_method(il2cpp_codegen_get_method_pointer(invokeData.method), invokeData.method, obj, params, &ret);
		return ret;
	}
};
template <typename R, typename T1, typename T2, typename T3, typename T4>
struct InvokerFuncInvoker4;
template <typename R, typename T1, typename T2, typename T3, typename T4>
struct InvokerFuncInvoker4<R, T1, T2, T3*, T4>
{
	static inline R Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1 p1, T2 p2, T3* p3, T4 p4)
	{
		R ret;
		void* params[4] = { &p1, &p2, p3, &p4 };
		method->invoker_method(methodPtr, method, obj, params, &ret);
		return ret;
	}
};

struct Comparer_1_t7EDCB50F141B8333E02C67781CAC2D41381F0563;
struct Comparer_1_tFA27DAC2908F666A385A0E5699BB66735365343B;
struct Comparer_1_t58CF625431A0184A14FF0A33D14229F8F6EA3C98;
struct Comparer_1_t535E02B3998AA8B49230077EF0DFCB16BA44C985;
struct EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8;
struct EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B;
struct EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B;
struct EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70;
struct EqualityComparer_1_t458C8DC3748A89A213F4738B57D3742C4896ABE9;
struct UnsafeList_1_t5422E48C657109BA40866D6144D34066FFCACBB3;
struct UnsafeList_1_tC512AB26A525DF3622FBF1917719AEBFF48AAB27;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct SByteU5BU5D_t88116DA68378C3333DB73E7D36C1A06AFAA91913;
struct UInt32U5BU5D_t02FBD658AD156A17574ECE6106CF1FBFCC9807FA;
struct Archetype_t96EB5691CCC58A7A4E29CA4F9EA62A25E4C14582;
struct BlobAssetBatch_tE7DAEECF09D38F983FE3F829F7774B40F4FD6B46;
struct BufferHeaderNode_t5B82FC9F92F05CD08F8E68E889EDD8CA3F7CE58A;
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3;
struct ChainCleanup_t720381A951125FF2EAA04EA1E544B86820F30122;
struct ComponentDependencyManager_t88715270EBD172A299D4F6DB471143B7E0BCDB47;
struct ComponentTypeList_t8A43AFD2ABD042DD0F0FAA4F95F3FDA3A1D8C053;
struct ContentArchiveId_t597D4859829AE27318BBF350B3B7FBDCF8FC7030;
struct ContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7;
struct CreateCommand_t1BE9EDD827DBFE09AEBA77279812A127281B793B;
struct ECBChunk_tF8E51552DBA320AB90FCAE9CF1185FAFD3764F4F;
struct Entity_t56176FC78C475061A82383D9E0CEE352C6C52ABD;
struct EntityBufferCommand_t3BF4346ABAD0A13FAB7CB86834657220DEC2A694;
struct EntityCommand_tCC8169A1562D889EF6040A025A7C80E14E4BEDB4;
struct EntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB;
struct EntityComponentGCNode_t2D1D66D5AAC85ED491A1AD2427C9F004A9D48639;
struct EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F;
struct EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36;
struct EntityNameStoreAccessData_t5AC842F68D9F5083E23B12C17F81F43535F2ED1F;
struct EntityNode_tC20FE5828EB0F9D86961E1AB6B4FE1159265322D;
struct EntityQueryData_t20DB32E7BB3F8732C371E45E8A8CEBCE62B61C26;
struct EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574;
struct FixedString512Bytes_t0C425B0F2C07FEA1642C32BF8559116DF2BFF50E;
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C;
struct IntPtr_t;
struct JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08;
struct RemoteContentId_t27977325179FF4C511004EBF35A0B38AA71D66B0;
struct RemoteContentLocation_t600FAD240C089026DD5CAFCBC44B128555506F7D;
struct ResolvedSectionPath_t87B9F3F0B0115B2D7CCADAD376C33481F1B5BE1D;
struct RewindableAllocator_tB18F8ADC8F2EE36E1F51FCCCFF0AC093108EF254;
struct ScratchpadAllocator_t4BADB7B6C4C7FFF17A9496AFB210658ACE7340B4;
struct String_t;
struct SystemState_t1AAA7F65EAD5CC5666D3F0360B309F9DF032E47D;
struct SystemTypeIndex_tF8FE523E862B9185701A867D7FD36966F8F03E59;
struct TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C;
struct UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455;
struct UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B;
struct UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF;
struct UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926;
struct UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C;
struct UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2;
struct UntypedWeakReferenceId_tE6BA94FD975EA12B639C0A568532BD1AB874492A;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
struct WorldUnmanagedImpl_tB98600E1E80A2ABD0C6F29D8C55829750507D830;
struct DependencyHandle_t73038501598DF9B7E83BF8486D87B9DED6200B15;
struct EntityOffsetInfo_tAA68D1FC74ADF57FB76987377354ED848C7CC9D1;
struct TypeInfo_tD43B08A8D19156EEC98399693A96161F02139654;

IL2CPP_EXTERN_C RuntimeClass* Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020_il2cpp_TypeInfo_var;
struct ChainCleanup_t720381A951125FF2EAA04EA1E544B86820F30122;
struct CreateCommand_t1BE9EDD827DBFE09AEBA77279812A127281B793B;
struct ECBChunk_tF8E51552DBA320AB90FCAE9CF1185FAFD3764F4F;
struct EntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB;
struct EntityCommand_tCC8169A1562D889EF6040A025A7C80E14E4BEDB4;


IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct Comparer_1_t7EDCB50F141B8333E02C67781CAC2D41381F0563  : public RuntimeObject
{
};
struct Comparer_1_tFA27DAC2908F666A385A0E5699BB66735365343B  : public RuntimeObject
{
};
struct Comparer_1_t58CF625431A0184A14FF0A33D14229F8F6EA3C98  : public RuntimeObject
{
};
struct Comparer_1_t535E02B3998AA8B49230077EF0DFCB16BA44C985  : public RuntimeObject
{
};
struct EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8  : public RuntimeObject
{
};
struct EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B  : public RuntimeObject
{
};
struct EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B  : public RuntimeObject
{
};
struct EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70  : public RuntimeObject
{
};
struct EqualityComparer_1_t458C8DC3748A89A213F4738B57D3742C4896ABE9  : public RuntimeObject
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
struct Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C  : public RuntimeObject
{
};
struct SharedStatic_1_t0A9894CA2483CA9491C550F8D66FBA5213718E9F 
{
	void* ____buffer;
};
#pragma pack(push, tp, 1)
struct BlobAssetBatch_tE7DAEECF09D38F983FE3F829F7774B40F4FD6B46 
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
					int32_t ___TotalDataSize;
				};
				#pragma pack(pop, tp)
				struct
				{
					int32_t ___TotalDataSize_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___BlobAssetHeaderCount_OffsetPadding[4];
					int32_t ___BlobAssetHeaderCount;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___BlobAssetHeaderCount_OffsetPadding_forAlignmentOnly[4];
					int32_t ___BlobAssetHeaderCount_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___RefCount_OffsetPadding[8];
					int32_t ___RefCount;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___RefCount_OffsetPadding_forAlignmentOnly[8];
					int32_t ___RefCount_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___Padding_OffsetPadding[12];
					int32_t ___Padding;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___Padding_OffsetPadding_forAlignmentOnly[12];
					int32_t ___Padding_forAlignmentOnly;
				};
			};
		};
		uint8_t BlobAssetBatch_tE7DAEECF09D38F983FE3F829F7774B40F4FD6B46__padding[16];
	};
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct BlobAssetOwner_t48F662D0AF49A5BBFD013EF59C8BD9C335A854AD 
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
					BlobAssetBatch_tE7DAEECF09D38F983FE3F829F7774B40F4FD6B46* ___BlobAssetBatchPtr;
				};
				#pragma pack(pop, tp)
				struct
				{
					BlobAssetBatch_tE7DAEECF09D38F983FE3F829F7774B40F4FD6B46* ___BlobAssetBatchPtr_forAlignmentOnly;
				};
			};
		};
		uint8_t BlobAssetOwner_t48F662D0AF49A5BBFD013EF59C8BD9C335A854AD__padding[8];
	};
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct BlobAssetReferenceData_tF4066C18E41A2817A3C1144C8A2AE91A33894998 
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
					uint8_t* ___m_Ptr;
				};
				#pragma pack(pop, tp)
				struct
				{
					uint8_t* ___m_Ptr_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					int64_t ___m_Align8Union;
				};
				#pragma pack(pop, tp)
				struct
				{
					int64_t ___m_Align8Union_forAlignmentOnly;
				};
			};
		};
		uint8_t BlobAssetReferenceData_tF4066C18E41A2817A3C1144C8A2AE91A33894998__padding[8];
	};
};
#pragma pack(pop, tp)
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3 
{
	uint8_t ___m_value;
};
struct ChainCleanup_t720381A951125FF2EAA04EA1E544B86820F30122 
{
	union
	{
		struct
		{
			EntityNode_tC20FE5828EB0F9D86961E1AB6B4FE1159265322D* ___EntityArraysCleanupList;
			BufferHeaderNode_t5B82FC9F92F05CD08F8E68E889EDD8CA3F7CE58A* ___BufferCleanupList;
			EntityComponentGCNode_t2D1D66D5AAC85ED491A1AD2427C9F004A9D48639* ___CleanupList;
		};
		uint8_t ChainCleanup_t720381A951125FF2EAA04EA1E544B86820F30122__padding[32];
	};
};
struct ECBChainHeapElement_tE83963A87C0B8B2EEDE315AF9DFF749A38C666DD 
{
	int32_t ___SortKey;
	int32_t ___ChainIndex;
};
struct ECBChunk_tF8E51552DBA320AB90FCAE9CF1185FAFD3764F4F 
{
	int32_t ___Used;
	int32_t ___Size;
	ECBChunk_tF8E51552DBA320AB90FCAE9CF1185FAFD3764F4F* ___Next;
	ECBChunk_tF8E51552DBA320AB90FCAE9CF1185FAFD3764F4F* ___Prev;
};
struct Entity_t56176FC78C475061A82383D9E0CEE352C6C52ABD 
{
	int32_t ___Index;
	int32_t ___Version;
};
struct EntityArchetype_tE1D293B55B4783642BB593531A57460AB7709354 
{
	Archetype_t96EB5691CCC58A7A4E29CA4F9EA62A25E4C14582* ___Archetype;
};
struct EntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB 
{
	union
	{
		struct
		{
			ECBChunk_tF8E51552DBA320AB90FCAE9CF1185FAFD3764F4F* ___m_Tail;
			ECBChunk_tF8E51552DBA320AB90FCAE9CF1185FAFD3764F4F* ___m_Head;
			ChainCleanup_t720381A951125FF2EAA04EA1E544B86820F30122* ___m_Cleanup;
			CreateCommand_t1BE9EDD827DBFE09AEBA77279812A127281B793B* ___m_PrevCreateCommand;
			EntityCommand_tCC8169A1562D889EF6040A025A7C80E14E4BEDB4* ___m_PrevEntityCommand;
			EntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB* ___m_NextChain;
			int32_t ___m_LastSortKey;
			bool ___m_CanBurstPlayback;
		};
		uint8_t EntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB__padding[64];
	};
};
struct EntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB_marshaled_pinvoke
{
	union
	{
		struct
		{
			ECBChunk_tF8E51552DBA320AB90FCAE9CF1185FAFD3764F4F* ___m_Tail;
			ECBChunk_tF8E51552DBA320AB90FCAE9CF1185FAFD3764F4F* ___m_Head;
			ChainCleanup_t720381A951125FF2EAA04EA1E544B86820F30122* ___m_Cleanup;
			CreateCommand_t1BE9EDD827DBFE09AEBA77279812A127281B793B* ___m_PrevCreateCommand;
			EntityCommand_tCC8169A1562D889EF6040A025A7C80E14E4BEDB4* ___m_PrevEntityCommand;
			EntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB* ___m_NextChain;
			int32_t ___m_LastSortKey;
			int32_t ___m_CanBurstPlayback;
		};
		uint8_t EntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB__padding[64];
	};
};
struct EntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB_marshaled_com
{
	union
	{
		struct
		{
			ECBChunk_tF8E51552DBA320AB90FCAE9CF1185FAFD3764F4F* ___m_Tail;
			ECBChunk_tF8E51552DBA320AB90FCAE9CF1185FAFD3764F4F* ___m_Head;
			ChainCleanup_t720381A951125FF2EAA04EA1E544B86820F30122* ___m_Cleanup;
			CreateCommand_t1BE9EDD827DBFE09AEBA77279812A127281B793B* ___m_PrevCreateCommand;
			EntityCommand_tCC8169A1562D889EF6040A025A7C80E14E4BEDB4* ___m_PrevEntityCommand;
			EntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB* ___m_NextChain;
			int32_t ___m_LastSortKey;
			int32_t ___m_CanBurstPlayback;
		};
		uint8_t EntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB__padding[64];
	};
};
struct EntityNameStoreAccessData_t5AC842F68D9F5083E23B12C17F81F43535F2ED1F 
{
	uint64_t ___m_NameChangeBitsSequenceNum;
};
struct EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90 
{
	EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* _____impl;
	uint64_t _____seqno;
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
#pragma pack(push, tp, 1)
struct FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 
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
					uint8_t ___byte0000;
				};
				#pragma pack(pop, tp)
				struct
				{
					uint8_t ___byte0000_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0001_OffsetPadding[1];
					uint8_t ___byte0001;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0001_OffsetPadding_forAlignmentOnly[1];
					uint8_t ___byte0001_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0002_OffsetPadding[2];
					uint8_t ___byte0002;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0002_OffsetPadding_forAlignmentOnly[2];
					uint8_t ___byte0002_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0003_OffsetPadding[3];
					uint8_t ___byte0003;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0003_OffsetPadding_forAlignmentOnly[3];
					uint8_t ___byte0003_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0004_OffsetPadding[4];
					uint8_t ___byte0004;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0004_OffsetPadding_forAlignmentOnly[4];
					uint8_t ___byte0004_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0005_OffsetPadding[5];
					uint8_t ___byte0005;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0005_OffsetPadding_forAlignmentOnly[5];
					uint8_t ___byte0005_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0006_OffsetPadding[6];
					uint8_t ___byte0006;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0006_OffsetPadding_forAlignmentOnly[6];
					uint8_t ___byte0006_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0007_OffsetPadding[7];
					uint8_t ___byte0007;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0007_OffsetPadding_forAlignmentOnly[7];
					uint8_t ___byte0007_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0008_OffsetPadding[8];
					uint8_t ___byte0008;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0008_OffsetPadding_forAlignmentOnly[8];
					uint8_t ___byte0008_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0009_OffsetPadding[9];
					uint8_t ___byte0009;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0009_OffsetPadding_forAlignmentOnly[9];
					uint8_t ___byte0009_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0010_OffsetPadding[10];
					uint8_t ___byte0010;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0010_OffsetPadding_forAlignmentOnly[10];
					uint8_t ___byte0010_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0011_OffsetPadding[11];
					uint8_t ___byte0011;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0011_OffsetPadding_forAlignmentOnly[11];
					uint8_t ___byte0011_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0012_OffsetPadding[12];
					uint8_t ___byte0012;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0012_OffsetPadding_forAlignmentOnly[12];
					uint8_t ___byte0012_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0013_OffsetPadding[13];
					uint8_t ___byte0013;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0013_OffsetPadding_forAlignmentOnly[13];
					uint8_t ___byte0013_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0014_OffsetPadding[14];
					uint8_t ___byte0014;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0014_OffsetPadding_forAlignmentOnly[14];
					uint8_t ___byte0014_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0015_OffsetPadding[15];
					uint8_t ___byte0015;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0015_OffsetPadding_forAlignmentOnly[15];
					uint8_t ___byte0015_forAlignmentOnly;
				};
			};
		};
		uint8_t FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0__padding[16];
	};
};
#pragma pack(pop, tp)
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
struct JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 
{
	uint64_t ___jobGroup;
	int32_t ___version;
};
struct ReadCommand_t5DB46BD58D686FDDFBD8AB7600B9CF676DC7D97F 
{
	void* ___Buffer;
	int64_t ___Offset;
	int64_t ___Size;
};
struct SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5 
{
	int8_t ___m_value;
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
struct UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455 
{
	uint16_t ___m_value;
};
struct UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF 
{
	uint64_t ___m_value;
};
struct UnsafeAtomicCounter32_tB925055F9F609BFEE32CC1CB3AA04D0B75690B62 
{
	int32_t* ___Counter;
};
struct UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926 
{
	union
	{
		#pragma pack(push, tp, 1)
		struct
		{
			uint8_t* ___values;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint8_t* ___values_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___keys_OffsetPadding[8];
			uint8_t* ___keys;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___keys_OffsetPadding_forAlignmentOnly[8];
			uint8_t* ___keys_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___next_OffsetPadding[16];
			uint8_t* ___next;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___next_OffsetPadding_forAlignmentOnly[16];
			uint8_t* ___next_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___buckets_OffsetPadding[24];
			uint8_t* ___buckets;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___buckets_OffsetPadding_forAlignmentOnly[24];
			uint8_t* ___buckets_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___keyCapacity_OffsetPadding[32];
			int32_t ___keyCapacity;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___keyCapacity_OffsetPadding_forAlignmentOnly[32];
			int32_t ___keyCapacity_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___bucketCapacityMask_OffsetPadding[36];
			int32_t ___bucketCapacityMask;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___bucketCapacityMask_OffsetPadding_forAlignmentOnly[36];
			int32_t ___bucketCapacityMask_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___allocatedIndexLength_OffsetPadding[40];
			int32_t ___allocatedIndexLength;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___allocatedIndexLength_OffsetPadding_forAlignmentOnly[40];
			int32_t ___allocatedIndexLength_forAlignmentOnly;
		};
	};
};
struct UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C 
{
	UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C* ___m_NextBlock;
	int32_t ___m_NumItems;
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
struct WorldUnmanaged_t7B736084B2D4749A9CE36AD9A7F9D930DAA9F88F 
{
	WorldUnmanagedImpl_tB98600E1E80A2ABD0C6F29D8C55829750507D830* ___m_Impl;
};
struct uint4_t6C69CBFAE9BF0F727D52B68779D4A3F0DBA8D5C9 
{
	uint32_t ___x;
	uint32_t ___y;
	uint32_t ___z;
	uint32_t ___w;
};
struct v64_t9C4037532D386FF1E9B95E5FBD01FEF472AC1F96 
{
	union
	{
		#pragma pack(push, tp, 1)
		struct
		{
			uint8_t ___Byte0;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint8_t ___Byte0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte1_OffsetPadding[1];
			uint8_t ___Byte1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte1_OffsetPadding_forAlignmentOnly[1];
			uint8_t ___Byte1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte2_OffsetPadding[2];
			uint8_t ___Byte2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte2_OffsetPadding_forAlignmentOnly[2];
			uint8_t ___Byte2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte3_OffsetPadding[3];
			uint8_t ___Byte3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte3_OffsetPadding_forAlignmentOnly[3];
			uint8_t ___Byte3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte4_OffsetPadding[4];
			uint8_t ___Byte4;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte4_OffsetPadding_forAlignmentOnly[4];
			uint8_t ___Byte4_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte5_OffsetPadding[5];
			uint8_t ___Byte5;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte5_OffsetPadding_forAlignmentOnly[5];
			uint8_t ___Byte5_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte6_OffsetPadding[6];
			uint8_t ___Byte6;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte6_OffsetPadding_forAlignmentOnly[6];
			uint8_t ___Byte6_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte7_OffsetPadding[7];
			uint8_t ___Byte7;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte7_OffsetPadding_forAlignmentOnly[7];
			uint8_t ___Byte7_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			int8_t ___SByte0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int8_t ___SByte0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte1_OffsetPadding[1];
			int8_t ___SByte1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte1_OffsetPadding_forAlignmentOnly[1];
			int8_t ___SByte1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte2_OffsetPadding[2];
			int8_t ___SByte2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte2_OffsetPadding_forAlignmentOnly[2];
			int8_t ___SByte2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte3_OffsetPadding[3];
			int8_t ___SByte3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte3_OffsetPadding_forAlignmentOnly[3];
			int8_t ___SByte3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte4_OffsetPadding[4];
			int8_t ___SByte4;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte4_OffsetPadding_forAlignmentOnly[4];
			int8_t ___SByte4_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte5_OffsetPadding[5];
			int8_t ___SByte5;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte5_OffsetPadding_forAlignmentOnly[5];
			int8_t ___SByte5_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte6_OffsetPadding[6];
			int8_t ___SByte6;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte6_OffsetPadding_forAlignmentOnly[6];
			int8_t ___SByte6_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte7_OffsetPadding[7];
			int8_t ___SByte7;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte7_OffsetPadding_forAlignmentOnly[7];
			int8_t ___SByte7_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			uint16_t ___UShort0;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint16_t ___UShort0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___UShort1_OffsetPadding[2];
			uint16_t ___UShort1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___UShort1_OffsetPadding_forAlignmentOnly[2];
			uint16_t ___UShort1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___UShort2_OffsetPadding[4];
			uint16_t ___UShort2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___UShort2_OffsetPadding_forAlignmentOnly[4];
			uint16_t ___UShort2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___UShort3_OffsetPadding[6];
			uint16_t ___UShort3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___UShort3_OffsetPadding_forAlignmentOnly[6];
			uint16_t ___UShort3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			int16_t ___SShort0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int16_t ___SShort0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SShort1_OffsetPadding[2];
			int16_t ___SShort1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SShort1_OffsetPadding_forAlignmentOnly[2];
			int16_t ___SShort1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SShort2_OffsetPadding[4];
			int16_t ___SShort2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SShort2_OffsetPadding_forAlignmentOnly[4];
			int16_t ___SShort2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SShort3_OffsetPadding[6];
			int16_t ___SShort3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SShort3_OffsetPadding_forAlignmentOnly[6];
			int16_t ___SShort3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			uint32_t ___UInt0;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint32_t ___UInt0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___UInt1_OffsetPadding[4];
			uint32_t ___UInt1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___UInt1_OffsetPadding_forAlignmentOnly[4];
			uint32_t ___UInt1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			int32_t ___SInt0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int32_t ___SInt0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SInt1_OffsetPadding[4];
			int32_t ___SInt1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SInt1_OffsetPadding_forAlignmentOnly[4];
			int32_t ___SInt1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			uint64_t ___ULong0;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint64_t ___ULong0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			int64_t ___SLong0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int64_t ___SLong0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			float ___Float0;
		};
		#pragma pack(pop, tp)
		struct
		{
			float ___Float0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Float1_OffsetPadding[4];
			float ___Float1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Float1_OffsetPadding_forAlignmentOnly[4];
			float ___Float1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			double ___Double0;
		};
		#pragma pack(pop, tp)
		struct
		{
			double ___Double0_forAlignmentOnly;
		};
	};
};
struct AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 
{
	uint16_t ___Index;
	uint16_t ___Version;
};
struct BufferWithFixUp_tDFD5630DDFDBC051A462A026DFAEAA4A047FB3B6 
{
	EntityBufferCommand_t3BF4346ABAD0A13FAB7CB86834657220DEC2A694* ___cmd;
};
struct ChunkListChanges_tC57E06E14D1D6D3D87675D05619E0539A86564D8 
{
	Archetype_t96EB5691CCC58A7A4E29CA4F9EA62A25E4C14582* ___ArchetypeTrackingHead;
};
struct Union_t651696C44E98CE15C53FE2628FA73E4B102D6C21 
{
	int64_t ___m_long;
};
struct PerChunkData_t1837BB30B95C4DD39A4908ECC71AB0B75DFF9135 
{
	Archetype_t96EB5691CCC58A7A4E29CA4F9EA62A25E4C14582* ___Archetype;
	int32_t ___EntityCount;
	int32_t ___ListIndex;
};
struct U3CIndexInEntityQueryU3Ee__FixedBuffer_t16145BD96786E58BD62F3D7542DA41E279C0E65A 
{
	union
	{
		struct
		{
			int32_t ___FixedElementField;
		};
		uint8_t U3CIndexInEntityQueryU3Ee__FixedBuffer_t16145BD96786E58BD62F3D7542DA41E279C0E65A__padding[8];
	};
};
struct U3CIndexInEntityQueryU3Ee__FixedBuffer_tF74E8C082C63D1F5EC4A529909287F360012EDD9 
{
	union
	{
		struct
		{
			int32_t ___FixedElementField;
		};
		uint8_t U3CIndexInEntityQueryU3Ee__FixedBuffer_tF74E8C082C63D1F5EC4A529909287F360012EDD9__padding[8];
	};
};
struct U3CSharedComponentIndexU3Ee__FixedBuffer_t6678D7BCFF071F01975BEAE7FF8C6FA532C1FDA0 
{
	union
	{
		struct
		{
			int32_t ___FixedElementField;
		};
		uint8_t U3CSharedComponentIndexU3Ee__FixedBuffer_t6678D7BCFF071F01975BEAE7FF8C6FA532C1FDA0__padding[8];
	};
};
struct Array_t3B8F006A80A48C83471DE3516556F1AFE6873381 
{
	union
	{
		struct
		{
		};
		uint8_t Array_t3B8F006A80A48C83471DE3516556F1AFE6873381__padding[1];
	};
};
struct U3CTypeHashU3Ee__FixedBuffer_tFC7E207A0C02CC8C3BDE8AB86460FD7CD7C7C6B6 
{
	union
	{
		struct
		{
			int64_t ___FixedElementField;
		};
		uint8_t U3CTypeHashU3Ee__FixedBuffer_tFC7E207A0C02CC8C3BDE8AB86460FD7CD7C7C6B6__padding[512];
	};
};
struct U3CVersionU3Ee__FixedBuffer_tC6868E0A9CCAFCBB64E75DD215D2797B4C4EC116 
{
	union
	{
		struct
		{
			uint16_t ___FixedElementField;
		};
		uint8_t U3CVersionU3Ee__FixedBuffer_tC6868E0A9CCAFCBB64E75DD215D2797B4C4EC116__padding[128];
	};
};
struct StreamingStateData_tB4ECCAB2ECCD0555A32604F161D9B80D9FA42B3A 
{
	union
	{
		#pragma pack(push, tp, 1)
		struct
		{
			uint64_t ___Acc;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint64_t ___Acc_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Buffer_OffsetPadding[64];
			uint8_t ___Buffer;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Buffer_OffsetPadding_forAlignmentOnly[64];
			uint8_t ___Buffer_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___IsHash64_OffsetPadding[320];
			int32_t ___IsHash64;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___IsHash64_OffsetPadding_forAlignmentOnly[320];
			int32_t ___IsHash64_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___BufferedSize_OffsetPadding[324];
			int32_t ___BufferedSize;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___BufferedSize_OffsetPadding_forAlignmentOnly[324];
			int32_t ___BufferedSize_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___NbStripesSoFar_OffsetPadding[328];
			int32_t ___NbStripesSoFar;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___NbStripesSoFar_OffsetPadding_forAlignmentOnly[328];
			int32_t ___NbStripesSoFar_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___TotalLength_OffsetPadding[336];
			int64_t ___TotalLength;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___TotalLength_OffsetPadding_forAlignmentOnly[336];
			int64_t ___TotalLength_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Seed_OffsetPadding[344];
			uint64_t ___Seed;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Seed_OffsetPadding_forAlignmentOnly[344];
			uint64_t ___Seed_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SecretKey_OffsetPadding[352];
			uint8_t ___SecretKey;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SecretKey_OffsetPadding_forAlignmentOnly[352];
			uint8_t ___SecretKey_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ____PadEnd_OffsetPadding[540];
			uint8_t ____PadEnd;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ____PadEnd_OffsetPadding_forAlignmentOnly[540];
			uint8_t ____PadEnd_forAlignmentOnly;
		};
	};
};
struct U3CBitsU3Ee__FixedBuffer_tFED81968B5AEB075B5560B55A16A31C5F01A83BD 
{
	union
	{
		struct
		{
			uint16_t ___FixedElementField;
		};
		uint8_t U3CBitsU3Ee__FixedBuffer_tFED81968B5AEB075B5560B55A16A31C5F01A83BD__padding[32];
	};
};
struct AllocatorHelper_1_tE2F3FBC837659F89E544184EDA24A6DDB9FD35D0 
{
	RewindableAllocator_tB18F8ADC8F2EE36E1F51FCCCFF0AC093108EF254* ___m_allocator;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___m_backingAllocator;
};
struct AllocatorHelper_1_t0290FF01C365B75408A8E7D00CC67BF0D92CB97B 
{
	ScratchpadAllocator_t4BADB7B6C4C7FFF17A9496AFB210658ACE7340B4* ___m_allocator;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___m_backingAllocator;
};
struct BlobAssetReference_1_tD5149596D95DFDE07586D2F21EBDCE9F21C30A24 
{
	alignas(8) BlobAssetReferenceData_tF4066C18E41A2817A3C1144C8A2AE91A33894998 ___m_data;
};
struct HashMapHelper_1_t1922B493DF75C945824746A291BE8AD04E7A6910 
{
	uint8_t* ___Ptr;
	ContentArchiveId_t597D4859829AE27318BBF350B3B7FBDCF8FC7030* ___Keys;
	int32_t* ___Next;
	int32_t* ___Buckets;
	int32_t ___Count;
	int32_t ___Capacity;
	int32_t ___Log2MinGrowth;
	int32_t ___BucketCapacity;
	int32_t ___AllocatedIndex;
	int32_t ___FirstFreeIdx;
	int32_t ___SizeOfTValue;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
};
struct HashMapHelper_1_tB74757C88AFC77B83E59303BFF915A4BDED9A5A5 
{
	uint8_t* ___Ptr;
	ContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7* ___Keys;
	int32_t* ___Next;
	int32_t* ___Buckets;
	int32_t ___Count;
	int32_t ___Capacity;
	int32_t ___Log2MinGrowth;
	int32_t ___BucketCapacity;
	int32_t ___AllocatedIndex;
	int32_t ___FirstFreeIdx;
	int32_t ___SizeOfTValue;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
};
struct HashMapHelper_1_tF4097677DF54F9B7101CE52DA301CACDF02D8AD9 
{
	uint8_t* ___Ptr;
	Entity_t56176FC78C475061A82383D9E0CEE352C6C52ABD* ___Keys;
	int32_t* ___Next;
	int32_t* ___Buckets;
	int32_t ___Count;
	int32_t ___Capacity;
	int32_t ___Log2MinGrowth;
	int32_t ___BucketCapacity;
	int32_t ___AllocatedIndex;
	int32_t ___FirstFreeIdx;
	int32_t ___SizeOfTValue;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
};
struct HashMapHelper_1_t55F6D796BFB8E5F42BE6369F25DF63EC9F81AFBC 
{
	uint8_t* ___Ptr;
	FixedString512Bytes_t0C425B0F2C07FEA1642C32BF8559116DF2BFF50E* ___Keys;
	int32_t* ___Next;
	int32_t* ___Buckets;
	int32_t ___Count;
	int32_t ___Capacity;
	int32_t ___Log2MinGrowth;
	int32_t ___BucketCapacity;
	int32_t ___AllocatedIndex;
	int32_t ___FirstFreeIdx;
	int32_t ___SizeOfTValue;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
};
struct HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B 
{
	uint8_t* ___Ptr;
	int32_t* ___Keys;
	int32_t* ___Next;
	int32_t* ___Buckets;
	int32_t ___Count;
	int32_t ___Capacity;
	int32_t ___Log2MinGrowth;
	int32_t ___BucketCapacity;
	int32_t ___AllocatedIndex;
	int32_t ___FirstFreeIdx;
	int32_t ___SizeOfTValue;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
};
struct HashMapHelper_1_t52DEB1D232D9067231DF945A04789178DDC0119D 
{
	uint8_t* ___Ptr;
	RemoteContentId_t27977325179FF4C511004EBF35A0B38AA71D66B0* ___Keys;
	int32_t* ___Next;
	int32_t* ___Buckets;
	int32_t ___Count;
	int32_t ___Capacity;
	int32_t ___Log2MinGrowth;
	int32_t ___BucketCapacity;
	int32_t ___AllocatedIndex;
	int32_t ___FirstFreeIdx;
	int32_t ___SizeOfTValue;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
};
struct HashMapHelper_1_t2DD122ED66B38FE6A3FF1935D7FDFE0E07AA7C09 
{
	uint8_t* ___Ptr;
	RemoteContentLocation_t600FAD240C089026DD5CAFCBC44B128555506F7D* ___Keys;
	int32_t* ___Next;
	int32_t* ___Buckets;
	int32_t ___Count;
	int32_t ___Capacity;
	int32_t ___Log2MinGrowth;
	int32_t ___BucketCapacity;
	int32_t ___AllocatedIndex;
	int32_t ___FirstFreeIdx;
	int32_t ___SizeOfTValue;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
};
struct HashMapHelper_1_tE18033C6B74BE6B9BAE79F2ADD9BC2C916DFA729 
{
	uint8_t* ___Ptr;
	alignas(IL2CPP_SIZEOF_VOID_P) SystemTypeIndex_tF8FE523E862B9185701A867D7FD36966F8F03E59* ___Keys;
	int32_t* ___Next;
	int32_t* ___Buckets;
	int32_t ___Count;
	int32_t ___Capacity;
	int32_t ___Log2MinGrowth;
	int32_t ___BucketCapacity;
	int32_t ___AllocatedIndex;
	int32_t ___FirstFreeIdx;
	int32_t ___SizeOfTValue;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
};
struct HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F 
{
	uint8_t* ___Ptr;
	uint64_t* ___Keys;
	int32_t* ___Next;
	int32_t* ___Buckets;
	int32_t ___Count;
	int32_t ___Capacity;
	int32_t ___Log2MinGrowth;
	int32_t ___BucketCapacity;
	int32_t ___AllocatedIndex;
	int32_t ___FirstFreeIdx;
	int32_t ___SizeOfTValue;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
};
struct HashMapHelper_1_tFE70D47D7D4D5A59CFA6D8E68852A7EE5BDB4854 
{
	uint8_t* ___Ptr;
	UntypedWeakReferenceId_tE6BA94FD975EA12B639C0A568532BD1AB874492A* ___Keys;
	int32_t* ___Next;
	int32_t* ___Buckets;
	int32_t ___Count;
	int32_t ___Capacity;
	int32_t ___Log2MinGrowth;
	int32_t ___BucketCapacity;
	int32_t ___AllocatedIndex;
	int32_t ___FirstFreeIdx;
	int32_t ___SizeOfTValue;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
};
struct UnsafeList_1_tA21F92C4A814A112A95FFC7861B906E3523E4EEF 
{
	UnsafeList_1_tC512AB26A525DF3622FBF1917719AEBFF48AAB27* ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct UnsafeList_1_t81DA7B1F50305CF2C5A3DAE7C5027E809A808B8C 
{
	ComponentTypeList_t8A43AFD2ABD042DD0F0FAA4F95F3FDA3A1D8C053* ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct UnsafeList_1_t6C5E84D303190B625F3759C244502E1735453718 
{
	int32_t* ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct UnsafeList_1_t7F37B06177929AC50704A82689AED5BBFE830613 
{
	intptr_t* ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct UnsafeList_1_tDA08D23291A006354D190890E73B9970FEFADE6E 
{
	ResolvedSectionPath_t87B9F3F0B0115B2D7CCADAD376C33481F1B5BE1D* ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct UnsafeList_1_tEE6D0269E6E8E59E96623AA3410F283FE7B8CF65 
{
	alignas(IL2CPP_SIZEOF_VOID_P) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C* ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct UnsafeList_1_tA2B6A040C4F2656D88ABB4345257ADE8F2F30F35 
{
	uint32_t* ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct UnsafeParallelMultiHashMap_2_tF97D13A4436BE5A45CEFAE2066E0ABE4AB22DC94 
{
	UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___m_Buffer;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___m_AllocatorLabel;
};
struct UnsafePtrList_1_t3BA56CBE50A217517D1FA78C345C0AF8242F8088 
{
	Archetype_t96EB5691CCC58A7A4E29CA4F9EA62A25E4C14582** ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct UnsafePtrList_1_t9303472093C8513F7E98E3EFE8C3560679C4CAA6 
{
	EntityQueryData_t20DB32E7BB3F8732C371E45E8A8CEBCE62B61C26** ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258 
{
	UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* ___m_Buffer;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___m_AllocatorLabel;
};
struct UnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD 
{
	UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* ___m_Buffer;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___m_AllocatorLabel;
};
struct UnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515 
{
	UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* ___m_Buffer;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___m_AllocatorLabel;
};
struct UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6 
{
	int32_t* ___Ptr;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___m_Capacity;
	int32_t ___m_Filled;
	int32_t ___m_Write;
	int32_t ___m_Read;
};
struct UnsafeRingQueue_1_t916A7CB801E880FD1A00447CC4815827882753ED 
{
	UntypedWeakReferenceId_tE6BA94FD975EA12B639C0A568532BD1AB874492A* ___Ptr;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___m_Capacity;
	int32_t ___m_Filled;
	int32_t ___m_Write;
	int32_t ___m_Read;
};
#pragma pack(push, tp, 1)
struct BlobAssetHeader_t3EC5AD955B287949B57D36BBDE25A4D1BA85E639 
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
					void* ___ValidationPtr;
				};
				#pragma pack(pop, tp)
				struct
				{
					void* ___ValidationPtr_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___Length_OffsetPadding[8];
					int32_t ___Length;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___Length_OffsetPadding_forAlignmentOnly[8];
					int32_t ___Length_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___Allocator_OffsetPadding[12];
					AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___Allocator_OffsetPadding_forAlignmentOnly[12];
					AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___Hash_OffsetPadding[16];
					uint64_t ___Hash;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___Hash_OffsetPadding_forAlignmentOnly[16];
					uint64_t ___Hash_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___Padding_OffsetPadding[24];
					uint64_t ___Padding;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___Padding_OffsetPadding_forAlignmentOnly[24];
					uint64_t ___Padding_forAlignmentOnly;
				};
			};
		};
		uint8_t BlobAssetHeader_t3EC5AD955B287949B57D36BBDE25A4D1BA85E639__padding[32];
	};
};
#pragma pack(pop, tp)
struct DynamicBlobAssetBatch_tAF1A195EBA8DD36359A9439ED1BB2D99AD81F027 
{
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___m_Allocator;
	int32_t ___m_FramesToRetainBlobAssets;
	UnsafeList_1_t5422E48C657109BA40866D6144D34066FFCACBB3* ___m_BlobAssets;
};
#pragma pack(push, tp, 1)
struct FixedBytes510_t95B284C3FF966246998B23701C3F0F55C6BD7973 
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
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0000;
				};
				#pragma pack(pop, tp)
				struct
				{
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0000_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0016_OffsetPadding[16];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0016;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0016_OffsetPadding_forAlignmentOnly[16];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0016_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0032_OffsetPadding[32];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0032;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0032_OffsetPadding_forAlignmentOnly[32];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0032_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0048_OffsetPadding[48];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0048;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0048_OffsetPadding_forAlignmentOnly[48];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0048_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0064_OffsetPadding[64];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0064;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0064_OffsetPadding_forAlignmentOnly[64];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0064_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0080_OffsetPadding[80];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0080;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0080_OffsetPadding_forAlignmentOnly[80];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0080_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0096_OffsetPadding[96];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0096;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0096_OffsetPadding_forAlignmentOnly[96];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0096_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0112_OffsetPadding[112];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0112;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0112_OffsetPadding_forAlignmentOnly[112];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0112_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0128_OffsetPadding[128];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0128;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0128_OffsetPadding_forAlignmentOnly[128];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0128_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0144_OffsetPadding[144];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0144;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0144_OffsetPadding_forAlignmentOnly[144];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0144_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0160_OffsetPadding[160];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0160;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0160_OffsetPadding_forAlignmentOnly[160];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0160_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0176_OffsetPadding[176];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0176;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0176_OffsetPadding_forAlignmentOnly[176];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0176_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0192_OffsetPadding[192];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0192;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0192_OffsetPadding_forAlignmentOnly[192];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0192_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0208_OffsetPadding[208];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0208;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0208_OffsetPadding_forAlignmentOnly[208];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0208_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0224_OffsetPadding[224];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0224;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0224_OffsetPadding_forAlignmentOnly[224];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0224_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0240_OffsetPadding[240];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0240;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0240_OffsetPadding_forAlignmentOnly[240];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0240_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0256_OffsetPadding[256];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0256;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0256_OffsetPadding_forAlignmentOnly[256];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0256_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0272_OffsetPadding[272];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0272;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0272_OffsetPadding_forAlignmentOnly[272];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0272_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0288_OffsetPadding[288];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0288;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0288_OffsetPadding_forAlignmentOnly[288];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0288_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0304_OffsetPadding[304];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0304;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0304_OffsetPadding_forAlignmentOnly[304];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0304_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0320_OffsetPadding[320];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0320;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0320_OffsetPadding_forAlignmentOnly[320];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0320_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0336_OffsetPadding[336];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0336;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0336_OffsetPadding_forAlignmentOnly[336];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0336_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0352_OffsetPadding[352];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0352;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0352_OffsetPadding_forAlignmentOnly[352];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0352_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0368_OffsetPadding[368];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0368;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0368_OffsetPadding_forAlignmentOnly[368];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0368_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0384_OffsetPadding[384];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0384;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0384_OffsetPadding_forAlignmentOnly[384];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0384_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0400_OffsetPadding[400];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0400;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0400_OffsetPadding_forAlignmentOnly[400];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0400_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0416_OffsetPadding[416];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0416;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0416_OffsetPadding_forAlignmentOnly[416];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0416_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0432_OffsetPadding[432];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0432;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0432_OffsetPadding_forAlignmentOnly[432];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0432_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0448_OffsetPadding[448];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0448;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0448_OffsetPadding_forAlignmentOnly[448];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0448_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0464_OffsetPadding[464];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0464;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0464_OffsetPadding_forAlignmentOnly[464];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0464_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___offset0480_OffsetPadding[480];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0480;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___offset0480_OffsetPadding_forAlignmentOnly[480];
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0480_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0496_OffsetPadding[496];
					uint8_t ___byte0496;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0496_OffsetPadding_forAlignmentOnly[496];
					uint8_t ___byte0496_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0497_OffsetPadding[497];
					uint8_t ___byte0497;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0497_OffsetPadding_forAlignmentOnly[497];
					uint8_t ___byte0497_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0498_OffsetPadding[498];
					uint8_t ___byte0498;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0498_OffsetPadding_forAlignmentOnly[498];
					uint8_t ___byte0498_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0499_OffsetPadding[499];
					uint8_t ___byte0499;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0499_OffsetPadding_forAlignmentOnly[499];
					uint8_t ___byte0499_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0500_OffsetPadding[500];
					uint8_t ___byte0500;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0500_OffsetPadding_forAlignmentOnly[500];
					uint8_t ___byte0500_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0501_OffsetPadding[501];
					uint8_t ___byte0501;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0501_OffsetPadding_forAlignmentOnly[501];
					uint8_t ___byte0501_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0502_OffsetPadding[502];
					uint8_t ___byte0502;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0502_OffsetPadding_forAlignmentOnly[502];
					uint8_t ___byte0502_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0503_OffsetPadding[503];
					uint8_t ___byte0503;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0503_OffsetPadding_forAlignmentOnly[503];
					uint8_t ___byte0503_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0504_OffsetPadding[504];
					uint8_t ___byte0504;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0504_OffsetPadding_forAlignmentOnly[504];
					uint8_t ___byte0504_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0505_OffsetPadding[505];
					uint8_t ___byte0505;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0505_OffsetPadding_forAlignmentOnly[505];
					uint8_t ___byte0505_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0506_OffsetPadding[506];
					uint8_t ___byte0506;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0506_OffsetPadding_forAlignmentOnly[506];
					uint8_t ___byte0506_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0507_OffsetPadding[507];
					uint8_t ___byte0507;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0507_OffsetPadding_forAlignmentOnly[507];
					uint8_t ___byte0507_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0508_OffsetPadding[508];
					uint8_t ___byte0508;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0508_OffsetPadding_forAlignmentOnly[508];
					uint8_t ___byte0508_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0509_OffsetPadding[509];
					uint8_t ___byte0509;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0509_OffsetPadding_forAlignmentOnly[509];
					uint8_t ___byte0509_forAlignmentOnly;
				};
			};
		};
		uint8_t FixedBytes510_t95B284C3FF966246998B23701C3F0F55C6BD7973__padding[510];
	};
};
#pragma pack(pop, tp)
struct GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC 
{
	intptr_t ___handle;
};
struct Hash128_t2EA8F45F10BC2DF40B0CE9AE04F222072EB1345B 
{
	uint4_t6C69CBFAE9BF0F727D52B68779D4A3F0DBA8D5C9 ___Value;
};
struct PlaybackPolicy_tDD40E624361B800D46A8F2AACB61FC7ADA97021A 
{
	int32_t ___value__;
};
struct ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD 
{
	intptr_t ___m_Ptr;
};
struct ReadHandle_t71C4E3C6D2A80E1A200DA2C22346363F9A5EBEBB 
{
	intptr_t ___ptr;
	int32_t ___version;
};
struct UnsafeAppendBuffer_t9EC160EA10485CD9DD96EDCBCEA06C7BCEF81500 
{
	uint8_t* ___Ptr;
	int32_t ___Length;
	int32_t ___Capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___Alignment;
};
struct UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4 
{
	uint64_t* ___Ptr;
	int32_t ___Length;
	int32_t ___Capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
};
struct UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2 
{
	intptr_t ___m_FirstBlock;
	intptr_t ___m_LastBlock;
	int32_t ___m_MaxItems;
	int32_t ___m_CurrentRead;
	uint8_t* ___m_CurrentWriteBlockTLS;
};
struct UntypedUnsafeList_tB7A46F76589C71832F1147292E5123FB99E199B2 
{
	void* ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct UntypedUnsafeParallelHashMap_t926EFEEE26C4DE4FE2FA5A27FEA1D83CDD4B1B17 
{
	UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___m_Buffer;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___m_AllocatorLabel;
};
struct WeakReferenceGenerationType_t8BFE0640E45A3A0A8219F431CAE59E10BD6273AD 
{
	int16_t ___value__;
};
struct v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 
{
	union
	{
		#pragma pack(push, tp, 1)
		struct
		{
			uint8_t ___Byte0;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint8_t ___Byte0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte1_OffsetPadding[1];
			uint8_t ___Byte1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte1_OffsetPadding_forAlignmentOnly[1];
			uint8_t ___Byte1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte2_OffsetPadding[2];
			uint8_t ___Byte2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte2_OffsetPadding_forAlignmentOnly[2];
			uint8_t ___Byte2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte3_OffsetPadding[3];
			uint8_t ___Byte3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte3_OffsetPadding_forAlignmentOnly[3];
			uint8_t ___Byte3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte4_OffsetPadding[4];
			uint8_t ___Byte4;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte4_OffsetPadding_forAlignmentOnly[4];
			uint8_t ___Byte4_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte5_OffsetPadding[5];
			uint8_t ___Byte5;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte5_OffsetPadding_forAlignmentOnly[5];
			uint8_t ___Byte5_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte6_OffsetPadding[6];
			uint8_t ___Byte6;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte6_OffsetPadding_forAlignmentOnly[6];
			uint8_t ___Byte6_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte7_OffsetPadding[7];
			uint8_t ___Byte7;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte7_OffsetPadding_forAlignmentOnly[7];
			uint8_t ___Byte7_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte8_OffsetPadding[8];
			uint8_t ___Byte8;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte8_OffsetPadding_forAlignmentOnly[8];
			uint8_t ___Byte8_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte9_OffsetPadding[9];
			uint8_t ___Byte9;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte9_OffsetPadding_forAlignmentOnly[9];
			uint8_t ___Byte9_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte10_OffsetPadding[10];
			uint8_t ___Byte10;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte10_OffsetPadding_forAlignmentOnly[10];
			uint8_t ___Byte10_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte11_OffsetPadding[11];
			uint8_t ___Byte11;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte11_OffsetPadding_forAlignmentOnly[11];
			uint8_t ___Byte11_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte12_OffsetPadding[12];
			uint8_t ___Byte12;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte12_OffsetPadding_forAlignmentOnly[12];
			uint8_t ___Byte12_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte13_OffsetPadding[13];
			uint8_t ___Byte13;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte13_OffsetPadding_forAlignmentOnly[13];
			uint8_t ___Byte13_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte14_OffsetPadding[14];
			uint8_t ___Byte14;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte14_OffsetPadding_forAlignmentOnly[14];
			uint8_t ___Byte14_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte15_OffsetPadding[15];
			uint8_t ___Byte15;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte15_OffsetPadding_forAlignmentOnly[15];
			uint8_t ___Byte15_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			int8_t ___SByte0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int8_t ___SByte0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte1_OffsetPadding[1];
			int8_t ___SByte1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte1_OffsetPadding_forAlignmentOnly[1];
			int8_t ___SByte1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte2_OffsetPadding[2];
			int8_t ___SByte2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte2_OffsetPadding_forAlignmentOnly[2];
			int8_t ___SByte2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte3_OffsetPadding[3];
			int8_t ___SByte3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte3_OffsetPadding_forAlignmentOnly[3];
			int8_t ___SByte3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte4_OffsetPadding[4];
			int8_t ___SByte4;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte4_OffsetPadding_forAlignmentOnly[4];
			int8_t ___SByte4_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte5_OffsetPadding[5];
			int8_t ___SByte5;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte5_OffsetPadding_forAlignmentOnly[5];
			int8_t ___SByte5_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte6_OffsetPadding[6];
			int8_t ___SByte6;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte6_OffsetPadding_forAlignmentOnly[6];
			int8_t ___SByte6_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte7_OffsetPadding[7];
			int8_t ___SByte7;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte7_OffsetPadding_forAlignmentOnly[7];
			int8_t ___SByte7_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte8_OffsetPadding[8];
			int8_t ___SByte8;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte8_OffsetPadding_forAlignmentOnly[8];
			int8_t ___SByte8_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte9_OffsetPadding[9];
			int8_t ___SByte9;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte9_OffsetPadding_forAlignmentOnly[9];
			int8_t ___SByte9_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte10_OffsetPadding[10];
			int8_t ___SByte10;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte10_OffsetPadding_forAlignmentOnly[10];
			int8_t ___SByte10_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte11_OffsetPadding[11];
			int8_t ___SByte11;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte11_OffsetPadding_forAlignmentOnly[11];
			int8_t ___SByte11_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte12_OffsetPadding[12];
			int8_t ___SByte12;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte12_OffsetPadding_forAlignmentOnly[12];
			int8_t ___SByte12_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte13_OffsetPadding[13];
			int8_t ___SByte13;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte13_OffsetPadding_forAlignmentOnly[13];
			int8_t ___SByte13_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte14_OffsetPadding[14];
			int8_t ___SByte14;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte14_OffsetPadding_forAlignmentOnly[14];
			int8_t ___SByte14_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte15_OffsetPadding[15];
			int8_t ___SByte15;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte15_OffsetPadding_forAlignmentOnly[15];
			int8_t ___SByte15_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			uint16_t ___UShort0;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint16_t ___UShort0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___UShort1_OffsetPadding[2];
			uint16_t ___UShort1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___UShort1_OffsetPadding_forAlignmentOnly[2];
			uint16_t ___UShort1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___UShort2_OffsetPadding[4];
			uint16_t ___UShort2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___UShort2_OffsetPadding_forAlignmentOnly[4];
			uint16_t ___UShort2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___UShort3_OffsetPadding[6];
			uint16_t ___UShort3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___UShort3_OffsetPadding_forAlignmentOnly[6];
			uint16_t ___UShort3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___UShort4_OffsetPadding[8];
			uint16_t ___UShort4;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___UShort4_OffsetPadding_forAlignmentOnly[8];
			uint16_t ___UShort4_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___UShort5_OffsetPadding[10];
			uint16_t ___UShort5;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___UShort5_OffsetPadding_forAlignmentOnly[10];
			uint16_t ___UShort5_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___UShort6_OffsetPadding[12];
			uint16_t ___UShort6;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___UShort6_OffsetPadding_forAlignmentOnly[12];
			uint16_t ___UShort6_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___UShort7_OffsetPadding[14];
			uint16_t ___UShort7;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___UShort7_OffsetPadding_forAlignmentOnly[14];
			uint16_t ___UShort7_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			int16_t ___SShort0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int16_t ___SShort0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SShort1_OffsetPadding[2];
			int16_t ___SShort1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SShort1_OffsetPadding_forAlignmentOnly[2];
			int16_t ___SShort1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SShort2_OffsetPadding[4];
			int16_t ___SShort2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SShort2_OffsetPadding_forAlignmentOnly[4];
			int16_t ___SShort2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SShort3_OffsetPadding[6];
			int16_t ___SShort3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SShort3_OffsetPadding_forAlignmentOnly[6];
			int16_t ___SShort3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SShort4_OffsetPadding[8];
			int16_t ___SShort4;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SShort4_OffsetPadding_forAlignmentOnly[8];
			int16_t ___SShort4_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SShort5_OffsetPadding[10];
			int16_t ___SShort5;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SShort5_OffsetPadding_forAlignmentOnly[10];
			int16_t ___SShort5_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SShort6_OffsetPadding[12];
			int16_t ___SShort6;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SShort6_OffsetPadding_forAlignmentOnly[12];
			int16_t ___SShort6_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SShort7_OffsetPadding[14];
			int16_t ___SShort7;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SShort7_OffsetPadding_forAlignmentOnly[14];
			int16_t ___SShort7_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			uint32_t ___UInt0;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint32_t ___UInt0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___UInt1_OffsetPadding[4];
			uint32_t ___UInt1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___UInt1_OffsetPadding_forAlignmentOnly[4];
			uint32_t ___UInt1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___UInt2_OffsetPadding[8];
			uint32_t ___UInt2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___UInt2_OffsetPadding_forAlignmentOnly[8];
			uint32_t ___UInt2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___UInt3_OffsetPadding[12];
			uint32_t ___UInt3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___UInt3_OffsetPadding_forAlignmentOnly[12];
			uint32_t ___UInt3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			int32_t ___SInt0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int32_t ___SInt0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SInt1_OffsetPadding[4];
			int32_t ___SInt1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SInt1_OffsetPadding_forAlignmentOnly[4];
			int32_t ___SInt1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SInt2_OffsetPadding[8];
			int32_t ___SInt2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SInt2_OffsetPadding_forAlignmentOnly[8];
			int32_t ___SInt2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SInt3_OffsetPadding[12];
			int32_t ___SInt3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SInt3_OffsetPadding_forAlignmentOnly[12];
			int32_t ___SInt3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			uint64_t ___ULong0;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint64_t ___ULong0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___ULong1_OffsetPadding[8];
			uint64_t ___ULong1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___ULong1_OffsetPadding_forAlignmentOnly[8];
			uint64_t ___ULong1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			int64_t ___SLong0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int64_t ___SLong0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SLong1_OffsetPadding[8];
			int64_t ___SLong1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SLong1_OffsetPadding_forAlignmentOnly[8];
			int64_t ___SLong1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			float ___Float0;
		};
		#pragma pack(pop, tp)
		struct
		{
			float ___Float0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Float1_OffsetPadding[4];
			float ___Float1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Float1_OffsetPadding_forAlignmentOnly[4];
			float ___Float1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Float2_OffsetPadding[8];
			float ___Float2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Float2_OffsetPadding_forAlignmentOnly[8];
			float ___Float2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Float3_OffsetPadding[12];
			float ___Float3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Float3_OffsetPadding_forAlignmentOnly[12];
			float ___Float3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			double ___Double0;
		};
		#pragma pack(pop, tp)
		struct
		{
			double ___Double0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Double1_OffsetPadding[8];
			double ___Double1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Double1_OffsetPadding_forAlignmentOnly[8];
			double ___Double1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			v64_t9C4037532D386FF1E9B95E5FBD01FEF472AC1F96 ___Lo64;
		};
		#pragma pack(pop, tp)
		struct
		{
			v64_t9C4037532D386FF1E9B95E5FBD01FEF472AC1F96 ___Lo64_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Hi64_OffsetPadding[8];
			v64_t9C4037532D386FF1E9B95E5FBD01FEF472AC1F96 ___Hi64;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Hi64_OffsetPadding_forAlignmentOnly[8];
			v64_t9C4037532D386FF1E9B95E5FBD01FEF472AC1F96 ___Hi64_forAlignmentOnly;
		};
	};
};
struct DependencyHandle_t73038501598DF9B7E83BF8486D87B9DED6200B15 
{
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___WriteFence;
	int32_t ___NumReadFences;
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___TypeIndex;
};
struct AccessMode_t08155A76104B91A50C66C3D69AB1F04FF5D91B5D 
{
	int32_t ___value__;
};
struct ChangedFilter_t55DB3F02469E53626DA400F9A19ABE3183B485EE 
{
	int32_t ___Count;
	U3CIndexInEntityQueryU3Ee__FixedBuffer_t16145BD96786E58BD62F3D7542DA41E279C0E65A ___IndexInEntityQuery;
};
struct SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8 
{
	int32_t ___Count;
	U3CIndexInEntityQueryU3Ee__FixedBuffer_tF74E8C082C63D1F5EC4A529909287F360012EDD9 ___IndexInEntityQuery;
	U3CSharedComponentIndexU3Ee__FixedBuffer_t6678D7BCFF071F01975BEAE7FF8C6FA532C1FDA0 ___SharedComponentIndex;
};
struct MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84 
{
	uint8_t* ___m_pointer;
	int64_t ___m_bytes;
	Union_t651696C44E98CE15C53FE2628FA73E4B102D6C21 ___m_union;
};
struct HeaderLoadStatus_t046D96BC798CB4BD1A397AAA40A2987D4A685DC4 
{
	int32_t ___value__;
};
struct StateAllocLevel1_t93303AA6CAA1A10E9819D11E131EDD90DE20043D 
{
	uint64_t ___FreeBits;
	SystemState_t1AAA7F65EAD5CC5666D3F0360B309F9DF032E47D* ___States;
	U3CVersionU3Ee__FixedBuffer_tC6868E0A9CCAFCBB64E75DD215D2797B4C4EC116 ___Version;
	U3CTypeHashU3Ee__FixedBuffer_tFC7E207A0C02CC8C3BDE8AB86460FD7CD7C7C6B6 ___TypeHash;
};
struct StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020 
{
	StreamingStateData_tB4ECCAB2ECCD0555A32604F161D9B80D9FA42B3A ___State;
};
struct StrBoolArray_tCA66E1F688A4BC6FA749195F867F59E523508DD6 
{
	U3CBitsU3Ee__FixedBuffer_tFED81968B5AEB075B5560B55A16A31C5F01A83BD ___Bits;
};
struct UnsafeHashSet_1_t982205DCD82C95EDB86B40937DA9AC768D4723A8 
{
	HashMapHelper_1_tF4097677DF54F9B7101CE52DA301CACDF02D8AD9 ___m_Data;
};
struct ArchetypeListMap_t9B5C7F814630CC95D11AE3A6D713646CDE4A33AD 
{
	UnsafeList_1_tA2B6A040C4F2656D88ABB4345257ADE8F2F30F35 ___hashes;
	UnsafePtrList_1_t3BA56CBE50A217517D1FA78C345C0AF8242F8088 ___archetypes;
	int32_t ___emptyNodes;
	int32_t ___skipNodes;
};
struct BufferAllocatorHeap_t8B23AEAD3FF0104ED854068D0451346730DAC3AE 
{
	UnsafeList_1_t7F37B06177929AC50704A82689AED5BBFE830613 ___Buffers;
	UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4 ___FreeList;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Handle;
	int32_t ___BufferSizeInBytes;
};
struct ComponentDependencyManager_t88715270EBD172A299D4F6DB471143B7E0BCDB47 
{
	uint16_t* ___m_TypeArrayIndices;
	DependencyHandle_t73038501598DF9B7E83BF8486D87B9DED6200B15* ___m_DependencyHandles;
	uint16_t ___m_DependencyHandlesCount;
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* ___m_ReadJobFences;
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___EntityTypeIndex;
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___m_ExclusiveTransactionDependency;
	uint8_t ____IsInTransaction;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___m_Marker;
	WorldUnmanaged_t7B736084B2D4749A9CE36AD9A7F9D930DAA9F88F ___m_World;
};
struct ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA 
{
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___TypeIndex;
	int32_t ___AccessModeType;
};
struct ContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7 
{
	Hash128_t2EA8F45F10BC2DF40B0CE9AE04F222072EB1345B ___Value;
};
struct DoubleRewindableAllocators_t8D3615CDAAECEE59D64F85F9E0F46D07168A7069 
{
	RewindableAllocator_tB18F8ADC8F2EE36E1F51FCCCFF0AC093108EF254* ___Pointer;
	AllocatorHelper_1_tE2F3FBC837659F89E544184EDA24A6DDB9FD35D0 ___UpdateAllocatorHelper0;
	AllocatorHelper_1_tE2F3FBC837659F89E544184EDA24A6DDB9FD35D0 ___UpdateAllocatorHelper1;
};
struct EntityCommandBufferData_t88C8EFD5BBEF42F8008AF73FA2C27B60E5A31DC2 
{
	EntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB ___m_MainThreadChain;
	EntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB* ___m_ThreadedChains;
	int32_t ___m_RecordedChainCount;
	int32_t ___m_MinimumChunkSize;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___m_Allocator;
	int32_t ___m_PlaybackPolicy;
	bool ___m_ShouldPlayback;
	bool ___m_DidPlayback;
	bool ___m_ForceFullDispose;
	Entity_t56176FC78C475061A82383D9E0CEE352C6C52ABD ___m_Entity;
	int32_t ___m_BufferWithFixupsCount;
	UnsafeAtomicCounter32_tB925055F9F609BFEE32CC1CB3AA04D0B75690B62 ___m_BufferWithFixups;
	int32_t ___m_CommandBufferID;
};
struct EntityCommandBufferData_t88C8EFD5BBEF42F8008AF73FA2C27B60E5A31DC2_marshaled_pinvoke
{
	EntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB_marshaled_pinvoke ___m_MainThreadChain;
	EntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB* ___m_ThreadedChains;
	int32_t ___m_RecordedChainCount;
	int32_t ___m_MinimumChunkSize;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___m_Allocator;
	int32_t ___m_PlaybackPolicy;
	int32_t ___m_ShouldPlayback;
	int32_t ___m_DidPlayback;
	int32_t ___m_ForceFullDispose;
	Entity_t56176FC78C475061A82383D9E0CEE352C6C52ABD ___m_Entity;
	int32_t ___m_BufferWithFixupsCount;
	UnsafeAtomicCounter32_tB925055F9F609BFEE32CC1CB3AA04D0B75690B62 ___m_BufferWithFixups;
	int32_t ___m_CommandBufferID;
};
struct EntityCommandBufferData_t88C8EFD5BBEF42F8008AF73FA2C27B60E5A31DC2_marshaled_com
{
	EntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB_marshaled_com ___m_MainThreadChain;
	EntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB* ___m_ThreadedChains;
	int32_t ___m_RecordedChainCount;
	int32_t ___m_MinimumChunkSize;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___m_Allocator;
	int32_t ___m_PlaybackPolicy;
	int32_t ___m_ShouldPlayback;
	int32_t ___m_DidPlayback;
	int32_t ___m_ForceFullDispose;
	Entity_t56176FC78C475061A82383D9E0CEE352C6C52ABD ___m_Entity;
	int32_t ___m_BufferWithFixupsCount;
	UnsafeAtomicCounter32_tB925055F9F609BFEE32CC1CB3AA04D0B75690B62 ___m_BufferWithFixups;
	int32_t ___m_CommandBufferID;
};
struct EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B 
{
	uint32_t ___RequiredChangeVersion;
	SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8 ___Shared;
	ChangedFilter_t55DB3F02469E53626DA400F9A19ABE3183B485EE ___Changed;
	uint32_t ____UseOrderFiltering;
};
struct FixedString512Bytes_t0C425B0F2C07FEA1642C32BF8559116DF2BFF50E 
{
	union
	{
		struct
		{
			uint16_t ___utf8LengthInBytes;
			alignas(1) FixedBytes510_t95B284C3FF966246998B23701C3F0F55C6BD7973 ___bytes;
		};
		uint8_t FixedString512Bytes_t0C425B0F2C07FEA1642C32BF8559116DF2BFF50E__padding[512];
	};
};
struct ManagedDeferredCommands_t3585F563AFB19DC3B6EB9250562B62FC78A0E9A1 
{
	EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F* ___ECS;
	UnsafeAppendBuffer_t9EC160EA10485CD9DD96EDCBCEA06C7BCEF81500 ___CommandBuffer;
};
struct RuntimeGlobalObjectId_tC6329FB06BA5199F5848D9355CF10D6D7CACEA00 
{
	int64_t ___SceneObjectIdentifier0;
	int64_t ___SceneObjectIdentifier1;
	Hash128_t2EA8F45F10BC2DF40B0CE9AE04F222072EB1345B ___AssetGUID;
	int32_t ___IdentifierType;
};
struct UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67 
{
	UntypedUnsafeList_tB7A46F76589C71832F1147292E5123FB99E199B2 ___m_UntypedListData;
};
struct NodeHeader_tC393A021B9635C19BEC9CEEA905E76D4B90FDC4F 
{
	uint64_t ___NodeTypeHash;
	Hash128_t2EA8F45F10BC2DF40B0CE9AE04F222072EB1345B ___Id;
	int32_t ___Size;
	int32_t ___NextSiblingOffset;
	int32_t ___ChildrenCount;
	int64_t ___MetadataStartingOffset;
	int32_t ___MetadataSize;
	int64_t ___DataStartingOffset;
	int64_t ___DataSize;
};
struct HeaderLoadResult_t86A12E9A873A437C5217B245451D083016BE7FED 
{
	int32_t ___Status;
	UnsafeList_1_tDA08D23291A006354D190890E73B9970FEFADE6E ___SectionPaths;
	BlobAssetReference_1_tD5149596D95DFDE07586D2F21EBDCE9F21C30A24 ___SceneMetaData;
	alignas(IL2CPP_SIZEOF_VOID_P) BlobAssetOwner_t48F662D0AF49A5BBFD013EF59C8BD9C335A854AD ___HeaderBlobOwner;
};
struct BufferAllocator_tBE0961382918F823D26ED519F45D281AA06494D4 
{
	BufferAllocatorHeap_t8B23AEAD3FF0104ED854068D0451346730DAC3AE ___Allocator;
};
struct EntityNameStoreAccess_tF60EECC3572FC72F6BBE88730AC291BE9B45BAD6 
{
	EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F* ___m_EntityComponentStore;
	UnsafeHashSet_1_t982205DCD82C95EDB86B40937DA9AC768D4723A8 ___m_EntitiesNameSet;
	EntityNameStoreAccessData_t5AC842F68D9F5083E23B12C17F81F43535F2ED1F* ___m_Data;
};
struct EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574 
{
	EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* ____Access;
	EntityQueryData_t20DB32E7BB3F8732C371E45E8A8CEBCE62B61C26* ____QueryData;
	EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B ____Filter;
	uint64_t ____SeqNo;
	GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC ____CachedState;
};
struct UntypedWeakReferenceId_tE6BA94FD975EA12B639C0A568532BD1AB874492A 
{
	RuntimeGlobalObjectId_tC6329FB06BA5199F5848D9355CF10D6D7CACEA00 ___GlobalId;
	int16_t ___GenerationType;
};
struct HeaderData_t5CE38A1426623168DB817F1D87E639856A2614B3 
{
	uint8_t* ___Data;
	ReadHandle_t71C4E3C6D2A80E1A200DA2C22346363F9A5EBEBB ___ReadHandle;
	FixedString512Bytes_t0C425B0F2C07FEA1642C32BF8559116DF2BFF50E ___SceneLoadDir;
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___JobHandle;
	ReadCommand_t5DB46BD58D686FDDFBD8AB7600B9CF676DC7D97F ___ReadCommand;
	HeaderLoadResult_t86A12E9A873A437C5217B245451D083016BE7FED ___HeaderLoadResult;
};
struct BlockAllocator_tE609150FFA2B257EBBBEEEFDF795FB7073A4E7AE 
{
	BufferAllocator_tBE0961382918F823D26ED519F45D281AA06494D4 ___m_bufferAllocator;
	UnsafeList_1_t6C5E84D303190B625F3759C244502E1735453718 ___m_allocations;
	int32_t ___m_currentBlockIndex;
	uint8_t* ___m_nextPtr;
};
struct EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F 
{
	int32_t* ___m_ComponentTypeOrderVersion;
	BlockAllocator_tE609150FFA2B257EBBBEEEFDF795FB7073A4E7AE ___m_ArchetypeChunkAllocator;
	UnsafePtrList_1_t3BA56CBE50A217517D1FA78C345C0AF8242F8088 ___m_Archetypes;
	ArchetypeListMap_t9B5C7F814630CC95D11AE3A6D713646CDE4A33AD ___m_TypeLookup;
	int32_t ___m_ManagedComponentIndex;
	int32_t ___m_ManagedComponentIndexCapacity;
	UnsafeAppendBuffer_t9EC160EA10485CD9DD96EDCBCEA06C7BCEF81500 ___m_ManagedComponentFreeIndex;
	ManagedDeferredCommands_t3585F563AFB19DC3B6EB9250562B62FC78A0E9A1 ___ManagedChangesTracker;
	int32_t ___m_SharedComponentVersion;
	int32_t ___m_SharedComponentGlobalVersion;
	int32_t ___m_UnmanagedSharedComponentCount;
	UnsafeList_1_t81DA7B1F50305CF2C5A3DAE7C5027E809A808B8C ___m_UnmanagedSharedComponentsByType;
	UnsafeList_1_tEE6D0269E6E8E59E96623AA3410F283FE7B8CF65 ___m_UnmanagedSharedComponentTypes;
	UnsafeList_1_tA21F92C4A814A112A95FFC7861B906E3523E4EEF ___m_UnmanagedSharedComponentInfo;
	UnsafeParallelMultiHashMap_2_tF97D13A4436BE5A45CEFAE2066E0ABE4AB22DC94 ___m_HashLookup;
	ChunkListChanges_tC57E06E14D1D6D3D87675D05619E0539A86564D8 ___m_ChunkListChangesTracker;
	uint64_t ___m_WorldSequenceNumber;
	uint64_t ___m_NextChunkSequenceNumber;
	uint32_t ___m_GlobalSystemVersion;
	int32_t ___m_IntentionallyInconsistent;
	uint32_t ___m_ArchetypeTrackingVersion;
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___m_LinkedGroupType;
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___m_ChunkHeaderType;
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___m_PrefabType;
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___m_OmitLinkedEntityGroupFromPrefabInstanceType;
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___m_CleanupEntityType;
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___m_DisabledType;
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___m_EntityType;
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___m_SystemInstanceType;
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA ___m_ChunkHeaderComponentType;
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA ___m_EntityComponentType;
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA ___m_SimulateComponentType;
	TypeInfo_tD43B08A8D19156EEC98399693A96161F02139654* ___m_TypeInfos;
	EntityOffsetInfo_tAA68D1FC74ADF57FB76987377354ED848C7CC9D1* ___m_EntityOffsetInfos;
	int32_t ___m_DebugOnlyManagedAccess;
	uint8_t ___memoryInitPattern;
	uint8_t ___useMemoryInitPattern;
	EntityNameStoreAccess_tF60EECC3572FC72F6BBE88730AC291BE9B45BAD6 ___m_NameStoreAccess;
};
struct EntityQueryManager_tCD6CFC49CDD19B4E639F214958CC0B81011ACD0A 
{
	ComponentDependencyManager_t88715270EBD172A299D4F6DB471143B7E0BCDB47* ___m_DependencyManager;
	BlockAllocator_tE609150FFA2B257EBBBEEEFDF795FB7073A4E7AE ___m_EntityQueryDataChunkAllocator;
	UnsafePtrList_1_t9303472093C8513F7E98E3EFE8C3560679C4CAA6 ___m_EntityQueryDatas;
	UntypedUnsafeParallelHashMap_t926EFEEE26C4DE4FE2FA5A27FEA1D83CDD4B1B17 ___m_EntityQueryDataCacheUntyped;
	int32_t ___m_EntityQueryMasksAllocated;
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___m_disabledTypeIndex;
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___m_prefabTypeIndex;
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___m_systemInstanceTypeIndex;
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___m_chunkHeaderTypeIndex;
};
struct EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36 
{
	EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F ___m_EntityComponentStore;
	EntityQueryManager_tCD6CFC49CDD19B4E639F214958CC0B81011ACD0A ___m_EntityQueryManager;
	ComponentDependencyManager_t88715270EBD172A299D4F6DB471143B7E0BCDB47 ___m_DependencyManager;
	UnsafeList_1_t6C5E84D303190B625F3759C244502E1735453718 ___m_ManagedReferenceIndexList;
	EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90 ___m_UniversalQuery;
	EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90 ___m_UniversalQueryWithChunks;
	EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90 ___m_UniversalQueryWithSystems;
	EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90 ___m_UniversalQueryWithChunksAndSystems;
	EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90 ___m_EntityGuidQuery;
	WorldUnmanaged_t7B736084B2D4749A9CE36AD9A7F9D930DAA9F88F ___m_WorldUnmanaged;
	int32_t ___m_ManagedAccessHandle;
	EntityArchetype_tE1D293B55B4783642BB593531A57460AB7709354 ___m_EntityAndSimulateOnlyArchetype;
	UntypedUnsafeParallelHashMap_t926EFEEE26C4DE4FE2FA5A27FEA1D83CDD4B1B17 ___m_AliveEntityQueries;
};
struct Comparer_1_t7EDCB50F141B8333E02C67781CAC2D41381F0563_StaticFields
{
	Comparer_1_t7EDCB50F141B8333E02C67781CAC2D41381F0563* ___defaultComparer;
};
struct Comparer_1_tFA27DAC2908F666A385A0E5699BB66735365343B_StaticFields
{
	Comparer_1_tFA27DAC2908F666A385A0E5699BB66735365343B* ___defaultComparer;
};
struct Comparer_1_t58CF625431A0184A14FF0A33D14229F8F6EA3C98_StaticFields
{
	Comparer_1_t58CF625431A0184A14FF0A33D14229F8F6EA3C98* ___defaultComparer;
};
struct Comparer_1_t535E02B3998AA8B49230077EF0DFCB16BA44C985_StaticFields
{
	Comparer_1_t535E02B3998AA8B49230077EF0DFCB16BA44C985* ___defaultComparer;
};
struct EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8_StaticFields
{
	EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* ___defaultComparer;
};
struct EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B_StaticFields
{
	EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* ___defaultComparer;
};
struct EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B_StaticFields
{
	EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* ___defaultComparer;
};
struct EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70_StaticFields
{
	EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* ___defaultComparer;
};
struct EqualityComparer_1_t458C8DC3748A89A213F4738B57D3742C4896ABE9_StaticFields
{
	EqualityComparer_1_t458C8DC3748A89A213F4738B57D3742C4896ABE9* ___defaultComparer;
};
struct Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_StaticFields
{
	UInt32U5BU5D_t02FBD658AD156A17574ECE6106CF1FBFCC9807FA* ___crctab;
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
struct StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020_StaticFields
{
	int32_t ___SECRET_LIMIT;
	int32_t ___NB_STRIPES_PER_BLOCK;
	int32_t ___INTERNAL_BUFFER_SIZE;
	int32_t ___INTERNAL_BUFFER_STRIPES;
};
struct EntityCommandBufferData_t88C8EFD5BBEF42F8008AF73FA2C27B60E5A31DC2_StaticFields
{
	int32_t ___ALIGN_64_BIT;
};
struct EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_StaticFields
{
	SharedStatic_1_t0A9894CA2483CA9491C550F8D66FBA5213718E9F ____bfp_ResetFilter;
	SharedStatic_1_t0A9894CA2483CA9491C550F8D66FBA5213718E9F ____bfp_FreeCachedState;
};
struct EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_StaticFields
{
	SharedStatic_1_t0A9894CA2483CA9491C550F8D66FBA5213718E9F ___s_ManagedPlaybackTrampoline;
	RuntimeObject* ___s_DelegateGCPrevention;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif


IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* EqualityComparer_1_get_Default_m7D273CC532DC2164C9C86D28C639FDEA38173C88_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Comparer_1_t7EDCB50F141B8333E02C67781CAC2D41381F0563* Comparer_1_get_Default_mE45154132033749FD101CB1689E0375B42C4B407_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* EqualityComparer_1_get_Default_m7F71AAC0046A3CB8C4CEB06A5A52A1269AF7023D_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Comparer_1_tFA27DAC2908F666A385A0E5699BB66735365343B* Comparer_1_get_Default_m84816461184ACF98D5F66D45F43652587DA47B4F_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* EqualityComparer_1_get_Default_m80EE5C179E01BB38904781592AC72F8137541D7E_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Comparer_1_t58CF625431A0184A14FF0A33D14229F8F6EA3C98* Comparer_1_get_Default_m5B4E9A09E85C87692450A9D2BC5C99C3E5DC1E36_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* EqualityComparer_1_get_Default_m41DB4C0E0A508A8326E903331DC63D410B7AB9C4_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStrCmpIntRes2_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m5D9BE946098FA4C7FC8CC23DEE63A0877E8D6C8B_gshared (uint8_t* ___0_a, int32_t ___1_alen, uint8_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStrCmpIntRes2_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_mB3F9377B1A57D35D5514DEF77B3D9279A8622960_gshared (int16_t* ___0_a, int32_t ___1_alen, int16_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStrCmpIntRes2_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_mA23FD3A0C3B4448E4721DA31DA7B4B93A636A3FD_gshared (int8_t* ___0_a, int32_t ___1_alen, int8_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStrCmpIntRes2_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m331D979D640CF9DF04C505875F9FB702E217B2AB_gshared (uint16_t* ___0_a, int32_t ___1_alen, uint16_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_ComputeStrmOutput_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1CC4D51DF3F513318DCC288B066D0018EAF9C235_gshared (int32_t ___0_len, int32_t ___1_imm8, uint8_t ___2_allOnesT, int32_t ___3_intRes2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_ComputeStrmOutput_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_mE92FFA321425E5808CD20616DC308BA7B36886E8_gshared (int32_t ___0_len, int32_t ___1_imm8, int16_t ___2_allOnesT, int32_t ___3_intRes2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_ComputeStrmOutput_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m5EFDDE5126FDB6BF9F9ED55B39751B517522C455_gshared (int32_t ___0_len, int32_t ___1_imm8, int8_t ___2_allOnesT, int32_t ___3_intRes2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_ComputeStrmOutput_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_mD44F4B084A230ACD38B4FCF13923F8986AFF0AB1_gshared (int32_t ___0_len, int32_t ___1_imm8, uint16_t ___2_allOnesT, int32_t ___3_intRes2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStringLength_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mD30812062AA4852D166ABCDF3D79FDD1856F173A_gshared (uint8_t* ___0_ptr, int32_t ___1_max, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStringLength_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m3EBC75C6F39A7B1A5F62D88877C87C9F3B5617A3_gshared (int16_t* ___0_ptr, int32_t ___1_max, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStringLength_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m73215CC1A28F076B0D2472385756C7AF58CBA171_gshared (int8_t* ___0_ptr, int32_t ___1_max, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStringLength_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m000E8D7B908376D69E48EACF3E6811C4DEE7A05D_gshared (uint16_t* ___0_ptr, int32_t ___1_max, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void* UnsafeUtilityExtensions_AddressOf_TisContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7_m85266A04E5B522991EBAA42F3FC3CCB8519D0C5D_gshared_inline (ContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7* ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7_m65ADB6FA4CDF3D140FA70FD5EECA5FB8FBFCFC7C_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StreamingState_Update_TisContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7_mF9E800270D3570EFABD72A330AC68B875E236375_gshared (StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020* __this, ContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7* ___0_input, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void* UnsafeUtilityExtensions_AddressOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mEED178608CB87EEA96C8A7B57B13B0172B827EEC_gshared_inline (int32_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mED481D505BF43CBD96972069EDD4E3509BE84931_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StreamingState_Update_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mAEB133EB1AAAA88E4A720F913C58CAB0DA1F7B5B_gshared (StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020* __this, int32_t* ___0_input, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StreamingState_Update_TisIl2CppFullySharedGenericStruct_m301FBB6A80BBA46BB5AC2B0DF206CAB72593DE1D_gshared (StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020* __this, Il2CppFullySharedGenericStruct* ___0_input, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t* Array_Resize_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mEE512F558B8B16B19497E4DF8445518F289534BE_gshared (int32_t* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* Array_Resize_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m66D39A0700C852DFD578157D9E4862A8230233F3_gshared (MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisAllocatorHelper_1_t0290FF01C365B75408A8E7D00CC67BF0D92CB97B_m3EAEE0ECC422E640B90E49964F53573F9D59D9B7_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisAllocatorHelper_1_t0290FF01C365B75408A8E7D00CC67BF0D92CB97B_m2982C28E643EA6FD5D84036353B642C3169A6775_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_t1922B493DF75C945824746A291BE8AD04E7A6910_mEACF1ADDBA4E72AA75650188B2C43D216732A0A2_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_t1922B493DF75C945824746A291BE8AD04E7A6910_mDC1000E76EB4699ECD216942EA8B893E2414871A_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_tB74757C88AFC77B83E59303BFF915A4BDED9A5A5_mEA64A1F1EC2CEE94044343CE8EFB46206629AB77_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_tB74757C88AFC77B83E59303BFF915A4BDED9A5A5_m148858A5CC66194B13FF0CD3CFD111AEA0AE3979_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_tF4097677DF54F9B7101CE52DA301CACDF02D8AD9_mBE257998246FC27D92E08B57914641E77B6D310A_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_tF4097677DF54F9B7101CE52DA301CACDF02D8AD9_mD632058B768B6CFE85AFD1CC15A00EF3CF56D26F_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_t55F6D796BFB8E5F42BE6369F25DF63EC9F81AFBC_m4C50BC02467EFFE9FE6A6A9671C70458FD444C55_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_t55F6D796BFB8E5F42BE6369F25DF63EC9F81AFBC_mC03E522A34FA831417562DBAC1448B62C17F2757_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m8058188B2884F5674C5A4C9C7AFC0A59000CC56F_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m9D33FAB445EBAAEAB91BED2D158B3290B610D47E_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_t52DEB1D232D9067231DF945A04789178DDC0119D_m77A04380E3226A5E4F4A53E9B2C20D8C7AB95983_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_t52DEB1D232D9067231DF945A04789178DDC0119D_m54E02D815E5622CFC48D78494D838723A951EED5_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_t2DD122ED66B38FE6A3FF1935D7FDFE0E07AA7C09_m978FAC1AAB7675C2941BCE49E452082F18DD4C53_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_t2DD122ED66B38FE6A3FF1935D7FDFE0E07AA7C09_m06B8198277B6B1F22CF35D804493FB2EBAE1E9AE_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_tE18033C6B74BE6B9BAE79F2ADD9BC2C916DFA729_m56495057B39DFE5087EA47F7331FD40597492A2A_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_tE18033C6B74BE6B9BAE79F2ADD9BC2C916DFA729_mF8605C6E2C9BE41D89B23148AA5A7F67596C0D63_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_m3446503708EF53FF3664993B371F061F2C98A44F_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_mC94DEDD2611C7C84632B957D3FDB324F2C85EA7A_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_tFE70D47D7D4D5A59CFA6D8E68852A7EE5BDB4854_m806F9CFE9718FE6DF13E117477C17767D1708279_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_tFE70D47D7D4D5A59CFA6D8E68852A7EE5BDB4854_m0660231136B868BA362E8045755B0F3C57CC67BA_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m9DD3BAE2675B37478EA2C9AA9DAFD2C6C1F5BF4E_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m796E3C1D5F3A55A9EFFD1AA98C09AB788198C7A1_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD_m201D21D3AC9187C9EFEF16F0B593FAC6BE19EE72_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD_m70E5F2C375F3B4039114929EBDF86DFCBF1EF99C_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515_m067749C993CAF4A3AA0673C46673216D995516DE_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515_m756E0E44BD2515C8949896575600531B61F5B16B_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m9108AF5F196154FF71AD62376A7411B92391F000_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m219DC3BB1EF8E9E18A66470555A9974E2C7D9EC6_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeRingQueue_1_t916A7CB801E880FD1A00447CC4815827882753ED_m6F51DC601209DBB54B5546FC945C0B69D996922D_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeRingQueue_1_t916A7CB801E880FD1A00447CC4815827882753ED_m84ACE3D5E56DC5439E2DA35A7C00916492258492_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisBlobAssetBatch_tE7DAEECF09D38F983FE3F829F7774B40F4FD6B46_m1B05D4B205551B035C03FC4B7D1757D2D1A5C4CD_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisBlobAssetBatch_tE7DAEECF09D38F983FE3F829F7774B40F4FD6B46_mBBE1A454562855891445DF33C1BB6CDA67E79903_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisBlobAssetHeader_t3EC5AD955B287949B57D36BBDE25A4D1BA85E639_mCC8381920C8736C7CFCA6E556B49BE02B71FE34C_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisBlobAssetHeader_t3EC5AD955B287949B57D36BBDE25A4D1BA85E639_mEBE2379486D6F502175AFA8545E6B0459F1F340C_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m97C7D5E5DE74DC60A0ECAA914830BEDF2C46ACAA_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mB152D3C658FB48DEDB6E662EEB0C91018E7F2857_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisChainCleanup_t720381A951125FF2EAA04EA1E544B86820F30122_mD5270B21C83F2AE30AEA6AABCBF5AC537D97A6ED_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisChainCleanup_t720381A951125FF2EAA04EA1E544B86820F30122_m12E55909AEBB7242169E344DD51218DBDA18F9F6_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisDoubleRewindableAllocators_t8D3615CDAAECEE59D64F85F9E0F46D07168A7069_m12CD64E162BDD4E9964F0A20D7221DF379B37569_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisDoubleRewindableAllocators_t8D3615CDAAECEE59D64F85F9E0F46D07168A7069_m92DFB3274CFF4B4484E6655675E1C1BF4AFB554E_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisDynamicBlobAssetBatch_tAF1A195EBA8DD36359A9439ED1BB2D99AD81F027_mB42BE557FD211C59CE7C30170B290F71275A669F_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisDynamicBlobAssetBatch_tAF1A195EBA8DD36359A9439ED1BB2D99AD81F027_m4C583B0CA45B53C9B24E8765BCCC2A3B9A835EA1_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisECBChainHeapElement_tE83963A87C0B8B2EEDE315AF9DFF749A38C666DD_m72A92B4DB122FC4BC45F18FB459B619269492BC7_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisECBChainHeapElement_tE83963A87C0B8B2EEDE315AF9DFF749A38C666DD_mD8DF741CD89D1CEF5C4F9A493181908BDC5C56F5_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisECBChunk_tF8E51552DBA320AB90FCAE9CF1185FAFD3764F4F_mB2F57AD808C223787F8F2F7FE94F1CA09478E439_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisECBChunk_tF8E51552DBA320AB90FCAE9CF1185FAFD3764F4F_mA06C51E42878473801E3CCADF345EC64265E1025_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisEntity_t56176FC78C475061A82383D9E0CEE352C6C52ABD_m177EBEBF64B94FE192C8268AE6BCB9A563047C3C_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisEntity_t56176FC78C475061A82383D9E0CEE352C6C52ABD_mC7729F36ED36489AFC5470E4D99F9EE076B9C40B_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisEntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB_m8B4CD5160A7C28D2A54CB1E185FC3B59AD633CC2_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisEntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB_m70E6D94B1AA9B8CFBA3C7654EDB0E506990B6808_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisEntityCommandBufferData_t88C8EFD5BBEF42F8008AF73FA2C27B60E5A31DC2_mF2283D03D9B90B77481B9489B742165F9BB40EF5_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisEntityCommandBufferData_t88C8EFD5BBEF42F8008AF73FA2C27B60E5A31DC2_m47AC89596CA42CA8709BCEF28C51EC7D4611668F_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisEntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_m1D3A68FF0C582ADAE2A63F86DA45E6C4C5F713B9_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisEntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_mFB3AC0FA7E1BDFF541B132DAE5CEA6917E2A2E48_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisEntityNameStoreAccessData_t5AC842F68D9F5083E23B12C17F81F43535F2ED1F_mBBB7A97578412E4A4A38B2F30EE24BE2425B70B8_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisEntityNameStoreAccessData_t5AC842F68D9F5083E23B12C17F81F43535F2ED1F_m0B3318CDE808F4FA12401BD3E39E889029BAB85F_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisEntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_m2F10D3E64E3CB71DD152025B3F5A3103ABB2DD07_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisEntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_m2569D7A993EADB9F70B33CDC2042DE372E7C2F74_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m274F833CD001C63E56A22D8F42C76CE8C6CC39DF_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisIntPtr_t_mB2B3CFF1CB804C99734D4E2F5D8A8C9DB0D209A8_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisIntPtr_t_mB17C6C168D8CA088879EDD0D5B9923F70F5269B8_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m9648A6CA697B17B009BBEDCE817AF98293EA07A8_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_mC7DDA799532A41B6BBF8F2B145215B78667BE6CE_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_mEC9469DBD91362D6135B8F5A81E90486BF328075_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m742C058FF2011B81DD081BA92DC32E0E34CEAAC8_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m6C198B51ACD7B8EC62D5E0E75433C12BE9D65A58_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m8127223B00E08567EC09EF1D992F89C74F248AB0_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_mCCA7CED28D808054F7C94E1BF58205316AEE194F_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_m56B5B812224539B0C633BABE891ADDE1973580F6_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mB6FE4CAF35894EF5E357881DA5A0EAE9EDAD3754_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mC1EBD5161294EF95B8AC378DDF616869D287DC36_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_mEBEAA7CA1C71A37FA5CBCF89A0C9B78ABAD5C8C7_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m3DF404928C7038CCD5C05BBBA41C4B2FD35A4253_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m25193E03B20C96400F243B7A682AF5BB8F030297_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_mD84C2AFFB4ED036B913CEAD2FBF8A60E9C3A017D_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m79CAC169FC4593612624CB619E7D6F6FD7447517_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m5892DF1B875736B0E3612716E560A4E4AD5F6591_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUntypedWeakReferenceId_tE6BA94FD975EA12B639C0A568532BD1AB874492A_mFAA6F9C6A87B112BBD85F22709B4E18563AA5593_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUntypedWeakReferenceId_tE6BA94FD975EA12B639C0A568532BD1AB874492A_m2BDC205D9F080390F4B1A1097C470377D56579B0_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisDependencyHandle_t73038501598DF9B7E83BF8486D87B9DED6200B15_m372324DEBD6B906BB1927888F56DCBFBDC0DAC4C_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisDependencyHandle_t73038501598DF9B7E83BF8486D87B9DED6200B15_mCEA60798AAEFB42EBE92BFD4C8BFE55710CF1C17_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisNodeHeader_tC393A021B9635C19BEC9CEEA905E76D4B90FDC4F_mBBB27F335B5822EB0F181EA661BBCF2EA0519A3C_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisNodeHeader_tC393A021B9635C19BEC9CEEA905E76D4B90FDC4F_m4035D9C7ED339F00B807E15D0E453D04898D957F_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisBufferWithFixUp_tDFD5630DDFDBC051A462A026DFAEAA4A047FB3B6_m36A4E0B3E7DFA48026FB77ABAFB38AC1F999BB1F_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisBufferWithFixUp_tDFD5630DDFDBC051A462A026DFAEAA4A047FB3B6_m17951F8123258E416C8A1B9CB83A5DDE16A48C3C_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m4A0947EA519A2614EC19544513888A4DC5F42919_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m6AD8B4EF31CDD94CA734378B1443806DAFE68A05_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHeaderData_t5CE38A1426623168DB817F1D87E639856A2614B3_m9007635FD7971062D616805DB88395EEB43C920B_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisHeaderData_t5CE38A1426623168DB817F1D87E639856A2614B3_m47321A559CE5DBAD9A16E3C2DF5FF899C1410244_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisStateAllocLevel1_t93303AA6CAA1A10E9819D11E131EDD90DE20043D_m5D881A2223FC0BF2CB68E2EF91BF123C506FA136_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisStateAllocLevel1_t93303AA6CAA1A10E9819D11E131EDD90DE20043D_m821747001EAE919BBF7212AA6497A81A78FC2B36_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisPerChunkData_t1837BB30B95C4DD39A4908ECC71AB0B75DFF9135_mAB06B6453863E5D5F9644288D86E39C5848BEB1B_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisPerChunkData_t1837BB30B95C4DD39A4908ECC71AB0B75DFF9135_mA7BD893DD0B8C45C36CE456C8EC87EC2907E3172_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* EqualityComparer_1_CreateComparer_m22AF3135664449980749E1EC32EB92DB49219F9B_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* EqualityComparer_1_CreateComparer_mD5EE323D1C48F0C09CBB944FA81707B8FEE2DB6D_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* EqualityComparer_1_CreateComparer_m5F906E9B13BCCCDF51EF0852BD9E5E0065D185F8_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* EqualityComparer_1_CreateComparer_mEBC7BD29A8FD796A4DAA1DF4428B95D1BA4FB377_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void* ILSupport_AddressOf_TisContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7_m01D2486E5139DD8D56B5A959FBDD5892F83B5C23_gshared_inline (ContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7* ___0_thing, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void* ILSupport_AddressOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m8544D06F32E3436CE779A52F9FF3B72256EBAFAC_gshared_inline (int32_t* ___0_thing, const RuntimeMethod* method) ;

inline EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* EqualityComparer_1_get_Default_m7D273CC532DC2164C9C86D28C639FDEA38173C88_inline (const RuntimeMethod* method)
{
	return ((  EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* (*) (const RuntimeMethod*))EqualityComparer_1_get_Default_m7D273CC532DC2164C9C86D28C639FDEA38173C88_gshared_inline)(method);
}
inline Comparer_1_t7EDCB50F141B8333E02C67781CAC2D41381F0563* Comparer_1_get_Default_mE45154132033749FD101CB1689E0375B42C4B407 (const RuntimeMethod* method)
{
	return ((  Comparer_1_t7EDCB50F141B8333E02C67781CAC2D41381F0563* (*) (const RuntimeMethod*))Comparer_1_get_Default_mE45154132033749FD101CB1689E0375B42C4B407_gshared)(method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StrBoolArray_SetBit_m212C6D1A8A4C422AF979D6B3BC7CD5B9BD0F3F01 (StrBoolArray_tCA66E1F688A4BC6FA749195F867F59E523508DD6* __this, int32_t ___0_aindex, int32_t ___1_bindex, bool ___2_val, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78 (StrBoolArray_tCA66E1F688A4BC6FA749195F867F59E523508DD6* __this, int32_t ___0_aindex, int32_t ___1_bindex, const RuntimeMethod* method) ;
inline EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* EqualityComparer_1_get_Default_m7F71AAC0046A3CB8C4CEB06A5A52A1269AF7023D_inline (const RuntimeMethod* method)
{
	return ((  EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* (*) (const RuntimeMethod*))EqualityComparer_1_get_Default_m7F71AAC0046A3CB8C4CEB06A5A52A1269AF7023D_gshared_inline)(method);
}
inline Comparer_1_tFA27DAC2908F666A385A0E5699BB66735365343B* Comparer_1_get_Default_m84816461184ACF98D5F66D45F43652587DA47B4F (const RuntimeMethod* method)
{
	return ((  Comparer_1_tFA27DAC2908F666A385A0E5699BB66735365343B* (*) (const RuntimeMethod*))Comparer_1_get_Default_m84816461184ACF98D5F66D45F43652587DA47B4F_gshared)(method);
}
inline EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* EqualityComparer_1_get_Default_m80EE5C179E01BB38904781592AC72F8137541D7E_inline (const RuntimeMethod* method)
{
	return ((  EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* (*) (const RuntimeMethod*))EqualityComparer_1_get_Default_m80EE5C179E01BB38904781592AC72F8137541D7E_gshared_inline)(method);
}
inline Comparer_1_t58CF625431A0184A14FF0A33D14229F8F6EA3C98* Comparer_1_get_Default_m5B4E9A09E85C87692450A9D2BC5C99C3E5DC1E36 (const RuntimeMethod* method)
{
	return ((  Comparer_1_t58CF625431A0184A14FF0A33D14229F8F6EA3C98* (*) (const RuntimeMethod*))Comparer_1_get_Default_m5B4E9A09E85C87692450A9D2BC5C99C3E5DC1E36_gshared)(method);
}
inline EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* EqualityComparer_1_get_Default_m41DB4C0E0A508A8326E903331DC63D410B7AB9C4_inline (const RuntimeMethod* method)
{
	return ((  EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* (*) (const RuntimeMethod*))EqualityComparer_1_get_Default_m41DB4C0E0A508A8326E903331DC63D410B7AB9C4_gshared_inline)(method);
}
inline int32_t Sse4_2_ComputeStrCmpIntRes2_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m5D9BE946098FA4C7FC8CC23DEE63A0877E8D6C8B (uint8_t* ___0_a, int32_t ___1_alen, uint8_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, const RuntimeMethod* method)
{
	return ((  int32_t (*) (uint8_t*, int32_t, uint8_t*, int32_t, int32_t, int32_t, int32_t, const RuntimeMethod*))Sse4_2_ComputeStrCmpIntRes2_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m5D9BE946098FA4C7FC8CC23DEE63A0877E8D6C8B_gshared)(___0_a, ___1_alen, ___2_b, ___3_blen, ___4_len, ___5_imm8, ___6_allOnes, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStriOutput_mC9EFEB2A2B9B95760CEE913DF4EF7F57BE662123 (int32_t ___0_len, int32_t ___1_imm8, int32_t ___2_intRes2, const RuntimeMethod* method) ;
inline int32_t Sse4_2_ComputeStrCmpIntRes2_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_mB3F9377B1A57D35D5514DEF77B3D9279A8622960 (int16_t* ___0_a, int32_t ___1_alen, int16_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, const RuntimeMethod* method)
{
	return ((  int32_t (*) (int16_t*, int32_t, int16_t*, int32_t, int32_t, int32_t, int32_t, const RuntimeMethod*))Sse4_2_ComputeStrCmpIntRes2_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_mB3F9377B1A57D35D5514DEF77B3D9279A8622960_gshared)(___0_a, ___1_alen, ___2_b, ___3_blen, ___4_len, ___5_imm8, ___6_allOnes, method);
}
inline int32_t Sse4_2_ComputeStrCmpIntRes2_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_mA23FD3A0C3B4448E4721DA31DA7B4B93A636A3FD (int8_t* ___0_a, int32_t ___1_alen, int8_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, const RuntimeMethod* method)
{
	return ((  int32_t (*) (int8_t*, int32_t, int8_t*, int32_t, int32_t, int32_t, int32_t, const RuntimeMethod*))Sse4_2_ComputeStrCmpIntRes2_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_mA23FD3A0C3B4448E4721DA31DA7B4B93A636A3FD_gshared)(___0_a, ___1_alen, ___2_b, ___3_blen, ___4_len, ___5_imm8, ___6_allOnes, method);
}
inline int32_t Sse4_2_ComputeStrCmpIntRes2_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m331D979D640CF9DF04C505875F9FB702E217B2AB (uint16_t* ___0_a, int32_t ___1_alen, uint16_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, const RuntimeMethod* method)
{
	return ((  int32_t (*) (uint16_t*, int32_t, uint16_t*, int32_t, int32_t, int32_t, int32_t, const RuntimeMethod*))Sse4_2_ComputeStrCmpIntRes2_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m331D979D640CF9DF04C505875F9FB702E217B2AB_gshared)(___0_a, ___1_alen, ___2_b, ___3_blen, ___4_len, ___5_imm8, ___6_allOnes, method);
}
inline v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_ComputeStrmOutput_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1CC4D51DF3F513318DCC288B066D0018EAF9C235 (int32_t ___0_len, int32_t ___1_imm8, uint8_t ___2_allOnesT, int32_t ___3_intRes2, const RuntimeMethod* method)
{
	return ((  v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 (*) (int32_t, int32_t, uint8_t, int32_t, const RuntimeMethod*))Sse4_2_ComputeStrmOutput_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1CC4D51DF3F513318DCC288B066D0018EAF9C235_gshared)(___0_len, ___1_imm8, ___2_allOnesT, ___3_intRes2, method);
}
inline v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_ComputeStrmOutput_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_mE92FFA321425E5808CD20616DC308BA7B36886E8 (int32_t ___0_len, int32_t ___1_imm8, int16_t ___2_allOnesT, int32_t ___3_intRes2, const RuntimeMethod* method)
{
	return ((  v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 (*) (int32_t, int32_t, int16_t, int32_t, const RuntimeMethod*))Sse4_2_ComputeStrmOutput_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_mE92FFA321425E5808CD20616DC308BA7B36886E8_gshared)(___0_len, ___1_imm8, ___2_allOnesT, ___3_intRes2, method);
}
inline v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_ComputeStrmOutput_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m5EFDDE5126FDB6BF9F9ED55B39751B517522C455 (int32_t ___0_len, int32_t ___1_imm8, int8_t ___2_allOnesT, int32_t ___3_intRes2, const RuntimeMethod* method)
{
	return ((  v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 (*) (int32_t, int32_t, int8_t, int32_t, const RuntimeMethod*))Sse4_2_ComputeStrmOutput_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m5EFDDE5126FDB6BF9F9ED55B39751B517522C455_gshared)(___0_len, ___1_imm8, ___2_allOnesT, ___3_intRes2, method);
}
inline v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_ComputeStrmOutput_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_mD44F4B084A230ACD38B4FCF13923F8986AFF0AB1 (int32_t ___0_len, int32_t ___1_imm8, uint16_t ___2_allOnesT, int32_t ___3_intRes2, const RuntimeMethod* method)
{
	return ((  v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 (*) (int32_t, int32_t, uint16_t, int32_t, const RuntimeMethod*))Sse4_2_ComputeStrmOutput_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_mD44F4B084A230ACD38B4FCF13923F8986AFF0AB1_gshared)(___0_len, ___1_imm8, ___2_allOnesT, ___3_intRes2, method);
}
inline int32_t Sse4_2_ComputeStringLength_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mD30812062AA4852D166ABCDF3D79FDD1856F173A (uint8_t* ___0_ptr, int32_t ___1_max, const RuntimeMethod* method)
{
	return ((  int32_t (*) (uint8_t*, int32_t, const RuntimeMethod*))Sse4_2_ComputeStringLength_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mD30812062AA4852D166ABCDF3D79FDD1856F173A_gshared)(___0_ptr, ___1_max, method);
}
inline int32_t Sse4_2_ComputeStringLength_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m3EBC75C6F39A7B1A5F62D88877C87C9F3B5617A3 (int16_t* ___0_ptr, int32_t ___1_max, const RuntimeMethod* method)
{
	return ((  int32_t (*) (int16_t*, int32_t, const RuntimeMethod*))Sse4_2_ComputeStringLength_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m3EBC75C6F39A7B1A5F62D88877C87C9F3B5617A3_gshared)(___0_ptr, ___1_max, method);
}
inline int32_t Sse4_2_ComputeStringLength_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m73215CC1A28F076B0D2472385756C7AF58CBA171 (int8_t* ___0_ptr, int32_t ___1_max, const RuntimeMethod* method)
{
	return ((  int32_t (*) (int8_t*, int32_t, const RuntimeMethod*))Sse4_2_ComputeStringLength_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m73215CC1A28F076B0D2472385756C7AF58CBA171_gshared)(___0_ptr, ___1_max, method);
}
inline int32_t Sse4_2_ComputeStringLength_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m000E8D7B908376D69E48EACF3E6811C4DEE7A05D (uint16_t* ___0_ptr, int32_t ___1_max, const RuntimeMethod* method)
{
	return ((  int32_t (*) (uint16_t*, int32_t, const RuntimeMethod*))Sse4_2_ComputeStringLength_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m000E8D7B908376D69E48EACF3E6811C4DEE7A05D_gshared)(___0_ptr, ___1_max, method);
}
inline void* UnsafeUtilityExtensions_AddressOf_TisContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7_m85266A04E5B522991EBAA42F3FC3CCB8519D0C5D_inline (ContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7* ___0_value, const RuntimeMethod* method)
{
	return ((  void* (*) (ContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7*, const RuntimeMethod*))UnsafeUtilityExtensions_AddressOf_TisContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7_m85266A04E5B522991EBAA42F3FC3CCB8519D0C5D_gshared_inline)(___0_value, method);
}
inline int32_t UnsafeUtility_SizeOf_TisContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7_m65ADB6FA4CDF3D140FA70FD5EECA5FB8FBFCFC7C_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7_m65ADB6FA4CDF3D140FA70FD5EECA5FB8FBFCFC7C_gshared_inline)(method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StreamingState_Update_mD0C172FBC9AB99BC72DF8CC3665ABB61658AB9E5 (StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020* __this, void* ___0_input, int32_t ___1_length, const RuntimeMethod* method) ;
inline void StreamingState_Update_TisContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7_mF9E800270D3570EFABD72A330AC68B875E236375 (StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020* __this, ContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7* ___0_input, const RuntimeMethod* method)
{
	((  void (*) (StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020*, ContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7*, const RuntimeMethod*))StreamingState_Update_TisContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7_mF9E800270D3570EFABD72A330AC68B875E236375_gshared)(__this, ___0_input, method);
}
inline void* UnsafeUtilityExtensions_AddressOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mEED178608CB87EEA96C8A7B57B13B0172B827EEC_inline (int32_t* ___0_value, const RuntimeMethod* method)
{
	return ((  void* (*) (int32_t*, const RuntimeMethod*))UnsafeUtilityExtensions_AddressOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mEED178608CB87EEA96C8A7B57B13B0172B827EEC_gshared_inline)(___0_value, method);
}
inline int32_t UnsafeUtility_SizeOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mED481D505BF43CBD96972069EDD4E3509BE84931_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mED481D505BF43CBD96972069EDD4E3509BE84931_gshared_inline)(method);
}
inline void StreamingState_Update_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mAEB133EB1AAAA88E4A720F913C58CAB0DA1F7B5B (StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020* __this, int32_t* ___0_input, const RuntimeMethod* method)
{
	((  void (*) (StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020*, int32_t*, const RuntimeMethod*))StreamingState_Update_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mAEB133EB1AAAA88E4A720F913C58CAB0DA1F7B5B_gshared)(__this, ___0_input, method);
}
inline void StreamingState_Update_TisIl2CppFullySharedGenericStruct_m301FBB6A80BBA46BB5AC2B0DF206CAB72593DE1D (StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020* __this, Il2CppFullySharedGenericStruct* ___0_input, const RuntimeMethod* method)
{
	((  void (*) (StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020*, Il2CppFullySharedGenericStruct*, const RuntimeMethod*))StreamingState_Update_TisIl2CppFullySharedGenericStruct_m301FBB6A80BBA46BB5AC2B0DF206CAB72593DE1D_gshared)(__this, ___0_input, method);
}
inline int32_t* Array_Resize_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mEE512F558B8B16B19497E4DF8445518F289534BE (int32_t* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method)
{
	return ((  int32_t* (*) (int32_t*, int64_t, int64_t, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148, const RuntimeMethod*))Array_Resize_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mEE512F558B8B16B19497E4DF8445518F289534BE_gshared)(___0_oldPointer, ___1_oldCount, ___2_newCount, ___3_allocator, method);
}
inline MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* Array_Resize_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m66D39A0700C852DFD578157D9E4862A8230233F3 (MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method)
{
	return ((  MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* (*) (MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84*, int64_t, int64_t, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148, const RuntimeMethod*))Array_Resize_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m66D39A0700C852DFD578157D9E4862A8230233F3_gshared)(___0_oldPointer, ___1_oldCount, ___2_newCount, ___3_allocator, method);
}
inline int32_t UnsafeUtility_SizeOf_TisAllocatorHelper_1_t0290FF01C365B75408A8E7D00CC67BF0D92CB97B_m3EAEE0ECC422E640B90E49964F53573F9D59D9B7_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisAllocatorHelper_1_t0290FF01C365B75408A8E7D00CC67BF0D92CB97B_m3EAEE0ECC422E640B90E49964F53573F9D59D9B7_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisAllocatorHelper_1_t0290FF01C365B75408A8E7D00CC67BF0D92CB97B_m2982C28E643EA6FD5D84036353B642C3169A6775 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisAllocatorHelper_1_t0290FF01C365B75408A8E7D00CC67BF0D92CB97B_m2982C28E643EA6FD5D84036353B642C3169A6775_gshared)(method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void* Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380 (void* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, int64_t ___4_size, int32_t ___5_align, const RuntimeMethod* method) ;
inline int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_t1922B493DF75C945824746A291BE8AD04E7A6910_mEACF1ADDBA4E72AA75650188B2C43D216732A0A2_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisHashMapHelper_1_t1922B493DF75C945824746A291BE8AD04E7A6910_mEACF1ADDBA4E72AA75650188B2C43D216732A0A2_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_t1922B493DF75C945824746A291BE8AD04E7A6910_mDC1000E76EB4699ECD216942EA8B893E2414871A (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisHashMapHelper_1_t1922B493DF75C945824746A291BE8AD04E7A6910_mDC1000E76EB4699ECD216942EA8B893E2414871A_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_tB74757C88AFC77B83E59303BFF915A4BDED9A5A5_mEA64A1F1EC2CEE94044343CE8EFB46206629AB77_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisHashMapHelper_1_tB74757C88AFC77B83E59303BFF915A4BDED9A5A5_mEA64A1F1EC2CEE94044343CE8EFB46206629AB77_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_tB74757C88AFC77B83E59303BFF915A4BDED9A5A5_m148858A5CC66194B13FF0CD3CFD111AEA0AE3979 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisHashMapHelper_1_tB74757C88AFC77B83E59303BFF915A4BDED9A5A5_m148858A5CC66194B13FF0CD3CFD111AEA0AE3979_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_tF4097677DF54F9B7101CE52DA301CACDF02D8AD9_mBE257998246FC27D92E08B57914641E77B6D310A_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisHashMapHelper_1_tF4097677DF54F9B7101CE52DA301CACDF02D8AD9_mBE257998246FC27D92E08B57914641E77B6D310A_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_tF4097677DF54F9B7101CE52DA301CACDF02D8AD9_mD632058B768B6CFE85AFD1CC15A00EF3CF56D26F (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisHashMapHelper_1_tF4097677DF54F9B7101CE52DA301CACDF02D8AD9_mD632058B768B6CFE85AFD1CC15A00EF3CF56D26F_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_t55F6D796BFB8E5F42BE6369F25DF63EC9F81AFBC_m4C50BC02467EFFE9FE6A6A9671C70458FD444C55_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisHashMapHelper_1_t55F6D796BFB8E5F42BE6369F25DF63EC9F81AFBC_m4C50BC02467EFFE9FE6A6A9671C70458FD444C55_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_t55F6D796BFB8E5F42BE6369F25DF63EC9F81AFBC_mC03E522A34FA831417562DBAC1448B62C17F2757 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisHashMapHelper_1_t55F6D796BFB8E5F42BE6369F25DF63EC9F81AFBC_mC03E522A34FA831417562DBAC1448B62C17F2757_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m8058188B2884F5674C5A4C9C7AFC0A59000CC56F_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m8058188B2884F5674C5A4C9C7AFC0A59000CC56F_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m9D33FAB445EBAAEAB91BED2D158B3290B610D47E (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m9D33FAB445EBAAEAB91BED2D158B3290B610D47E_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_t52DEB1D232D9067231DF945A04789178DDC0119D_m77A04380E3226A5E4F4A53E9B2C20D8C7AB95983_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisHashMapHelper_1_t52DEB1D232D9067231DF945A04789178DDC0119D_m77A04380E3226A5E4F4A53E9B2C20D8C7AB95983_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_t52DEB1D232D9067231DF945A04789178DDC0119D_m54E02D815E5622CFC48D78494D838723A951EED5 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisHashMapHelper_1_t52DEB1D232D9067231DF945A04789178DDC0119D_m54E02D815E5622CFC48D78494D838723A951EED5_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_t2DD122ED66B38FE6A3FF1935D7FDFE0E07AA7C09_m978FAC1AAB7675C2941BCE49E452082F18DD4C53_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisHashMapHelper_1_t2DD122ED66B38FE6A3FF1935D7FDFE0E07AA7C09_m978FAC1AAB7675C2941BCE49E452082F18DD4C53_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_t2DD122ED66B38FE6A3FF1935D7FDFE0E07AA7C09_m06B8198277B6B1F22CF35D804493FB2EBAE1E9AE (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisHashMapHelper_1_t2DD122ED66B38FE6A3FF1935D7FDFE0E07AA7C09_m06B8198277B6B1F22CF35D804493FB2EBAE1E9AE_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_tE18033C6B74BE6B9BAE79F2ADD9BC2C916DFA729_m56495057B39DFE5087EA47F7331FD40597492A2A_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisHashMapHelper_1_tE18033C6B74BE6B9BAE79F2ADD9BC2C916DFA729_m56495057B39DFE5087EA47F7331FD40597492A2A_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_tE18033C6B74BE6B9BAE79F2ADD9BC2C916DFA729_mF8605C6E2C9BE41D89B23148AA5A7F67596C0D63 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisHashMapHelper_1_tE18033C6B74BE6B9BAE79F2ADD9BC2C916DFA729_mF8605C6E2C9BE41D89B23148AA5A7F67596C0D63_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_m3446503708EF53FF3664993B371F061F2C98A44F_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_m3446503708EF53FF3664993B371F061F2C98A44F_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_mC94DEDD2611C7C84632B957D3FDB324F2C85EA7A (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_mC94DEDD2611C7C84632B957D3FDB324F2C85EA7A_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_tFE70D47D7D4D5A59CFA6D8E68852A7EE5BDB4854_m806F9CFE9718FE6DF13E117477C17767D1708279_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisHashMapHelper_1_tFE70D47D7D4D5A59CFA6D8E68852A7EE5BDB4854_m806F9CFE9718FE6DF13E117477C17767D1708279_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_tFE70D47D7D4D5A59CFA6D8E68852A7EE5BDB4854_m0660231136B868BA362E8045755B0F3C57CC67BA (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisHashMapHelper_1_tFE70D47D7D4D5A59CFA6D8E68852A7EE5BDB4854_m0660231136B868BA362E8045755B0F3C57CC67BA_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m9DD3BAE2675B37478EA2C9AA9DAFD2C6C1F5BF4E_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m9DD3BAE2675B37478EA2C9AA9DAFD2C6C1F5BF4E_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m796E3C1D5F3A55A9EFFD1AA98C09AB788198C7A1 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m796E3C1D5F3A55A9EFFD1AA98C09AB788198C7A1_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD_m201D21D3AC9187C9EFEF16F0B593FAC6BE19EE72_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD_m201D21D3AC9187C9EFEF16F0B593FAC6BE19EE72_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD_m70E5F2C375F3B4039114929EBDF86DFCBF1EF99C (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD_m70E5F2C375F3B4039114929EBDF86DFCBF1EF99C_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515_m067749C993CAF4A3AA0673C46673216D995516DE_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515_m067749C993CAF4A3AA0673C46673216D995516DE_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515_m756E0E44BD2515C8949896575600531B61F5B16B (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515_m756E0E44BD2515C8949896575600531B61F5B16B_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m9108AF5F196154FF71AD62376A7411B92391F000_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m9108AF5F196154FF71AD62376A7411B92391F000_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m219DC3BB1EF8E9E18A66470555A9974E2C7D9EC6 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m219DC3BB1EF8E9E18A66470555A9974E2C7D9EC6_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUnsafeRingQueue_1_t916A7CB801E880FD1A00447CC4815827882753ED_m6F51DC601209DBB54B5546FC945C0B69D996922D_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUnsafeRingQueue_1_t916A7CB801E880FD1A00447CC4815827882753ED_m6F51DC601209DBB54B5546FC945C0B69D996922D_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUnsafeRingQueue_1_t916A7CB801E880FD1A00447CC4815827882753ED_m84ACE3D5E56DC5439E2DA35A7C00916492258492 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUnsafeRingQueue_1_t916A7CB801E880FD1A00447CC4815827882753ED_m84ACE3D5E56DC5439E2DA35A7C00916492258492_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisBlobAssetBatch_tE7DAEECF09D38F983FE3F829F7774B40F4FD6B46_m1B05D4B205551B035C03FC4B7D1757D2D1A5C4CD_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisBlobAssetBatch_tE7DAEECF09D38F983FE3F829F7774B40F4FD6B46_m1B05D4B205551B035C03FC4B7D1757D2D1A5C4CD_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisBlobAssetBatch_tE7DAEECF09D38F983FE3F829F7774B40F4FD6B46_mBBE1A454562855891445DF33C1BB6CDA67E79903 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisBlobAssetBatch_tE7DAEECF09D38F983FE3F829F7774B40F4FD6B46_mBBE1A454562855891445DF33C1BB6CDA67E79903_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisBlobAssetHeader_t3EC5AD955B287949B57D36BBDE25A4D1BA85E639_mCC8381920C8736C7CFCA6E556B49BE02B71FE34C_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisBlobAssetHeader_t3EC5AD955B287949B57D36BBDE25A4D1BA85E639_mCC8381920C8736C7CFCA6E556B49BE02B71FE34C_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisBlobAssetHeader_t3EC5AD955B287949B57D36BBDE25A4D1BA85E639_mEBE2379486D6F502175AFA8545E6B0459F1F340C (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisBlobAssetHeader_t3EC5AD955B287949B57D36BBDE25A4D1BA85E639_mEBE2379486D6F502175AFA8545E6B0459F1F340C_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m97C7D5E5DE74DC60A0ECAA914830BEDF2C46ACAA_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m97C7D5E5DE74DC60A0ECAA914830BEDF2C46ACAA_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mB152D3C658FB48DEDB6E662EEB0C91018E7F2857 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mB152D3C658FB48DEDB6E662EEB0C91018E7F2857_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisChainCleanup_t720381A951125FF2EAA04EA1E544B86820F30122_mD5270B21C83F2AE30AEA6AABCBF5AC537D97A6ED_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisChainCleanup_t720381A951125FF2EAA04EA1E544B86820F30122_mD5270B21C83F2AE30AEA6AABCBF5AC537D97A6ED_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisChainCleanup_t720381A951125FF2EAA04EA1E544B86820F30122_m12E55909AEBB7242169E344DD51218DBDA18F9F6 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisChainCleanup_t720381A951125FF2EAA04EA1E544B86820F30122_m12E55909AEBB7242169E344DD51218DBDA18F9F6_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisDoubleRewindableAllocators_t8D3615CDAAECEE59D64F85F9E0F46D07168A7069_m12CD64E162BDD4E9964F0A20D7221DF379B37569_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisDoubleRewindableAllocators_t8D3615CDAAECEE59D64F85F9E0F46D07168A7069_m12CD64E162BDD4E9964F0A20D7221DF379B37569_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisDoubleRewindableAllocators_t8D3615CDAAECEE59D64F85F9E0F46D07168A7069_m92DFB3274CFF4B4484E6655675E1C1BF4AFB554E (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisDoubleRewindableAllocators_t8D3615CDAAECEE59D64F85F9E0F46D07168A7069_m92DFB3274CFF4B4484E6655675E1C1BF4AFB554E_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisDynamicBlobAssetBatch_tAF1A195EBA8DD36359A9439ED1BB2D99AD81F027_mB42BE557FD211C59CE7C30170B290F71275A669F_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisDynamicBlobAssetBatch_tAF1A195EBA8DD36359A9439ED1BB2D99AD81F027_mB42BE557FD211C59CE7C30170B290F71275A669F_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisDynamicBlobAssetBatch_tAF1A195EBA8DD36359A9439ED1BB2D99AD81F027_m4C583B0CA45B53C9B24E8765BCCC2A3B9A835EA1 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisDynamicBlobAssetBatch_tAF1A195EBA8DD36359A9439ED1BB2D99AD81F027_m4C583B0CA45B53C9B24E8765BCCC2A3B9A835EA1_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisECBChainHeapElement_tE83963A87C0B8B2EEDE315AF9DFF749A38C666DD_m72A92B4DB122FC4BC45F18FB459B619269492BC7_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisECBChainHeapElement_tE83963A87C0B8B2EEDE315AF9DFF749A38C666DD_m72A92B4DB122FC4BC45F18FB459B619269492BC7_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisECBChainHeapElement_tE83963A87C0B8B2EEDE315AF9DFF749A38C666DD_mD8DF741CD89D1CEF5C4F9A493181908BDC5C56F5 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisECBChainHeapElement_tE83963A87C0B8B2EEDE315AF9DFF749A38C666DD_mD8DF741CD89D1CEF5C4F9A493181908BDC5C56F5_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisECBChunk_tF8E51552DBA320AB90FCAE9CF1185FAFD3764F4F_mB2F57AD808C223787F8F2F7FE94F1CA09478E439_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisECBChunk_tF8E51552DBA320AB90FCAE9CF1185FAFD3764F4F_mB2F57AD808C223787F8F2F7FE94F1CA09478E439_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisECBChunk_tF8E51552DBA320AB90FCAE9CF1185FAFD3764F4F_mA06C51E42878473801E3CCADF345EC64265E1025 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisECBChunk_tF8E51552DBA320AB90FCAE9CF1185FAFD3764F4F_mA06C51E42878473801E3CCADF345EC64265E1025_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisEntity_t56176FC78C475061A82383D9E0CEE352C6C52ABD_m177EBEBF64B94FE192C8268AE6BCB9A563047C3C_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisEntity_t56176FC78C475061A82383D9E0CEE352C6C52ABD_m177EBEBF64B94FE192C8268AE6BCB9A563047C3C_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisEntity_t56176FC78C475061A82383D9E0CEE352C6C52ABD_mC7729F36ED36489AFC5470E4D99F9EE076B9C40B (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisEntity_t56176FC78C475061A82383D9E0CEE352C6C52ABD_mC7729F36ED36489AFC5470E4D99F9EE076B9C40B_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisEntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB_m8B4CD5160A7C28D2A54CB1E185FC3B59AD633CC2_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisEntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB_m8B4CD5160A7C28D2A54CB1E185FC3B59AD633CC2_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisEntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB_m70E6D94B1AA9B8CFBA3C7654EDB0E506990B6808 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisEntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB_m70E6D94B1AA9B8CFBA3C7654EDB0E506990B6808_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisEntityCommandBufferData_t88C8EFD5BBEF42F8008AF73FA2C27B60E5A31DC2_mF2283D03D9B90B77481B9489B742165F9BB40EF5_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisEntityCommandBufferData_t88C8EFD5BBEF42F8008AF73FA2C27B60E5A31DC2_mF2283D03D9B90B77481B9489B742165F9BB40EF5_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisEntityCommandBufferData_t88C8EFD5BBEF42F8008AF73FA2C27B60E5A31DC2_m47AC89596CA42CA8709BCEF28C51EC7D4611668F (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisEntityCommandBufferData_t88C8EFD5BBEF42F8008AF73FA2C27B60E5A31DC2_m47AC89596CA42CA8709BCEF28C51EC7D4611668F_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisEntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_m1D3A68FF0C582ADAE2A63F86DA45E6C4C5F713B9_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisEntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_m1D3A68FF0C582ADAE2A63F86DA45E6C4C5F713B9_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisEntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_mFB3AC0FA7E1BDFF541B132DAE5CEA6917E2A2E48 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisEntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_mFB3AC0FA7E1BDFF541B132DAE5CEA6917E2A2E48_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisEntityNameStoreAccessData_t5AC842F68D9F5083E23B12C17F81F43535F2ED1F_mBBB7A97578412E4A4A38B2F30EE24BE2425B70B8_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisEntityNameStoreAccessData_t5AC842F68D9F5083E23B12C17F81F43535F2ED1F_mBBB7A97578412E4A4A38B2F30EE24BE2425B70B8_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisEntityNameStoreAccessData_t5AC842F68D9F5083E23B12C17F81F43535F2ED1F_m0B3318CDE808F4FA12401BD3E39E889029BAB85F (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisEntityNameStoreAccessData_t5AC842F68D9F5083E23B12C17F81F43535F2ED1F_m0B3318CDE808F4FA12401BD3E39E889029BAB85F_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisEntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_m2F10D3E64E3CB71DD152025B3F5A3103ABB2DD07_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisEntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_m2F10D3E64E3CB71DD152025B3F5A3103ABB2DD07_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisEntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_m2569D7A993EADB9F70B33CDC2042DE372E7C2F74 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisEntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_m2569D7A993EADB9F70B33CDC2042DE372E7C2F74_gshared)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m274F833CD001C63E56A22D8F42C76CE8C6CC39DF (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m274F833CD001C63E56A22D8F42C76CE8C6CC39DF_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisIntPtr_t_mB2B3CFF1CB804C99734D4E2F5D8A8C9DB0D209A8_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisIntPtr_t_mB2B3CFF1CB804C99734D4E2F5D8A8C9DB0D209A8_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisIntPtr_t_mB17C6C168D8CA088879EDD0D5B9923F70F5269B8 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisIntPtr_t_mB17C6C168D8CA088879EDD0D5B9923F70F5269B8_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m9648A6CA697B17B009BBEDCE817AF98293EA07A8_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m9648A6CA697B17B009BBEDCE817AF98293EA07A8_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_mC7DDA799532A41B6BBF8F2B145215B78667BE6CE (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_mC7DDA799532A41B6BBF8F2B145215B78667BE6CE_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_mEC9469DBD91362D6135B8F5A81E90486BF328075_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_mEC9469DBD91362D6135B8F5A81E90486BF328075_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m742C058FF2011B81DD081BA92DC32E0E34CEAAC8 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m742C058FF2011B81DD081BA92DC32E0E34CEAAC8_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m6C198B51ACD7B8EC62D5E0E75433C12BE9D65A58_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m6C198B51ACD7B8EC62D5E0E75433C12BE9D65A58_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m8127223B00E08567EC09EF1D992F89C74F248AB0 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m8127223B00E08567EC09EF1D992F89C74F248AB0_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_mCCA7CED28D808054F7C94E1BF58205316AEE194F_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_mCCA7CED28D808054F7C94E1BF58205316AEE194F_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_m56B5B812224539B0C633BABE891ADDE1973580F6 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_m56B5B812224539B0C633BABE891ADDE1973580F6_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mB6FE4CAF35894EF5E357881DA5A0EAE9EDAD3754_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mB6FE4CAF35894EF5E357881DA5A0EAE9EDAD3754_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mC1EBD5161294EF95B8AC378DDF616869D287DC36 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mC1EBD5161294EF95B8AC378DDF616869D287DC36_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_mEBEAA7CA1C71A37FA5CBCF89A0C9B78ABAD5C8C7_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_mEBEAA7CA1C71A37FA5CBCF89A0C9B78ABAD5C8C7_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m3DF404928C7038CCD5C05BBBA41C4B2FD35A4253 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m3DF404928C7038CCD5C05BBBA41C4B2FD35A4253_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m25193E03B20C96400F243B7A682AF5BB8F030297_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m25193E03B20C96400F243B7A682AF5BB8F030297_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_mD84C2AFFB4ED036B913CEAD2FBF8A60E9C3A017D (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_mD84C2AFFB4ED036B913CEAD2FBF8A60E9C3A017D_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m79CAC169FC4593612624CB619E7D6F6FD7447517_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m79CAC169FC4593612624CB619E7D6F6FD7447517_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m5892DF1B875736B0E3612716E560A4E4AD5F6591 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m5892DF1B875736B0E3612716E560A4E4AD5F6591_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUntypedWeakReferenceId_tE6BA94FD975EA12B639C0A568532BD1AB874492A_mFAA6F9C6A87B112BBD85F22709B4E18563AA5593_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUntypedWeakReferenceId_tE6BA94FD975EA12B639C0A568532BD1AB874492A_mFAA6F9C6A87B112BBD85F22709B4E18563AA5593_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUntypedWeakReferenceId_tE6BA94FD975EA12B639C0A568532BD1AB874492A_m2BDC205D9F080390F4B1A1097C470377D56579B0 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUntypedWeakReferenceId_tE6BA94FD975EA12B639C0A568532BD1AB874492A_m2BDC205D9F080390F4B1A1097C470377D56579B0_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisDependencyHandle_t73038501598DF9B7E83BF8486D87B9DED6200B15_m372324DEBD6B906BB1927888F56DCBFBDC0DAC4C_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisDependencyHandle_t73038501598DF9B7E83BF8486D87B9DED6200B15_m372324DEBD6B906BB1927888F56DCBFBDC0DAC4C_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisDependencyHandle_t73038501598DF9B7E83BF8486D87B9DED6200B15_mCEA60798AAEFB42EBE92BFD4C8BFE55710CF1C17 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisDependencyHandle_t73038501598DF9B7E83BF8486D87B9DED6200B15_mCEA60798AAEFB42EBE92BFD4C8BFE55710CF1C17_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisNodeHeader_tC393A021B9635C19BEC9CEEA905E76D4B90FDC4F_mBBB27F335B5822EB0F181EA661BBCF2EA0519A3C_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisNodeHeader_tC393A021B9635C19BEC9CEEA905E76D4B90FDC4F_mBBB27F335B5822EB0F181EA661BBCF2EA0519A3C_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisNodeHeader_tC393A021B9635C19BEC9CEEA905E76D4B90FDC4F_m4035D9C7ED339F00B807E15D0E453D04898D957F (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisNodeHeader_tC393A021B9635C19BEC9CEEA905E76D4B90FDC4F_m4035D9C7ED339F00B807E15D0E453D04898D957F_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisBufferWithFixUp_tDFD5630DDFDBC051A462A026DFAEAA4A047FB3B6_m36A4E0B3E7DFA48026FB77ABAFB38AC1F999BB1F_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisBufferWithFixUp_tDFD5630DDFDBC051A462A026DFAEAA4A047FB3B6_m36A4E0B3E7DFA48026FB77ABAFB38AC1F999BB1F_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisBufferWithFixUp_tDFD5630DDFDBC051A462A026DFAEAA4A047FB3B6_m17951F8123258E416C8A1B9CB83A5DDE16A48C3C (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisBufferWithFixUp_tDFD5630DDFDBC051A462A026DFAEAA4A047FB3B6_m17951F8123258E416C8A1B9CB83A5DDE16A48C3C_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m4A0947EA519A2614EC19544513888A4DC5F42919_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m4A0947EA519A2614EC19544513888A4DC5F42919_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m6AD8B4EF31CDD94CA734378B1443806DAFE68A05 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m6AD8B4EF31CDD94CA734378B1443806DAFE68A05_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisHeaderData_t5CE38A1426623168DB817F1D87E639856A2614B3_m9007635FD7971062D616805DB88395EEB43C920B_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisHeaderData_t5CE38A1426623168DB817F1D87E639856A2614B3_m9007635FD7971062D616805DB88395EEB43C920B_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisHeaderData_t5CE38A1426623168DB817F1D87E639856A2614B3_m47321A559CE5DBAD9A16E3C2DF5FF899C1410244 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisHeaderData_t5CE38A1426623168DB817F1D87E639856A2614B3_m47321A559CE5DBAD9A16E3C2DF5FF899C1410244_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisStateAllocLevel1_t93303AA6CAA1A10E9819D11E131EDD90DE20043D_m5D881A2223FC0BF2CB68E2EF91BF123C506FA136_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisStateAllocLevel1_t93303AA6CAA1A10E9819D11E131EDD90DE20043D_m5D881A2223FC0BF2CB68E2EF91BF123C506FA136_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisStateAllocLevel1_t93303AA6CAA1A10E9819D11E131EDD90DE20043D_m821747001EAE919BBF7212AA6497A81A78FC2B36 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisStateAllocLevel1_t93303AA6CAA1A10E9819D11E131EDD90DE20043D_m821747001EAE919BBF7212AA6497A81A78FC2B36_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisPerChunkData_t1837BB30B95C4DD39A4908ECC71AB0B75DFF9135_mAB06B6453863E5D5F9644288D86E39C5848BEB1B_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisPerChunkData_t1837BB30B95C4DD39A4908ECC71AB0B75DFF9135_mAB06B6453863E5D5F9644288D86E39C5848BEB1B_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisPerChunkData_t1837BB30B95C4DD39A4908ECC71AB0B75DFF9135_mA7BD893DD0B8C45C36CE456C8EC87EC2907E3172 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisPerChunkData_t1837BB30B95C4DD39A4908ECC71AB0B75DFF9135_mA7BD893DD0B8C45C36CE456C8EC87EC2907E3172_gshared)(method);
}
inline EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* EqualityComparer_1_CreateComparer_m22AF3135664449980749E1EC32EB92DB49219F9B (const RuntimeMethod* method)
{
	return ((  EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* (*) (const RuntimeMethod*))EqualityComparer_1_CreateComparer_m22AF3135664449980749E1EC32EB92DB49219F9B_gshared)(method);
}
inline EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* EqualityComparer_1_CreateComparer_mD5EE323D1C48F0C09CBB944FA81707B8FEE2DB6D (const RuntimeMethod* method)
{
	return ((  EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* (*) (const RuntimeMethod*))EqualityComparer_1_CreateComparer_mD5EE323D1C48F0C09CBB944FA81707B8FEE2DB6D_gshared)(method);
}
inline EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* EqualityComparer_1_CreateComparer_m5F906E9B13BCCCDF51EF0852BD9E5E0065D185F8 (const RuntimeMethod* method)
{
	return ((  EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* (*) (const RuntimeMethod*))EqualityComparer_1_CreateComparer_m5F906E9B13BCCCDF51EF0852BD9E5E0065D185F8_gshared)(method);
}
inline EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* EqualityComparer_1_CreateComparer_mEBC7BD29A8FD796A4DAA1DF4428B95D1BA4FB377 (const RuntimeMethod* method)
{
	return ((  EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* (*) (const RuntimeMethod*))EqualityComparer_1_CreateComparer_mEBC7BD29A8FD796A4DAA1DF4428B95D1BA4FB377_gshared)(method);
}
inline void* ILSupport_AddressOf_TisContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7_m01D2486E5139DD8D56B5A959FBDD5892F83B5C23_inline (ContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7* ___0_thing, const RuntimeMethod* method)
{
	return ((  void* (*) (ContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7*, const RuntimeMethod*))ILSupport_AddressOf_TisContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7_m01D2486E5139DD8D56B5A959FBDD5892F83B5C23_gshared_inline)(___0_thing, method);
}
inline void* ILSupport_AddressOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m8544D06F32E3436CE779A52F9FF3B72256EBAFAC_inline (int32_t* ___0_thing, const RuntimeMethod* method)
{
	return ((  void* (*) (int32_t*, const RuntimeMethod*))ILSupport_AddressOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m8544D06F32E3436CE779A52F9FF3B72256EBAFAC_gshared_inline)(___0_thing, method);
}
// Method Definition Index: 66213
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStrCmpIntRes2_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_mB3F9377B1A57D35D5514DEF77B3D9279A8622960_gshared (int16_t* ___0_a, int32_t ___1_alen, int16_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	bool V_0 = false;
	bool V_1 = false;
	StrBoolArray_tCA66E1F688A4BC6FA749195F867F59E523508DD6 V_2;
	memset((&V_2), 0, sizeof(V_2));
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	int16_t V_7 = 0;
	int16_t V_8 = 0;
	bool V_9 = false;
	int32_t V_10 = 0;
	int32_t V_11 = 0;
	int16_t V_12 = 0;
	int32_t G_B49_0 = 0;
	int32_t G_B48_0 = 0;
	int32_t G_B50_0 = 0;
	int32_t G_B50_1 = 0;
	int32_t G_B59_0 = 0;
	int32_t G_B58_0 = 0;
	int32_t G_B60_0 = 0;
	int32_t G_B61_0 = 0;
	int32_t G_B61_1 = 0;
	int32_t G_B69_0 = 0;
	int32_t G_B68_0 = 0;
	int32_t G_B70_0 = 0;
	int32_t G_B70_1 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:223>
		V_0 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:224>
		V_1 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:225>
		il2cpp_codegen_initobj((&V_2), sizeof(StrBoolArray_tCA66E1F688A4BC6FA749195F867F59E523508DD6));
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:228>
		V_3 = 0;
		goto IL_0183;
	}

IL_0013:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:230>
		int16_t* L_0 = ___0_a;
		int32_t L_1 = V_3;
		uint32_t L_2 = sizeof(int16_t);
		int16_t L_3 = (*(int16_t*)((int16_t*)il2cpp_codegen_add((intptr_t)L_0, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_1), (int32_t)L_2)))));
		V_7 = L_3;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:232>
		int32_t L_4 = V_3;
		int32_t L_5 = ___1_alen;
		if ((!(((uint32_t)L_4) == ((uint32_t)L_5))))
		{
			goto IL_002b;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:233>
		V_0 = (bool)1;
	}

IL_002b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:235>
		V_1 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:236>
		V_4 = 0;
		goto IL_0176;
	}

IL_0035:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:238>
		int16_t* L_6 = ___2_b;
		int32_t L_7 = V_4;
		uint32_t L_8 = sizeof(int16_t);
		int16_t L_9 = (*(int16_t*)((int16_t*)il2cpp_codegen_add((intptr_t)L_6, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_7), (int32_t)L_8)))));
		V_8 = L_9;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:239>
		int32_t L_10 = V_4;
		int32_t L_11 = ___3_blen;
		if ((!(((uint32_t)L_10) == ((uint32_t)L_11))))
		{
			goto IL_004f;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:240>
		V_1 = (bool)1;
	}

IL_004f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:245>
		int32_t L_12 = ___5_imm8;
		V_10 = ((int32_t)(((int32_t)(L_12>>2))&3));
		int32_t L_13 = V_10;
		switch (L_13)
		{
			case 0:
			{
				goto IL_006f;
			}
			case 1:
			{
				goto IL_00ad;
			}
			case 2:
			{
				goto IL_0102;
			}
		}
	}
	{
		goto IL_0134;
	}

IL_006f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:248>
		EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* L_14;
		L_14 = EqualityComparer_1_get_Default_m7D273CC532DC2164C9C86D28C639FDEA38173C88_inline(il2cpp_rgctx_method(method->rgctx_data, 2));
		int16_t L_15 = V_7;
		int16_t L_16 = V_8;
		NullCheck(L_14);
		bool L_17;
		L_17 = VirtualFuncInvoker2< bool, int16_t, int16_t >::Invoke(8, L_14, L_15, L_16);
		V_9 = L_17;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:249>
		bool L_18 = V_0;
		bool L_19 = V_1;
		if (!((int32_t)(((((int32_t)L_18) == ((int32_t)0))? 1 : 0)&(int32_t)L_19)))
		{
			goto IL_008f;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:250>
		V_9 = (bool)0;
		goto IL_0164;
	}

IL_008f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:251>
		bool L_20 = V_0;
		if (!L_20)
		{
			goto IL_009d;
		}
	}
	{
		bool L_21 = V_1;
		if (L_21)
		{
			goto IL_009d;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:252>
		V_9 = (bool)0;
		goto IL_0164;
	}

IL_009d:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:253>
		bool L_22 = V_0;
		bool L_23 = V_1;
		if (!((int32_t)((int32_t)L_22&(int32_t)L_23)))
		{
			goto IL_0164;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:254>
		V_9 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:255>
		goto IL_0164;
	}

IL_00ad:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:258>
		int32_t L_24 = V_3;
		if (((int32_t)(L_24&1)))
		{
			goto IL_00ca;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:259>
		Comparer_1_t7EDCB50F141B8333E02C67781CAC2D41381F0563* L_25;
		L_25 = Comparer_1_get_Default_mE45154132033749FD101CB1689E0375B42C4B407(il2cpp_rgctx_method(method->rgctx_data, 6));
		int16_t L_26 = V_8;
		int16_t L_27 = V_7;
		NullCheck(L_25);
		int32_t L_28;
		L_28 = VirtualFuncInvoker2< int32_t, int16_t, int16_t >::Invoke(6, L_25, L_26, L_27);
		V_9 = (bool)((((int32_t)((((int32_t)L_28) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		goto IL_00e0;
	}

IL_00ca:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:261>
		Comparer_1_t7EDCB50F141B8333E02C67781CAC2D41381F0563* L_29;
		L_29 = Comparer_1_get_Default_mE45154132033749FD101CB1689E0375B42C4B407(il2cpp_rgctx_method(method->rgctx_data, 6));
		int16_t L_30 = V_8;
		int16_t L_31 = V_7;
		NullCheck(L_29);
		int32_t L_32;
		L_32 = VirtualFuncInvoker2< int32_t, int16_t, int16_t >::Invoke(6, L_29, L_30, L_31);
		V_9 = (bool)((((int32_t)((((int32_t)L_32) > ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_00e0:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:263>
		bool L_33 = V_0;
		bool L_34 = V_1;
		if (!((int32_t)(((((int32_t)L_33) == ((int32_t)0))? 1 : 0)&(int32_t)L_34)))
		{
			goto IL_00ed;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:264>
		V_9 = (bool)0;
		goto IL_0164;
	}

IL_00ed:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:265>
		bool L_35 = V_0;
		if (!L_35)
		{
			goto IL_00f8;
		}
	}
	{
		bool L_36 = V_1;
		if (L_36)
		{
			goto IL_00f8;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:266>
		V_9 = (bool)0;
		goto IL_0164;
	}

IL_00f8:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:267>
		bool L_37 = V_0;
		bool L_38 = V_1;
		if (!((int32_t)((int32_t)L_37&(int32_t)L_38)))
		{
			goto IL_0164;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:268>
		V_9 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:269>
		goto IL_0164;
	}

IL_0102:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:271>
		EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* L_39;
		L_39 = EqualityComparer_1_get_Default_m7D273CC532DC2164C9C86D28C639FDEA38173C88_inline(il2cpp_rgctx_method(method->rgctx_data, 2));
		int16_t L_40 = V_7;
		int16_t L_41 = V_8;
		NullCheck(L_39);
		bool L_42;
		L_42 = VirtualFuncInvoker2< bool, int16_t, int16_t >::Invoke(8, L_39, L_40, L_41);
		V_9 = L_42;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:272>
		bool L_43 = V_0;
		bool L_44 = V_1;
		if (!((int32_t)(((((int32_t)L_43) == ((int32_t)0))? 1 : 0)&(int32_t)L_44)))
		{
			goto IL_011f;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:273>
		V_9 = (bool)0;
		goto IL_0164;
	}

IL_011f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:274>
		bool L_45 = V_0;
		if (!L_45)
		{
			goto IL_012a;
		}
	}
	{
		bool L_46 = V_1;
		if (L_46)
		{
			goto IL_012a;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:275>
		V_9 = (bool)0;
		goto IL_0164;
	}

IL_012a:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:276>
		bool L_47 = V_0;
		bool L_48 = V_1;
		if (!((int32_t)((int32_t)L_47&(int32_t)L_48)))
		{
			goto IL_0164;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:277>
		V_9 = (bool)1;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:278>
		goto IL_0164;
	}

IL_0134:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:280>
		EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* L_49;
		L_49 = EqualityComparer_1_get_Default_m7D273CC532DC2164C9C86D28C639FDEA38173C88_inline(il2cpp_rgctx_method(method->rgctx_data, 2));
		int16_t L_50 = V_7;
		int16_t L_51 = V_8;
		NullCheck(L_49);
		bool L_52;
		L_52 = VirtualFuncInvoker2< bool, int16_t, int16_t >::Invoke(8, L_49, L_50, L_51);
		V_9 = L_52;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:281>
		bool L_53 = V_0;
		bool L_54 = V_1;
		if (!((int32_t)(((((int32_t)L_53) == ((int32_t)0))? 1 : 0)&(int32_t)L_54)))
		{
			goto IL_0151;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:282>
		V_9 = (bool)0;
		goto IL_0164;
	}

IL_0151:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:283>
		bool L_55 = V_0;
		if (!L_55)
		{
			goto IL_015c;
		}
	}
	{
		bool L_56 = V_1;
		if (L_56)
		{
			goto IL_015c;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:284>
		V_9 = (bool)1;
		goto IL_0164;
	}

IL_015c:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:285>
		bool L_57 = V_0;
		bool L_58 = V_1;
		if (!((int32_t)((int32_t)L_57&(int32_t)L_58)))
		{
			goto IL_0164;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:286>
		V_9 = (bool)1;
	}

IL_0164:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:290>
		int32_t L_59 = V_3;
		int32_t L_60 = V_4;
		bool L_61 = V_9;
		StrBoolArray_SetBit_m212C6D1A8A4C422AF979D6B3BC7CD5B9BD0F3F01((&V_2), L_59, L_60, L_61, NULL);
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:236>
		int32_t L_62 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_62, 1));
	}

IL_0176:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:236>
		int32_t L_63 = V_4;
		int32_t L_64 = ___4_len;
		if ((((int32_t)L_63) < ((int32_t)L_64)))
		{
			goto IL_0035;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:228>
		int32_t L_65 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_65, 1));
	}

IL_0183:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:228>
		int32_t L_66 = V_3;
		int32_t L_67 = ___4_len;
		if ((((int32_t)L_66) < ((int32_t)L_67)))
		{
			goto IL_0013;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:294>
		V_6 = 0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:297>
		int32_t L_68 = ___5_imm8;
		V_10 = ((int32_t)(((int32_t)(L_68>>2))&3));
		int32_t L_69 = V_10;
		switch (L_69)
		{
			case 0:
			{
				goto IL_01b2;
			}
			case 1:
			{
				goto IL_01ef;
			}
			case 2:
			{
				goto IL_0237;
			}
			case 3:
			{
				goto IL_025f;
			}
		}
	}
	{
		goto IL_02a5;
	}

IL_01b2:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:300>
		V_3 = 0;
		goto IL_01e5;
	}

IL_01b6:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:302>
		V_4 = 0;
		goto IL_01db;
	}

IL_01bb:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:304>
		int32_t L_70 = V_6;
		int32_t L_71 = V_4;
		int32_t L_72 = V_3;
		bool L_73;
		L_73 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_71, L_72, NULL);
		if (L_73)
		{
			G_B49_0 = L_70;
			goto IL_01cc;
		}
		G_B48_0 = L_70;
	}
	{
		G_B50_0 = 0;
		G_B50_1 = G_B48_0;
		goto IL_01cd;
	}

IL_01cc:
	{
		G_B50_0 = 1;
		G_B50_1 = G_B49_0;
	}

IL_01cd:
	{
		int32_t L_74 = V_3;
		V_6 = ((int32_t)(G_B50_1|((int32_t)(G_B50_0<<((int32_t)(L_74&((int32_t)31)))))));
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:302>
		int32_t L_75 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_75, 1));
	}

IL_01db:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:302>
		int32_t L_76 = V_4;
		int32_t L_77 = ___4_len;
		if ((((int32_t)L_76) < ((int32_t)L_77)))
		{
			goto IL_01bb;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:300>
		int32_t L_78 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_78, 1));
	}

IL_01e5:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:300>
		int32_t L_79 = V_3;
		int32_t L_80 = ___4_len;
		if ((((int32_t)L_79) < ((int32_t)L_80)))
		{
			goto IL_01b6;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:312>
		goto IL_02a5;
	}

IL_01ef:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:314>
		V_3 = 0;
		goto IL_0230;
	}

IL_01f3:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:316>
		V_4 = 0;
		goto IL_0226;
	}

IL_01f8:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:318>
		int32_t L_81 = V_6;
		int32_t L_82 = V_4;
		int32_t L_83 = V_3;
		bool L_84;
		L_84 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_82, L_83, NULL);
		if (!L_84)
		{
			G_B59_0 = L_81;
			goto IL_0214;
		}
		G_B58_0 = L_81;
	}
	{
		int32_t L_85 = V_4;
		int32_t L_86 = V_3;
		bool L_87;
		L_87 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), ((int32_t)il2cpp_codegen_add(L_85, 1)), L_86, NULL);
		if (L_87)
		{
			G_B60_0 = G_B58_0;
			goto IL_0217;
		}
		G_B59_0 = G_B58_0;
	}

IL_0214:
	{
		G_B61_0 = 0;
		G_B61_1 = G_B59_0;
		goto IL_0218;
	}

IL_0217:
	{
		G_B61_0 = 1;
		G_B61_1 = G_B60_0;
	}

IL_0218:
	{
		int32_t L_88 = V_3;
		V_6 = ((int32_t)(G_B61_1|((int32_t)(G_B61_0<<((int32_t)(L_88&((int32_t)31)))))));
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:316>
		int32_t L_89 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_89, 2));
	}

IL_0226:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:316>
		int32_t L_90 = V_4;
		int32_t L_91 = ___4_len;
		if ((((int32_t)L_90) < ((int32_t)L_91)))
		{
			goto IL_01f8;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:314>
		int32_t L_92 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_92, 1));
	}

IL_0230:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:314>
		int32_t L_93 = V_3;
		int32_t L_94 = ___4_len;
		if ((((int32_t)L_93) < ((int32_t)L_94)))
		{
			goto IL_01f3;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:321>
		goto IL_02a5;
	}

IL_0237:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:323>
		V_3 = 0;
		goto IL_0258;
	}

IL_023b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:325>
		int32_t L_95 = V_6;
		int32_t L_96 = V_3;
		int32_t L_97 = V_3;
		bool L_98;
		L_98 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_96, L_97, NULL);
		if (L_98)
		{
			G_B69_0 = L_95;
			goto IL_024b;
		}
		G_B68_0 = L_95;
	}
	{
		G_B70_0 = 0;
		G_B70_1 = G_B68_0;
		goto IL_024c;
	}

IL_024b:
	{
		G_B70_0 = 1;
		G_B70_1 = G_B69_0;
	}

IL_024c:
	{
		int32_t L_99 = V_3;
		V_6 = ((int32_t)(G_B70_1|((int32_t)(G_B70_0<<((int32_t)(L_99&((int32_t)31)))))));
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:323>
		int32_t L_100 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_100, 1));
	}

IL_0258:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:323>
		int32_t L_101 = V_3;
		int32_t L_102 = ___4_len;
		if ((((int32_t)L_101) < ((int32_t)L_102)))
		{
			goto IL_023b;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:327>
		goto IL_02a5;
	}

IL_025f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:329>
		int32_t L_103 = ___6_allOnes;
		V_6 = L_103;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:330>
		V_3 = 0;
		goto IL_02a0;
	}

IL_0267:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:332>
		int32_t L_104 = V_3;
		V_11 = L_104;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:333>
		V_4 = 0;
		goto IL_0294;
	}

IL_026f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:335>
		int32_t L_105 = V_4;
		int32_t L_106 = V_11;
		bool L_107;
		L_107 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_105, L_106, NULL);
		if (L_107)
		{
			goto IL_0288;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:336>
		int32_t L_108 = V_6;
		int32_t L_109 = V_3;
		V_6 = ((int32_t)(L_108&((~((int32_t)(1<<((int32_t)(L_109&((int32_t)31)))))))));
	}

IL_0288:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:337>
		int32_t L_110 = V_11;
		V_11 = ((int32_t)il2cpp_codegen_add(L_110, 1));
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:333>
		int32_t L_111 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_111, 1));
	}

IL_0294:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:333>
		int32_t L_112 = V_4;
		int32_t L_113 = ___4_len;
		int32_t L_114 = V_3;
		if ((((int32_t)L_112) < ((int32_t)((int32_t)il2cpp_codegen_subtract(L_113, L_114)))))
		{
			goto IL_026f;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:330>
		int32_t L_115 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_115, 1));
	}

IL_02a0:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:330>
		int32_t L_116 = V_3;
		int32_t L_117 = ___4_len;
		if ((((int32_t)L_116) < ((int32_t)L_117)))
		{
			goto IL_0267;
		}
	}

IL_02a5:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:343>
		V_5 = 0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:346>
		V_1 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:347>
		V_3 = 0;
		goto IL_032b;
	}

IL_02ae:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:349>
		int32_t L_118 = ___5_imm8;
		if (!((int32_t)(L_118&((int32_t)16))))
		{
			goto IL_0319;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:351>
		int32_t L_119 = ___5_imm8;
		if (!((int32_t)(L_119&((int32_t)32))))
		{
			goto IL_0308;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:353>
		EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* L_120;
		L_120 = EqualityComparer_1_get_Default_m7D273CC532DC2164C9C86D28C639FDEA38173C88_inline(il2cpp_rgctx_method(method->rgctx_data, 2));
		int16_t* L_121 = ___2_b;
		int32_t L_122 = V_3;
		uint32_t L_123 = sizeof(int16_t);
		int16_t L_124 = (*(int16_t*)((int16_t*)il2cpp_codegen_add((intptr_t)L_121, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_122), (int32_t)L_123)))));
		il2cpp_codegen_initobj((&V_12), sizeof(int16_t));
		int16_t L_125 = V_12;
		NullCheck(L_120);
		bool L_126;
		L_126 = VirtualFuncInvoker2< bool, int16_t, int16_t >::Invoke(8, L_120, L_124, L_125);
		if (!L_126)
		{
			goto IL_02e4;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:355>
		V_1 = (bool)1;
	}

IL_02e4:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:358>
		bool L_127 = V_1;
		if (!L_127)
		{
			goto IL_02f7;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:359>
		int32_t L_128 = V_5;
		int32_t L_129 = V_6;
		int32_t L_130 = V_3;
		V_5 = ((int32_t)(L_128|((int32_t)(L_129&((int32_t)(1<<((int32_t)(L_130&((int32_t)31)))))))));
		goto IL_0327;
	}

IL_02f7:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:361>
		int32_t L_131 = V_5;
		int32_t L_132 = V_6;
		int32_t L_133 = V_3;
		V_5 = ((int32_t)(L_131|((int32_t)(((~L_132))&((int32_t)(1<<((int32_t)(L_133&((int32_t)31)))))))));
		goto IL_0327;
	}

IL_0308:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:364>
		int32_t L_134 = V_5;
		int32_t L_135 = V_6;
		int32_t L_136 = V_3;
		V_5 = ((int32_t)(L_134|((int32_t)(((~L_135))&((int32_t)(1<<((int32_t)(L_136&((int32_t)31)))))))));
		goto IL_0327;
	}

IL_0319:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:367>
		int32_t L_137 = V_5;
		int32_t L_138 = V_6;
		int32_t L_139 = V_3;
		V_5 = ((int32_t)(L_137|((int32_t)(L_138&((int32_t)(1<<((int32_t)(L_139&((int32_t)31)))))))));
	}

IL_0327:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:347>
		int32_t L_140 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_140, 1));
	}

IL_032b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:347>
		int32_t L_141 = V_3;
		int32_t L_142 = ___4_len;
		if ((((int32_t)L_141) < ((int32_t)L_142)))
		{
			goto IL_02ae;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:370>
		int32_t L_143 = V_5;
		return L_143;
	}
}
// Method Definition Index: 66213
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStrCmpIntRes2_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_mA23FD3A0C3B4448E4721DA31DA7B4B93A636A3FD_gshared (int8_t* ___0_a, int32_t ___1_alen, int8_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	bool V_0 = false;
	bool V_1 = false;
	StrBoolArray_tCA66E1F688A4BC6FA749195F867F59E523508DD6 V_2;
	memset((&V_2), 0, sizeof(V_2));
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	int8_t V_7 = 0x0;
	int8_t V_8 = 0x0;
	bool V_9 = false;
	int32_t V_10 = 0;
	int32_t V_11 = 0;
	int8_t V_12 = 0x0;
	int32_t G_B49_0 = 0;
	int32_t G_B48_0 = 0;
	int32_t G_B50_0 = 0;
	int32_t G_B50_1 = 0;
	int32_t G_B59_0 = 0;
	int32_t G_B58_0 = 0;
	int32_t G_B60_0 = 0;
	int32_t G_B61_0 = 0;
	int32_t G_B61_1 = 0;
	int32_t G_B69_0 = 0;
	int32_t G_B68_0 = 0;
	int32_t G_B70_0 = 0;
	int32_t G_B70_1 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:223>
		V_0 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:224>
		V_1 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:225>
		il2cpp_codegen_initobj((&V_2), sizeof(StrBoolArray_tCA66E1F688A4BC6FA749195F867F59E523508DD6));
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:228>
		V_3 = 0;
		goto IL_0183;
	}

IL_0013:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:230>
		int8_t* L_0 = ___0_a;
		int32_t L_1 = V_3;
		uint32_t L_2 = sizeof(int8_t);
		int8_t L_3 = (*(int8_t*)((int8_t*)il2cpp_codegen_add((intptr_t)L_0, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_1), (int32_t)L_2)))));
		V_7 = L_3;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:232>
		int32_t L_4 = V_3;
		int32_t L_5 = ___1_alen;
		if ((!(((uint32_t)L_4) == ((uint32_t)L_5))))
		{
			goto IL_002b;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:233>
		V_0 = (bool)1;
	}

IL_002b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:235>
		V_1 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:236>
		V_4 = 0;
		goto IL_0176;
	}

IL_0035:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:238>
		int8_t* L_6 = ___2_b;
		int32_t L_7 = V_4;
		uint32_t L_8 = sizeof(int8_t);
		int8_t L_9 = (*(int8_t*)((int8_t*)il2cpp_codegen_add((intptr_t)L_6, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_7), (int32_t)L_8)))));
		V_8 = L_9;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:239>
		int32_t L_10 = V_4;
		int32_t L_11 = ___3_blen;
		if ((!(((uint32_t)L_10) == ((uint32_t)L_11))))
		{
			goto IL_004f;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:240>
		V_1 = (bool)1;
	}

IL_004f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:245>
		int32_t L_12 = ___5_imm8;
		V_10 = ((int32_t)(((int32_t)(L_12>>2))&3));
		int32_t L_13 = V_10;
		switch (L_13)
		{
			case 0:
			{
				goto IL_006f;
			}
			case 1:
			{
				goto IL_00ad;
			}
			case 2:
			{
				goto IL_0102;
			}
		}
	}
	{
		goto IL_0134;
	}

IL_006f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:248>
		EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* L_14;
		L_14 = EqualityComparer_1_get_Default_m7F71AAC0046A3CB8C4CEB06A5A52A1269AF7023D_inline(il2cpp_rgctx_method(method->rgctx_data, 2));
		int8_t L_15 = V_7;
		int8_t L_16 = V_8;
		NullCheck(L_14);
		bool L_17;
		L_17 = VirtualFuncInvoker2< bool, int8_t, int8_t >::Invoke(8, L_14, L_15, L_16);
		V_9 = L_17;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:249>
		bool L_18 = V_0;
		bool L_19 = V_1;
		if (!((int32_t)(((((int32_t)L_18) == ((int32_t)0))? 1 : 0)&(int32_t)L_19)))
		{
			goto IL_008f;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:250>
		V_9 = (bool)0;
		goto IL_0164;
	}

IL_008f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:251>
		bool L_20 = V_0;
		if (!L_20)
		{
			goto IL_009d;
		}
	}
	{
		bool L_21 = V_1;
		if (L_21)
		{
			goto IL_009d;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:252>
		V_9 = (bool)0;
		goto IL_0164;
	}

IL_009d:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:253>
		bool L_22 = V_0;
		bool L_23 = V_1;
		if (!((int32_t)((int32_t)L_22&(int32_t)L_23)))
		{
			goto IL_0164;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:254>
		V_9 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:255>
		goto IL_0164;
	}

IL_00ad:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:258>
		int32_t L_24 = V_3;
		if (((int32_t)(L_24&1)))
		{
			goto IL_00ca;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:259>
		Comparer_1_tFA27DAC2908F666A385A0E5699BB66735365343B* L_25;
		L_25 = Comparer_1_get_Default_m84816461184ACF98D5F66D45F43652587DA47B4F(il2cpp_rgctx_method(method->rgctx_data, 6));
		int8_t L_26 = V_8;
		int8_t L_27 = V_7;
		NullCheck(L_25);
		int32_t L_28;
		L_28 = VirtualFuncInvoker2< int32_t, int8_t, int8_t >::Invoke(6, L_25, L_26, L_27);
		V_9 = (bool)((((int32_t)((((int32_t)L_28) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		goto IL_00e0;
	}

IL_00ca:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:261>
		Comparer_1_tFA27DAC2908F666A385A0E5699BB66735365343B* L_29;
		L_29 = Comparer_1_get_Default_m84816461184ACF98D5F66D45F43652587DA47B4F(il2cpp_rgctx_method(method->rgctx_data, 6));
		int8_t L_30 = V_8;
		int8_t L_31 = V_7;
		NullCheck(L_29);
		int32_t L_32;
		L_32 = VirtualFuncInvoker2< int32_t, int8_t, int8_t >::Invoke(6, L_29, L_30, L_31);
		V_9 = (bool)((((int32_t)((((int32_t)L_32) > ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_00e0:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:263>
		bool L_33 = V_0;
		bool L_34 = V_1;
		if (!((int32_t)(((((int32_t)L_33) == ((int32_t)0))? 1 : 0)&(int32_t)L_34)))
		{
			goto IL_00ed;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:264>
		V_9 = (bool)0;
		goto IL_0164;
	}

IL_00ed:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:265>
		bool L_35 = V_0;
		if (!L_35)
		{
			goto IL_00f8;
		}
	}
	{
		bool L_36 = V_1;
		if (L_36)
		{
			goto IL_00f8;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:266>
		V_9 = (bool)0;
		goto IL_0164;
	}

IL_00f8:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:267>
		bool L_37 = V_0;
		bool L_38 = V_1;
		if (!((int32_t)((int32_t)L_37&(int32_t)L_38)))
		{
			goto IL_0164;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:268>
		V_9 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:269>
		goto IL_0164;
	}

IL_0102:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:271>
		EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* L_39;
		L_39 = EqualityComparer_1_get_Default_m7F71AAC0046A3CB8C4CEB06A5A52A1269AF7023D_inline(il2cpp_rgctx_method(method->rgctx_data, 2));
		int8_t L_40 = V_7;
		int8_t L_41 = V_8;
		NullCheck(L_39);
		bool L_42;
		L_42 = VirtualFuncInvoker2< bool, int8_t, int8_t >::Invoke(8, L_39, L_40, L_41);
		V_9 = L_42;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:272>
		bool L_43 = V_0;
		bool L_44 = V_1;
		if (!((int32_t)(((((int32_t)L_43) == ((int32_t)0))? 1 : 0)&(int32_t)L_44)))
		{
			goto IL_011f;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:273>
		V_9 = (bool)0;
		goto IL_0164;
	}

IL_011f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:274>
		bool L_45 = V_0;
		if (!L_45)
		{
			goto IL_012a;
		}
	}
	{
		bool L_46 = V_1;
		if (L_46)
		{
			goto IL_012a;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:275>
		V_9 = (bool)0;
		goto IL_0164;
	}

IL_012a:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:276>
		bool L_47 = V_0;
		bool L_48 = V_1;
		if (!((int32_t)((int32_t)L_47&(int32_t)L_48)))
		{
			goto IL_0164;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:277>
		V_9 = (bool)1;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:278>
		goto IL_0164;
	}

IL_0134:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:280>
		EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* L_49;
		L_49 = EqualityComparer_1_get_Default_m7F71AAC0046A3CB8C4CEB06A5A52A1269AF7023D_inline(il2cpp_rgctx_method(method->rgctx_data, 2));
		int8_t L_50 = V_7;
		int8_t L_51 = V_8;
		NullCheck(L_49);
		bool L_52;
		L_52 = VirtualFuncInvoker2< bool, int8_t, int8_t >::Invoke(8, L_49, L_50, L_51);
		V_9 = L_52;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:281>
		bool L_53 = V_0;
		bool L_54 = V_1;
		if (!((int32_t)(((((int32_t)L_53) == ((int32_t)0))? 1 : 0)&(int32_t)L_54)))
		{
			goto IL_0151;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:282>
		V_9 = (bool)0;
		goto IL_0164;
	}

IL_0151:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:283>
		bool L_55 = V_0;
		if (!L_55)
		{
			goto IL_015c;
		}
	}
	{
		bool L_56 = V_1;
		if (L_56)
		{
			goto IL_015c;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:284>
		V_9 = (bool)1;
		goto IL_0164;
	}

IL_015c:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:285>
		bool L_57 = V_0;
		bool L_58 = V_1;
		if (!((int32_t)((int32_t)L_57&(int32_t)L_58)))
		{
			goto IL_0164;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:286>
		V_9 = (bool)1;
	}

IL_0164:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:290>
		int32_t L_59 = V_3;
		int32_t L_60 = V_4;
		bool L_61 = V_9;
		StrBoolArray_SetBit_m212C6D1A8A4C422AF979D6B3BC7CD5B9BD0F3F01((&V_2), L_59, L_60, L_61, NULL);
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:236>
		int32_t L_62 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_62, 1));
	}

IL_0176:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:236>
		int32_t L_63 = V_4;
		int32_t L_64 = ___4_len;
		if ((((int32_t)L_63) < ((int32_t)L_64)))
		{
			goto IL_0035;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:228>
		int32_t L_65 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_65, 1));
	}

IL_0183:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:228>
		int32_t L_66 = V_3;
		int32_t L_67 = ___4_len;
		if ((((int32_t)L_66) < ((int32_t)L_67)))
		{
			goto IL_0013;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:294>
		V_6 = 0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:297>
		int32_t L_68 = ___5_imm8;
		V_10 = ((int32_t)(((int32_t)(L_68>>2))&3));
		int32_t L_69 = V_10;
		switch (L_69)
		{
			case 0:
			{
				goto IL_01b2;
			}
			case 1:
			{
				goto IL_01ef;
			}
			case 2:
			{
				goto IL_0237;
			}
			case 3:
			{
				goto IL_025f;
			}
		}
	}
	{
		goto IL_02a5;
	}

IL_01b2:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:300>
		V_3 = 0;
		goto IL_01e5;
	}

IL_01b6:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:302>
		V_4 = 0;
		goto IL_01db;
	}

IL_01bb:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:304>
		int32_t L_70 = V_6;
		int32_t L_71 = V_4;
		int32_t L_72 = V_3;
		bool L_73;
		L_73 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_71, L_72, NULL);
		if (L_73)
		{
			G_B49_0 = L_70;
			goto IL_01cc;
		}
		G_B48_0 = L_70;
	}
	{
		G_B50_0 = 0;
		G_B50_1 = G_B48_0;
		goto IL_01cd;
	}

IL_01cc:
	{
		G_B50_0 = 1;
		G_B50_1 = G_B49_0;
	}

IL_01cd:
	{
		int32_t L_74 = V_3;
		V_6 = ((int32_t)(G_B50_1|((int32_t)(G_B50_0<<((int32_t)(L_74&((int32_t)31)))))));
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:302>
		int32_t L_75 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_75, 1));
	}

IL_01db:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:302>
		int32_t L_76 = V_4;
		int32_t L_77 = ___4_len;
		if ((((int32_t)L_76) < ((int32_t)L_77)))
		{
			goto IL_01bb;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:300>
		int32_t L_78 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_78, 1));
	}

IL_01e5:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:300>
		int32_t L_79 = V_3;
		int32_t L_80 = ___4_len;
		if ((((int32_t)L_79) < ((int32_t)L_80)))
		{
			goto IL_01b6;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:312>
		goto IL_02a5;
	}

IL_01ef:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:314>
		V_3 = 0;
		goto IL_0230;
	}

IL_01f3:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:316>
		V_4 = 0;
		goto IL_0226;
	}

IL_01f8:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:318>
		int32_t L_81 = V_6;
		int32_t L_82 = V_4;
		int32_t L_83 = V_3;
		bool L_84;
		L_84 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_82, L_83, NULL);
		if (!L_84)
		{
			G_B59_0 = L_81;
			goto IL_0214;
		}
		G_B58_0 = L_81;
	}
	{
		int32_t L_85 = V_4;
		int32_t L_86 = V_3;
		bool L_87;
		L_87 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), ((int32_t)il2cpp_codegen_add(L_85, 1)), L_86, NULL);
		if (L_87)
		{
			G_B60_0 = G_B58_0;
			goto IL_0217;
		}
		G_B59_0 = G_B58_0;
	}

IL_0214:
	{
		G_B61_0 = 0;
		G_B61_1 = G_B59_0;
		goto IL_0218;
	}

IL_0217:
	{
		G_B61_0 = 1;
		G_B61_1 = G_B60_0;
	}

IL_0218:
	{
		int32_t L_88 = V_3;
		V_6 = ((int32_t)(G_B61_1|((int32_t)(G_B61_0<<((int32_t)(L_88&((int32_t)31)))))));
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:316>
		int32_t L_89 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_89, 2));
	}

IL_0226:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:316>
		int32_t L_90 = V_4;
		int32_t L_91 = ___4_len;
		if ((((int32_t)L_90) < ((int32_t)L_91)))
		{
			goto IL_01f8;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:314>
		int32_t L_92 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_92, 1));
	}

IL_0230:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:314>
		int32_t L_93 = V_3;
		int32_t L_94 = ___4_len;
		if ((((int32_t)L_93) < ((int32_t)L_94)))
		{
			goto IL_01f3;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:321>
		goto IL_02a5;
	}

IL_0237:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:323>
		V_3 = 0;
		goto IL_0258;
	}

IL_023b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:325>
		int32_t L_95 = V_6;
		int32_t L_96 = V_3;
		int32_t L_97 = V_3;
		bool L_98;
		L_98 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_96, L_97, NULL);
		if (L_98)
		{
			G_B69_0 = L_95;
			goto IL_024b;
		}
		G_B68_0 = L_95;
	}
	{
		G_B70_0 = 0;
		G_B70_1 = G_B68_0;
		goto IL_024c;
	}

IL_024b:
	{
		G_B70_0 = 1;
		G_B70_1 = G_B69_0;
	}

IL_024c:
	{
		int32_t L_99 = V_3;
		V_6 = ((int32_t)(G_B70_1|((int32_t)(G_B70_0<<((int32_t)(L_99&((int32_t)31)))))));
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:323>
		int32_t L_100 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_100, 1));
	}

IL_0258:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:323>
		int32_t L_101 = V_3;
		int32_t L_102 = ___4_len;
		if ((((int32_t)L_101) < ((int32_t)L_102)))
		{
			goto IL_023b;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:327>
		goto IL_02a5;
	}

IL_025f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:329>
		int32_t L_103 = ___6_allOnes;
		V_6 = L_103;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:330>
		V_3 = 0;
		goto IL_02a0;
	}

IL_0267:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:332>
		int32_t L_104 = V_3;
		V_11 = L_104;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:333>
		V_4 = 0;
		goto IL_0294;
	}

IL_026f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:335>
		int32_t L_105 = V_4;
		int32_t L_106 = V_11;
		bool L_107;
		L_107 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_105, L_106, NULL);
		if (L_107)
		{
			goto IL_0288;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:336>
		int32_t L_108 = V_6;
		int32_t L_109 = V_3;
		V_6 = ((int32_t)(L_108&((~((int32_t)(1<<((int32_t)(L_109&((int32_t)31)))))))));
	}

IL_0288:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:337>
		int32_t L_110 = V_11;
		V_11 = ((int32_t)il2cpp_codegen_add(L_110, 1));
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:333>
		int32_t L_111 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_111, 1));
	}

IL_0294:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:333>
		int32_t L_112 = V_4;
		int32_t L_113 = ___4_len;
		int32_t L_114 = V_3;
		if ((((int32_t)L_112) < ((int32_t)((int32_t)il2cpp_codegen_subtract(L_113, L_114)))))
		{
			goto IL_026f;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:330>
		int32_t L_115 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_115, 1));
	}

IL_02a0:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:330>
		int32_t L_116 = V_3;
		int32_t L_117 = ___4_len;
		if ((((int32_t)L_116) < ((int32_t)L_117)))
		{
			goto IL_0267;
		}
	}

IL_02a5:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:343>
		V_5 = 0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:346>
		V_1 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:347>
		V_3 = 0;
		goto IL_032b;
	}

IL_02ae:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:349>
		int32_t L_118 = ___5_imm8;
		if (!((int32_t)(L_118&((int32_t)16))))
		{
			goto IL_0319;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:351>
		int32_t L_119 = ___5_imm8;
		if (!((int32_t)(L_119&((int32_t)32))))
		{
			goto IL_0308;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:353>
		EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* L_120;
		L_120 = EqualityComparer_1_get_Default_m7F71AAC0046A3CB8C4CEB06A5A52A1269AF7023D_inline(il2cpp_rgctx_method(method->rgctx_data, 2));
		int8_t* L_121 = ___2_b;
		int32_t L_122 = V_3;
		uint32_t L_123 = sizeof(int8_t);
		int8_t L_124 = (*(int8_t*)((int8_t*)il2cpp_codegen_add((intptr_t)L_121, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_122), (int32_t)L_123)))));
		il2cpp_codegen_initobj((&V_12), sizeof(int8_t));
		int8_t L_125 = V_12;
		NullCheck(L_120);
		bool L_126;
		L_126 = VirtualFuncInvoker2< bool, int8_t, int8_t >::Invoke(8, L_120, L_124, L_125);
		if (!L_126)
		{
			goto IL_02e4;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:355>
		V_1 = (bool)1;
	}

IL_02e4:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:358>
		bool L_127 = V_1;
		if (!L_127)
		{
			goto IL_02f7;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:359>
		int32_t L_128 = V_5;
		int32_t L_129 = V_6;
		int32_t L_130 = V_3;
		V_5 = ((int32_t)(L_128|((int32_t)(L_129&((int32_t)(1<<((int32_t)(L_130&((int32_t)31)))))))));
		goto IL_0327;
	}

IL_02f7:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:361>
		int32_t L_131 = V_5;
		int32_t L_132 = V_6;
		int32_t L_133 = V_3;
		V_5 = ((int32_t)(L_131|((int32_t)(((~L_132))&((int32_t)(1<<((int32_t)(L_133&((int32_t)31)))))))));
		goto IL_0327;
	}

IL_0308:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:364>
		int32_t L_134 = V_5;
		int32_t L_135 = V_6;
		int32_t L_136 = V_3;
		V_5 = ((int32_t)(L_134|((int32_t)(((~L_135))&((int32_t)(1<<((int32_t)(L_136&((int32_t)31)))))))));
		goto IL_0327;
	}

IL_0319:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:367>
		int32_t L_137 = V_5;
		int32_t L_138 = V_6;
		int32_t L_139 = V_3;
		V_5 = ((int32_t)(L_137|((int32_t)(L_138&((int32_t)(1<<((int32_t)(L_139&((int32_t)31)))))))));
	}

IL_0327:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:347>
		int32_t L_140 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_140, 1));
	}

IL_032b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:347>
		int32_t L_141 = V_3;
		int32_t L_142 = ___4_len;
		if ((((int32_t)L_141) < ((int32_t)L_142)))
		{
			goto IL_02ae;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:370>
		int32_t L_143 = V_5;
		return L_143;
	}
}
// Method Definition Index: 66213
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStrCmpIntRes2_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m331D979D640CF9DF04C505875F9FB702E217B2AB_gshared (uint16_t* ___0_a, int32_t ___1_alen, uint16_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	bool V_0 = false;
	bool V_1 = false;
	StrBoolArray_tCA66E1F688A4BC6FA749195F867F59E523508DD6 V_2;
	memset((&V_2), 0, sizeof(V_2));
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	uint16_t V_7 = 0;
	uint16_t V_8 = 0;
	bool V_9 = false;
	int32_t V_10 = 0;
	int32_t V_11 = 0;
	uint16_t V_12 = 0;
	int32_t G_B49_0 = 0;
	int32_t G_B48_0 = 0;
	int32_t G_B50_0 = 0;
	int32_t G_B50_1 = 0;
	int32_t G_B59_0 = 0;
	int32_t G_B58_0 = 0;
	int32_t G_B60_0 = 0;
	int32_t G_B61_0 = 0;
	int32_t G_B61_1 = 0;
	int32_t G_B69_0 = 0;
	int32_t G_B68_0 = 0;
	int32_t G_B70_0 = 0;
	int32_t G_B70_1 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:223>
		V_0 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:224>
		V_1 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:225>
		il2cpp_codegen_initobj((&V_2), sizeof(StrBoolArray_tCA66E1F688A4BC6FA749195F867F59E523508DD6));
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:228>
		V_3 = 0;
		goto IL_0183;
	}

IL_0013:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:230>
		uint16_t* L_0 = ___0_a;
		int32_t L_1 = V_3;
		uint32_t L_2 = sizeof(uint16_t);
		uint16_t L_3 = (*(uint16_t*)((uint16_t*)il2cpp_codegen_add((intptr_t)L_0, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_1), (int32_t)L_2)))));
		V_7 = L_3;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:232>
		int32_t L_4 = V_3;
		int32_t L_5 = ___1_alen;
		if ((!(((uint32_t)L_4) == ((uint32_t)L_5))))
		{
			goto IL_002b;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:233>
		V_0 = (bool)1;
	}

IL_002b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:235>
		V_1 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:236>
		V_4 = 0;
		goto IL_0176;
	}

IL_0035:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:238>
		uint16_t* L_6 = ___2_b;
		int32_t L_7 = V_4;
		uint32_t L_8 = sizeof(uint16_t);
		uint16_t L_9 = (*(uint16_t*)((uint16_t*)il2cpp_codegen_add((intptr_t)L_6, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_7), (int32_t)L_8)))));
		V_8 = L_9;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:239>
		int32_t L_10 = V_4;
		int32_t L_11 = ___3_blen;
		if ((!(((uint32_t)L_10) == ((uint32_t)L_11))))
		{
			goto IL_004f;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:240>
		V_1 = (bool)1;
	}

IL_004f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:245>
		int32_t L_12 = ___5_imm8;
		V_10 = ((int32_t)(((int32_t)(L_12>>2))&3));
		int32_t L_13 = V_10;
		switch (L_13)
		{
			case 0:
			{
				goto IL_006f;
			}
			case 1:
			{
				goto IL_00ad;
			}
			case 2:
			{
				goto IL_0102;
			}
		}
	}
	{
		goto IL_0134;
	}

IL_006f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:248>
		EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* L_14;
		L_14 = EqualityComparer_1_get_Default_m80EE5C179E01BB38904781592AC72F8137541D7E_inline(il2cpp_rgctx_method(method->rgctx_data, 2));
		uint16_t L_15 = V_7;
		uint16_t L_16 = V_8;
		NullCheck(L_14);
		bool L_17;
		L_17 = VirtualFuncInvoker2< bool, uint16_t, uint16_t >::Invoke(8, L_14, L_15, L_16);
		V_9 = L_17;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:249>
		bool L_18 = V_0;
		bool L_19 = V_1;
		if (!((int32_t)(((((int32_t)L_18) == ((int32_t)0))? 1 : 0)&(int32_t)L_19)))
		{
			goto IL_008f;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:250>
		V_9 = (bool)0;
		goto IL_0164;
	}

IL_008f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:251>
		bool L_20 = V_0;
		if (!L_20)
		{
			goto IL_009d;
		}
	}
	{
		bool L_21 = V_1;
		if (L_21)
		{
			goto IL_009d;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:252>
		V_9 = (bool)0;
		goto IL_0164;
	}

IL_009d:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:253>
		bool L_22 = V_0;
		bool L_23 = V_1;
		if (!((int32_t)((int32_t)L_22&(int32_t)L_23)))
		{
			goto IL_0164;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:254>
		V_9 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:255>
		goto IL_0164;
	}

IL_00ad:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:258>
		int32_t L_24 = V_3;
		if (((int32_t)(L_24&1)))
		{
			goto IL_00ca;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:259>
		Comparer_1_t58CF625431A0184A14FF0A33D14229F8F6EA3C98* L_25;
		L_25 = Comparer_1_get_Default_m5B4E9A09E85C87692450A9D2BC5C99C3E5DC1E36(il2cpp_rgctx_method(method->rgctx_data, 6));
		uint16_t L_26 = V_8;
		uint16_t L_27 = V_7;
		NullCheck(L_25);
		int32_t L_28;
		L_28 = VirtualFuncInvoker2< int32_t, uint16_t, uint16_t >::Invoke(6, L_25, L_26, L_27);
		V_9 = (bool)((((int32_t)((((int32_t)L_28) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		goto IL_00e0;
	}

IL_00ca:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:261>
		Comparer_1_t58CF625431A0184A14FF0A33D14229F8F6EA3C98* L_29;
		L_29 = Comparer_1_get_Default_m5B4E9A09E85C87692450A9D2BC5C99C3E5DC1E36(il2cpp_rgctx_method(method->rgctx_data, 6));
		uint16_t L_30 = V_8;
		uint16_t L_31 = V_7;
		NullCheck(L_29);
		int32_t L_32;
		L_32 = VirtualFuncInvoker2< int32_t, uint16_t, uint16_t >::Invoke(6, L_29, L_30, L_31);
		V_9 = (bool)((((int32_t)((((int32_t)L_32) > ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_00e0:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:263>
		bool L_33 = V_0;
		bool L_34 = V_1;
		if (!((int32_t)(((((int32_t)L_33) == ((int32_t)0))? 1 : 0)&(int32_t)L_34)))
		{
			goto IL_00ed;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:264>
		V_9 = (bool)0;
		goto IL_0164;
	}

IL_00ed:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:265>
		bool L_35 = V_0;
		if (!L_35)
		{
			goto IL_00f8;
		}
	}
	{
		bool L_36 = V_1;
		if (L_36)
		{
			goto IL_00f8;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:266>
		V_9 = (bool)0;
		goto IL_0164;
	}

IL_00f8:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:267>
		bool L_37 = V_0;
		bool L_38 = V_1;
		if (!((int32_t)((int32_t)L_37&(int32_t)L_38)))
		{
			goto IL_0164;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:268>
		V_9 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:269>
		goto IL_0164;
	}

IL_0102:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:271>
		EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* L_39;
		L_39 = EqualityComparer_1_get_Default_m80EE5C179E01BB38904781592AC72F8137541D7E_inline(il2cpp_rgctx_method(method->rgctx_data, 2));
		uint16_t L_40 = V_7;
		uint16_t L_41 = V_8;
		NullCheck(L_39);
		bool L_42;
		L_42 = VirtualFuncInvoker2< bool, uint16_t, uint16_t >::Invoke(8, L_39, L_40, L_41);
		V_9 = L_42;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:272>
		bool L_43 = V_0;
		bool L_44 = V_1;
		if (!((int32_t)(((((int32_t)L_43) == ((int32_t)0))? 1 : 0)&(int32_t)L_44)))
		{
			goto IL_011f;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:273>
		V_9 = (bool)0;
		goto IL_0164;
	}

IL_011f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:274>
		bool L_45 = V_0;
		if (!L_45)
		{
			goto IL_012a;
		}
	}
	{
		bool L_46 = V_1;
		if (L_46)
		{
			goto IL_012a;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:275>
		V_9 = (bool)0;
		goto IL_0164;
	}

IL_012a:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:276>
		bool L_47 = V_0;
		bool L_48 = V_1;
		if (!((int32_t)((int32_t)L_47&(int32_t)L_48)))
		{
			goto IL_0164;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:277>
		V_9 = (bool)1;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:278>
		goto IL_0164;
	}

IL_0134:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:280>
		EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* L_49;
		L_49 = EqualityComparer_1_get_Default_m80EE5C179E01BB38904781592AC72F8137541D7E_inline(il2cpp_rgctx_method(method->rgctx_data, 2));
		uint16_t L_50 = V_7;
		uint16_t L_51 = V_8;
		NullCheck(L_49);
		bool L_52;
		L_52 = VirtualFuncInvoker2< bool, uint16_t, uint16_t >::Invoke(8, L_49, L_50, L_51);
		V_9 = L_52;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:281>
		bool L_53 = V_0;
		bool L_54 = V_1;
		if (!((int32_t)(((((int32_t)L_53) == ((int32_t)0))? 1 : 0)&(int32_t)L_54)))
		{
			goto IL_0151;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:282>
		V_9 = (bool)0;
		goto IL_0164;
	}

IL_0151:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:283>
		bool L_55 = V_0;
		if (!L_55)
		{
			goto IL_015c;
		}
	}
	{
		bool L_56 = V_1;
		if (L_56)
		{
			goto IL_015c;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:284>
		V_9 = (bool)1;
		goto IL_0164;
	}

IL_015c:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:285>
		bool L_57 = V_0;
		bool L_58 = V_1;
		if (!((int32_t)((int32_t)L_57&(int32_t)L_58)))
		{
			goto IL_0164;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:286>
		V_9 = (bool)1;
	}

IL_0164:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:290>
		int32_t L_59 = V_3;
		int32_t L_60 = V_4;
		bool L_61 = V_9;
		StrBoolArray_SetBit_m212C6D1A8A4C422AF979D6B3BC7CD5B9BD0F3F01((&V_2), L_59, L_60, L_61, NULL);
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:236>
		int32_t L_62 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_62, 1));
	}

IL_0176:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:236>
		int32_t L_63 = V_4;
		int32_t L_64 = ___4_len;
		if ((((int32_t)L_63) < ((int32_t)L_64)))
		{
			goto IL_0035;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:228>
		int32_t L_65 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_65, 1));
	}

IL_0183:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:228>
		int32_t L_66 = V_3;
		int32_t L_67 = ___4_len;
		if ((((int32_t)L_66) < ((int32_t)L_67)))
		{
			goto IL_0013;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:294>
		V_6 = 0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:297>
		int32_t L_68 = ___5_imm8;
		V_10 = ((int32_t)(((int32_t)(L_68>>2))&3));
		int32_t L_69 = V_10;
		switch (L_69)
		{
			case 0:
			{
				goto IL_01b2;
			}
			case 1:
			{
				goto IL_01ef;
			}
			case 2:
			{
				goto IL_0237;
			}
			case 3:
			{
				goto IL_025f;
			}
		}
	}
	{
		goto IL_02a5;
	}

IL_01b2:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:300>
		V_3 = 0;
		goto IL_01e5;
	}

IL_01b6:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:302>
		V_4 = 0;
		goto IL_01db;
	}

IL_01bb:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:304>
		int32_t L_70 = V_6;
		int32_t L_71 = V_4;
		int32_t L_72 = V_3;
		bool L_73;
		L_73 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_71, L_72, NULL);
		if (L_73)
		{
			G_B49_0 = L_70;
			goto IL_01cc;
		}
		G_B48_0 = L_70;
	}
	{
		G_B50_0 = 0;
		G_B50_1 = G_B48_0;
		goto IL_01cd;
	}

IL_01cc:
	{
		G_B50_0 = 1;
		G_B50_1 = G_B49_0;
	}

IL_01cd:
	{
		int32_t L_74 = V_3;
		V_6 = ((int32_t)(G_B50_1|((int32_t)(G_B50_0<<((int32_t)(L_74&((int32_t)31)))))));
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:302>
		int32_t L_75 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_75, 1));
	}

IL_01db:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:302>
		int32_t L_76 = V_4;
		int32_t L_77 = ___4_len;
		if ((((int32_t)L_76) < ((int32_t)L_77)))
		{
			goto IL_01bb;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:300>
		int32_t L_78 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_78, 1));
	}

IL_01e5:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:300>
		int32_t L_79 = V_3;
		int32_t L_80 = ___4_len;
		if ((((int32_t)L_79) < ((int32_t)L_80)))
		{
			goto IL_01b6;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:312>
		goto IL_02a5;
	}

IL_01ef:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:314>
		V_3 = 0;
		goto IL_0230;
	}

IL_01f3:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:316>
		V_4 = 0;
		goto IL_0226;
	}

IL_01f8:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:318>
		int32_t L_81 = V_6;
		int32_t L_82 = V_4;
		int32_t L_83 = V_3;
		bool L_84;
		L_84 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_82, L_83, NULL);
		if (!L_84)
		{
			G_B59_0 = L_81;
			goto IL_0214;
		}
		G_B58_0 = L_81;
	}
	{
		int32_t L_85 = V_4;
		int32_t L_86 = V_3;
		bool L_87;
		L_87 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), ((int32_t)il2cpp_codegen_add(L_85, 1)), L_86, NULL);
		if (L_87)
		{
			G_B60_0 = G_B58_0;
			goto IL_0217;
		}
		G_B59_0 = G_B58_0;
	}

IL_0214:
	{
		G_B61_0 = 0;
		G_B61_1 = G_B59_0;
		goto IL_0218;
	}

IL_0217:
	{
		G_B61_0 = 1;
		G_B61_1 = G_B60_0;
	}

IL_0218:
	{
		int32_t L_88 = V_3;
		V_6 = ((int32_t)(G_B61_1|((int32_t)(G_B61_0<<((int32_t)(L_88&((int32_t)31)))))));
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:316>
		int32_t L_89 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_89, 2));
	}

IL_0226:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:316>
		int32_t L_90 = V_4;
		int32_t L_91 = ___4_len;
		if ((((int32_t)L_90) < ((int32_t)L_91)))
		{
			goto IL_01f8;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:314>
		int32_t L_92 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_92, 1));
	}

IL_0230:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:314>
		int32_t L_93 = V_3;
		int32_t L_94 = ___4_len;
		if ((((int32_t)L_93) < ((int32_t)L_94)))
		{
			goto IL_01f3;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:321>
		goto IL_02a5;
	}

IL_0237:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:323>
		V_3 = 0;
		goto IL_0258;
	}

IL_023b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:325>
		int32_t L_95 = V_6;
		int32_t L_96 = V_3;
		int32_t L_97 = V_3;
		bool L_98;
		L_98 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_96, L_97, NULL);
		if (L_98)
		{
			G_B69_0 = L_95;
			goto IL_024b;
		}
		G_B68_0 = L_95;
	}
	{
		G_B70_0 = 0;
		G_B70_1 = G_B68_0;
		goto IL_024c;
	}

IL_024b:
	{
		G_B70_0 = 1;
		G_B70_1 = G_B69_0;
	}

IL_024c:
	{
		int32_t L_99 = V_3;
		V_6 = ((int32_t)(G_B70_1|((int32_t)(G_B70_0<<((int32_t)(L_99&((int32_t)31)))))));
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:323>
		int32_t L_100 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_100, 1));
	}

IL_0258:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:323>
		int32_t L_101 = V_3;
		int32_t L_102 = ___4_len;
		if ((((int32_t)L_101) < ((int32_t)L_102)))
		{
			goto IL_023b;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:327>
		goto IL_02a5;
	}

IL_025f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:329>
		int32_t L_103 = ___6_allOnes;
		V_6 = L_103;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:330>
		V_3 = 0;
		goto IL_02a0;
	}

IL_0267:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:332>
		int32_t L_104 = V_3;
		V_11 = L_104;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:333>
		V_4 = 0;
		goto IL_0294;
	}

IL_026f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:335>
		int32_t L_105 = V_4;
		int32_t L_106 = V_11;
		bool L_107;
		L_107 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_105, L_106, NULL);
		if (L_107)
		{
			goto IL_0288;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:336>
		int32_t L_108 = V_6;
		int32_t L_109 = V_3;
		V_6 = ((int32_t)(L_108&((~((int32_t)(1<<((int32_t)(L_109&((int32_t)31)))))))));
	}

IL_0288:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:337>
		int32_t L_110 = V_11;
		V_11 = ((int32_t)il2cpp_codegen_add(L_110, 1));
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:333>
		int32_t L_111 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_111, 1));
	}

IL_0294:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:333>
		int32_t L_112 = V_4;
		int32_t L_113 = ___4_len;
		int32_t L_114 = V_3;
		if ((((int32_t)L_112) < ((int32_t)((int32_t)il2cpp_codegen_subtract(L_113, L_114)))))
		{
			goto IL_026f;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:330>
		int32_t L_115 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_115, 1));
	}

IL_02a0:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:330>
		int32_t L_116 = V_3;
		int32_t L_117 = ___4_len;
		if ((((int32_t)L_116) < ((int32_t)L_117)))
		{
			goto IL_0267;
		}
	}

IL_02a5:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:343>
		V_5 = 0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:346>
		V_1 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:347>
		V_3 = 0;
		goto IL_032b;
	}

IL_02ae:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:349>
		int32_t L_118 = ___5_imm8;
		if (!((int32_t)(L_118&((int32_t)16))))
		{
			goto IL_0319;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:351>
		int32_t L_119 = ___5_imm8;
		if (!((int32_t)(L_119&((int32_t)32))))
		{
			goto IL_0308;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:353>
		EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* L_120;
		L_120 = EqualityComparer_1_get_Default_m80EE5C179E01BB38904781592AC72F8137541D7E_inline(il2cpp_rgctx_method(method->rgctx_data, 2));
		uint16_t* L_121 = ___2_b;
		int32_t L_122 = V_3;
		uint32_t L_123 = sizeof(uint16_t);
		uint16_t L_124 = (*(uint16_t*)((uint16_t*)il2cpp_codegen_add((intptr_t)L_121, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_122), (int32_t)L_123)))));
		il2cpp_codegen_initobj((&V_12), sizeof(uint16_t));
		uint16_t L_125 = V_12;
		NullCheck(L_120);
		bool L_126;
		L_126 = VirtualFuncInvoker2< bool, uint16_t, uint16_t >::Invoke(8, L_120, L_124, L_125);
		if (!L_126)
		{
			goto IL_02e4;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:355>
		V_1 = (bool)1;
	}

IL_02e4:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:358>
		bool L_127 = V_1;
		if (!L_127)
		{
			goto IL_02f7;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:359>
		int32_t L_128 = V_5;
		int32_t L_129 = V_6;
		int32_t L_130 = V_3;
		V_5 = ((int32_t)(L_128|((int32_t)(L_129&((int32_t)(1<<((int32_t)(L_130&((int32_t)31)))))))));
		goto IL_0327;
	}

IL_02f7:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:361>
		int32_t L_131 = V_5;
		int32_t L_132 = V_6;
		int32_t L_133 = V_3;
		V_5 = ((int32_t)(L_131|((int32_t)(((~L_132))&((int32_t)(1<<((int32_t)(L_133&((int32_t)31)))))))));
		goto IL_0327;
	}

IL_0308:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:364>
		int32_t L_134 = V_5;
		int32_t L_135 = V_6;
		int32_t L_136 = V_3;
		V_5 = ((int32_t)(L_134|((int32_t)(((~L_135))&((int32_t)(1<<((int32_t)(L_136&((int32_t)31)))))))));
		goto IL_0327;
	}

IL_0319:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:367>
		int32_t L_137 = V_5;
		int32_t L_138 = V_6;
		int32_t L_139 = V_3;
		V_5 = ((int32_t)(L_137|((int32_t)(L_138&((int32_t)(1<<((int32_t)(L_139&((int32_t)31)))))))));
	}

IL_0327:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:347>
		int32_t L_140 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_140, 1));
	}

IL_032b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:347>
		int32_t L_141 = V_3;
		int32_t L_142 = ___4_len;
		if ((((int32_t)L_141) < ((int32_t)L_142)))
		{
			goto IL_02ae;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:370>
		int32_t L_143 = V_5;
		return L_143;
	}
}
// Method Definition Index: 66213
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStrCmpIntRes2_TisIl2CppFullySharedGenericStruct_m5BBC7FD25430C93A4DCF34A210DE56367BA1E204_gshared (Il2CppFullySharedGenericStruct* ___0_a, int32_t ___1_alen, Il2CppFullySharedGenericStruct* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 1));
	const Il2CppFullySharedGenericStruct L_3 = alloca(SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
	const Il2CppFullySharedGenericStruct L_9 = L_3;
	const Il2CppFullySharedGenericStruct L_15 = L_3;
	const Il2CppFullySharedGenericStruct L_26 = L_3;
	const Il2CppFullySharedGenericStruct L_30 = L_3;
	const Il2CppFullySharedGenericStruct L_40 = L_3;
	const Il2CppFullySharedGenericStruct L_50 = L_3;
	const Il2CppFullySharedGenericStruct L_124 = L_3;
	const Il2CppFullySharedGenericStruct L_16 = alloca(SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
	const Il2CppFullySharedGenericStruct L_27 = L_16;
	const Il2CppFullySharedGenericStruct L_31 = L_16;
	const Il2CppFullySharedGenericStruct L_41 = L_16;
	const Il2CppFullySharedGenericStruct L_51 = L_16;
	const Il2CppFullySharedGenericStruct L_125 = L_16;
	bool V_0 = false;
	bool V_1 = false;
	StrBoolArray_tCA66E1F688A4BC6FA749195F867F59E523508DD6 V_2;
	memset((&V_2), 0, sizeof(V_2));
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	Il2CppFullySharedGenericStruct V_7 = alloca(SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
	memset(V_7, 0, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
	Il2CppFullySharedGenericStruct V_8 = alloca(SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
	memset(V_8, 0, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
	bool V_9 = false;
	int32_t V_10 = 0;
	int32_t V_11 = 0;
	Il2CppFullySharedGenericStruct V_12 = alloca(SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
	memset(V_12, 0, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
	int32_t G_B49_0 = 0;
	int32_t G_B48_0 = 0;
	int32_t G_B50_0 = 0;
	int32_t G_B50_1 = 0;
	int32_t G_B59_0 = 0;
	int32_t G_B58_0 = 0;
	int32_t G_B60_0 = 0;
	int32_t G_B61_0 = 0;
	int32_t G_B61_1 = 0;
	int32_t G_B69_0 = 0;
	int32_t G_B68_0 = 0;
	int32_t G_B70_0 = 0;
	int32_t G_B70_1 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:223>
		V_0 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:224>
		V_1 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:225>
		il2cpp_codegen_initobj((&V_2), sizeof(StrBoolArray_tCA66E1F688A4BC6FA749195F867F59E523508DD6));
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:228>
		V_3 = 0;
		goto IL_0183;
	}

IL_0013:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:230>
		Il2CppFullySharedGenericStruct* L_0 = ___0_a;
		int32_t L_1 = V_3;
		uint32_t L_2 = SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77;
		il2cpp_codegen_memcpy(L_3, ((Il2CppFullySharedGenericStruct*)il2cpp_codegen_add((intptr_t)L_0, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_1), (int32_t)L_2)))), SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		il2cpp_codegen_memcpy(V_7, L_3, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:232>
		int32_t L_4 = V_3;
		int32_t L_5 = ___1_alen;
		if ((!(((uint32_t)L_4) == ((uint32_t)L_5))))
		{
			goto IL_002b;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:233>
		V_0 = (bool)1;
	}

IL_002b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:235>
		V_1 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:236>
		V_4 = 0;
		goto IL_0176;
	}

IL_0035:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:238>
		Il2CppFullySharedGenericStruct* L_6 = ___2_b;
		int32_t L_7 = V_4;
		uint32_t L_8 = SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77;
		il2cpp_codegen_memcpy(L_9, ((Il2CppFullySharedGenericStruct*)il2cpp_codegen_add((intptr_t)L_6, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_7), (int32_t)L_8)))), SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		il2cpp_codegen_memcpy(V_8, L_9, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:239>
		int32_t L_10 = V_4;
		int32_t L_11 = ___3_blen;
		if ((!(((uint32_t)L_10) == ((uint32_t)L_11))))
		{
			goto IL_004f;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:240>
		V_1 = (bool)1;
	}

IL_004f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:245>
		int32_t L_12 = ___5_imm8;
		V_10 = ((int32_t)(((int32_t)(L_12>>2))&3));
		int32_t L_13 = V_10;
		switch (L_13)
		{
			case 0:
			{
				goto IL_006f;
			}
			case 1:
			{
				goto IL_00ad;
			}
			case 2:
			{
				goto IL_0102;
			}
		}
	}
	{
		goto IL_0134;
	}

IL_006f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:248>
		EqualityComparer_1_t458C8DC3748A89A213F4738B57D3742C4896ABE9* L_14;
		L_14 = ((  EqualityComparer_1_t458C8DC3748A89A213F4738B57D3742C4896ABE9* (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		il2cpp_codegen_memcpy(L_15, V_7, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		il2cpp_codegen_memcpy(L_16, V_8, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		NullCheck(L_14);
		bool L_17;
		L_17 = VirtualFuncInvoker2Invoker< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(8, L_14, L_15, L_16);
		V_9 = L_17;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:249>
		bool L_18 = V_0;
		bool L_19 = V_1;
		if (!((int32_t)(((((int32_t)L_18) == ((int32_t)0))? 1 : 0)&(int32_t)L_19)))
		{
			goto IL_008f;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:250>
		V_9 = (bool)0;
		goto IL_0164;
	}

IL_008f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:251>
		bool L_20 = V_0;
		if (!L_20)
		{
			goto IL_009d;
		}
	}
	{
		bool L_21 = V_1;
		if (L_21)
		{
			goto IL_009d;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:252>
		V_9 = (bool)0;
		goto IL_0164;
	}

IL_009d:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:253>
		bool L_22 = V_0;
		bool L_23 = V_1;
		if (!((int32_t)((int32_t)L_22&(int32_t)L_23)))
		{
			goto IL_0164;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:254>
		V_9 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:255>
		goto IL_0164;
	}

IL_00ad:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:258>
		int32_t L_24 = V_3;
		if (((int32_t)(L_24&1)))
		{
			goto IL_00ca;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:259>
		Comparer_1_t535E02B3998AA8B49230077EF0DFCB16BA44C985* L_25;
		L_25 = ((  Comparer_1_t535E02B3998AA8B49230077EF0DFCB16BA44C985* (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 6)))(il2cpp_rgctx_method(method->rgctx_data, 6));
		il2cpp_codegen_memcpy(L_26, V_8, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		il2cpp_codegen_memcpy(L_27, V_7, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		NullCheck(L_25);
		int32_t L_28;
		L_28 = VirtualFuncInvoker2Invoker< int32_t, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(6, L_25, L_26, L_27);
		V_9 = (bool)((((int32_t)((((int32_t)L_28) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		goto IL_00e0;
	}

IL_00ca:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:261>
		Comparer_1_t535E02B3998AA8B49230077EF0DFCB16BA44C985* L_29;
		L_29 = ((  Comparer_1_t535E02B3998AA8B49230077EF0DFCB16BA44C985* (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 6)))(il2cpp_rgctx_method(method->rgctx_data, 6));
		il2cpp_codegen_memcpy(L_30, V_8, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		il2cpp_codegen_memcpy(L_31, V_7, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		NullCheck(L_29);
		int32_t L_32;
		L_32 = VirtualFuncInvoker2Invoker< int32_t, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(6, L_29, L_30, L_31);
		V_9 = (bool)((((int32_t)((((int32_t)L_32) > ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_00e0:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:263>
		bool L_33 = V_0;
		bool L_34 = V_1;
		if (!((int32_t)(((((int32_t)L_33) == ((int32_t)0))? 1 : 0)&(int32_t)L_34)))
		{
			goto IL_00ed;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:264>
		V_9 = (bool)0;
		goto IL_0164;
	}

IL_00ed:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:265>
		bool L_35 = V_0;
		if (!L_35)
		{
			goto IL_00f8;
		}
	}
	{
		bool L_36 = V_1;
		if (L_36)
		{
			goto IL_00f8;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:266>
		V_9 = (bool)0;
		goto IL_0164;
	}

IL_00f8:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:267>
		bool L_37 = V_0;
		bool L_38 = V_1;
		if (!((int32_t)((int32_t)L_37&(int32_t)L_38)))
		{
			goto IL_0164;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:268>
		V_9 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:269>
		goto IL_0164;
	}

IL_0102:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:271>
		EqualityComparer_1_t458C8DC3748A89A213F4738B57D3742C4896ABE9* L_39;
		L_39 = ((  EqualityComparer_1_t458C8DC3748A89A213F4738B57D3742C4896ABE9* (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		il2cpp_codegen_memcpy(L_40, V_7, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		il2cpp_codegen_memcpy(L_41, V_8, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		NullCheck(L_39);
		bool L_42;
		L_42 = VirtualFuncInvoker2Invoker< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(8, L_39, L_40, L_41);
		V_9 = L_42;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:272>
		bool L_43 = V_0;
		bool L_44 = V_1;
		if (!((int32_t)(((((int32_t)L_43) == ((int32_t)0))? 1 : 0)&(int32_t)L_44)))
		{
			goto IL_011f;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:273>
		V_9 = (bool)0;
		goto IL_0164;
	}

IL_011f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:274>
		bool L_45 = V_0;
		if (!L_45)
		{
			goto IL_012a;
		}
	}
	{
		bool L_46 = V_1;
		if (L_46)
		{
			goto IL_012a;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:275>
		V_9 = (bool)0;
		goto IL_0164;
	}

IL_012a:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:276>
		bool L_47 = V_0;
		bool L_48 = V_1;
		if (!((int32_t)((int32_t)L_47&(int32_t)L_48)))
		{
			goto IL_0164;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:277>
		V_9 = (bool)1;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:278>
		goto IL_0164;
	}

IL_0134:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:280>
		EqualityComparer_1_t458C8DC3748A89A213F4738B57D3742C4896ABE9* L_49;
		L_49 = ((  EqualityComparer_1_t458C8DC3748A89A213F4738B57D3742C4896ABE9* (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		il2cpp_codegen_memcpy(L_50, V_7, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		il2cpp_codegen_memcpy(L_51, V_8, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		NullCheck(L_49);
		bool L_52;
		L_52 = VirtualFuncInvoker2Invoker< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(8, L_49, L_50, L_51);
		V_9 = L_52;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:281>
		bool L_53 = V_0;
		bool L_54 = V_1;
		if (!((int32_t)(((((int32_t)L_53) == ((int32_t)0))? 1 : 0)&(int32_t)L_54)))
		{
			goto IL_0151;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:282>
		V_9 = (bool)0;
		goto IL_0164;
	}

IL_0151:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:283>
		bool L_55 = V_0;
		if (!L_55)
		{
			goto IL_015c;
		}
	}
	{
		bool L_56 = V_1;
		if (L_56)
		{
			goto IL_015c;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:284>
		V_9 = (bool)1;
		goto IL_0164;
	}

IL_015c:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:285>
		bool L_57 = V_0;
		bool L_58 = V_1;
		if (!((int32_t)((int32_t)L_57&(int32_t)L_58)))
		{
			goto IL_0164;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:286>
		V_9 = (bool)1;
	}

IL_0164:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:290>
		int32_t L_59 = V_3;
		int32_t L_60 = V_4;
		bool L_61 = V_9;
		StrBoolArray_SetBit_m212C6D1A8A4C422AF979D6B3BC7CD5B9BD0F3F01((&V_2), L_59, L_60, L_61, NULL);
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:236>
		int32_t L_62 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_62, 1));
	}

IL_0176:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:236>
		int32_t L_63 = V_4;
		int32_t L_64 = ___4_len;
		if ((((int32_t)L_63) < ((int32_t)L_64)))
		{
			goto IL_0035;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:228>
		int32_t L_65 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_65, 1));
	}

IL_0183:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:228>
		int32_t L_66 = V_3;
		int32_t L_67 = ___4_len;
		if ((((int32_t)L_66) < ((int32_t)L_67)))
		{
			goto IL_0013;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:294>
		V_6 = 0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:297>
		int32_t L_68 = ___5_imm8;
		V_10 = ((int32_t)(((int32_t)(L_68>>2))&3));
		int32_t L_69 = V_10;
		switch (L_69)
		{
			case 0:
			{
				goto IL_01b2;
			}
			case 1:
			{
				goto IL_01ef;
			}
			case 2:
			{
				goto IL_0237;
			}
			case 3:
			{
				goto IL_025f;
			}
		}
	}
	{
		goto IL_02a5;
	}

IL_01b2:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:300>
		V_3 = 0;
		goto IL_01e5;
	}

IL_01b6:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:302>
		V_4 = 0;
		goto IL_01db;
	}

IL_01bb:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:304>
		int32_t L_70 = V_6;
		int32_t L_71 = V_4;
		int32_t L_72 = V_3;
		bool L_73;
		L_73 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_71, L_72, NULL);
		if (L_73)
		{
			G_B49_0 = L_70;
			goto IL_01cc;
		}
		G_B48_0 = L_70;
	}
	{
		G_B50_0 = 0;
		G_B50_1 = G_B48_0;
		goto IL_01cd;
	}

IL_01cc:
	{
		G_B50_0 = 1;
		G_B50_1 = G_B49_0;
	}

IL_01cd:
	{
		int32_t L_74 = V_3;
		V_6 = ((int32_t)(G_B50_1|((int32_t)(G_B50_0<<((int32_t)(L_74&((int32_t)31)))))));
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:302>
		int32_t L_75 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_75, 1));
	}

IL_01db:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:302>
		int32_t L_76 = V_4;
		int32_t L_77 = ___4_len;
		if ((((int32_t)L_76) < ((int32_t)L_77)))
		{
			goto IL_01bb;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:300>
		int32_t L_78 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_78, 1));
	}

IL_01e5:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:300>
		int32_t L_79 = V_3;
		int32_t L_80 = ___4_len;
		if ((((int32_t)L_79) < ((int32_t)L_80)))
		{
			goto IL_01b6;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:312>
		goto IL_02a5;
	}

IL_01ef:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:314>
		V_3 = 0;
		goto IL_0230;
	}

IL_01f3:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:316>
		V_4 = 0;
		goto IL_0226;
	}

IL_01f8:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:318>
		int32_t L_81 = V_6;
		int32_t L_82 = V_4;
		int32_t L_83 = V_3;
		bool L_84;
		L_84 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_82, L_83, NULL);
		if (!L_84)
		{
			G_B59_0 = L_81;
			goto IL_0214;
		}
		G_B58_0 = L_81;
	}
	{
		int32_t L_85 = V_4;
		int32_t L_86 = V_3;
		bool L_87;
		L_87 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), ((int32_t)il2cpp_codegen_add(L_85, 1)), L_86, NULL);
		if (L_87)
		{
			G_B60_0 = G_B58_0;
			goto IL_0217;
		}
		G_B59_0 = G_B58_0;
	}

IL_0214:
	{
		G_B61_0 = 0;
		G_B61_1 = G_B59_0;
		goto IL_0218;
	}

IL_0217:
	{
		G_B61_0 = 1;
		G_B61_1 = G_B60_0;
	}

IL_0218:
	{
		int32_t L_88 = V_3;
		V_6 = ((int32_t)(G_B61_1|((int32_t)(G_B61_0<<((int32_t)(L_88&((int32_t)31)))))));
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:316>
		int32_t L_89 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_89, 2));
	}

IL_0226:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:316>
		int32_t L_90 = V_4;
		int32_t L_91 = ___4_len;
		if ((((int32_t)L_90) < ((int32_t)L_91)))
		{
			goto IL_01f8;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:314>
		int32_t L_92 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_92, 1));
	}

IL_0230:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:314>
		int32_t L_93 = V_3;
		int32_t L_94 = ___4_len;
		if ((((int32_t)L_93) < ((int32_t)L_94)))
		{
			goto IL_01f3;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:321>
		goto IL_02a5;
	}

IL_0237:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:323>
		V_3 = 0;
		goto IL_0258;
	}

IL_023b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:325>
		int32_t L_95 = V_6;
		int32_t L_96 = V_3;
		int32_t L_97 = V_3;
		bool L_98;
		L_98 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_96, L_97, NULL);
		if (L_98)
		{
			G_B69_0 = L_95;
			goto IL_024b;
		}
		G_B68_0 = L_95;
	}
	{
		G_B70_0 = 0;
		G_B70_1 = G_B68_0;
		goto IL_024c;
	}

IL_024b:
	{
		G_B70_0 = 1;
		G_B70_1 = G_B69_0;
	}

IL_024c:
	{
		int32_t L_99 = V_3;
		V_6 = ((int32_t)(G_B70_1|((int32_t)(G_B70_0<<((int32_t)(L_99&((int32_t)31)))))));
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:323>
		int32_t L_100 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_100, 1));
	}

IL_0258:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:323>
		int32_t L_101 = V_3;
		int32_t L_102 = ___4_len;
		if ((((int32_t)L_101) < ((int32_t)L_102)))
		{
			goto IL_023b;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:327>
		goto IL_02a5;
	}

IL_025f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:329>
		int32_t L_103 = ___6_allOnes;
		V_6 = L_103;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:330>
		V_3 = 0;
		goto IL_02a0;
	}

IL_0267:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:332>
		int32_t L_104 = V_3;
		V_11 = L_104;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:333>
		V_4 = 0;
		goto IL_0294;
	}

IL_026f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:335>
		int32_t L_105 = V_4;
		int32_t L_106 = V_11;
		bool L_107;
		L_107 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_105, L_106, NULL);
		if (L_107)
		{
			goto IL_0288;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:336>
		int32_t L_108 = V_6;
		int32_t L_109 = V_3;
		V_6 = ((int32_t)(L_108&((~((int32_t)(1<<((int32_t)(L_109&((int32_t)31)))))))));
	}

IL_0288:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:337>
		int32_t L_110 = V_11;
		V_11 = ((int32_t)il2cpp_codegen_add(L_110, 1));
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:333>
		int32_t L_111 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_111, 1));
	}

IL_0294:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:333>
		int32_t L_112 = V_4;
		int32_t L_113 = ___4_len;
		int32_t L_114 = V_3;
		if ((((int32_t)L_112) < ((int32_t)((int32_t)il2cpp_codegen_subtract(L_113, L_114)))))
		{
			goto IL_026f;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:330>
		int32_t L_115 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_115, 1));
	}

IL_02a0:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:330>
		int32_t L_116 = V_3;
		int32_t L_117 = ___4_len;
		if ((((int32_t)L_116) < ((int32_t)L_117)))
		{
			goto IL_0267;
		}
	}

IL_02a5:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:343>
		V_5 = 0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:346>
		V_1 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:347>
		V_3 = 0;
		goto IL_032b;
	}

IL_02ae:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:349>
		int32_t L_118 = ___5_imm8;
		if (!((int32_t)(L_118&((int32_t)16))))
		{
			goto IL_0319;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:351>
		int32_t L_119 = ___5_imm8;
		if (!((int32_t)(L_119&((int32_t)32))))
		{
			goto IL_0308;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:353>
		EqualityComparer_1_t458C8DC3748A89A213F4738B57D3742C4896ABE9* L_120;
		L_120 = ((  EqualityComparer_1_t458C8DC3748A89A213F4738B57D3742C4896ABE9* (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		Il2CppFullySharedGenericStruct* L_121 = ___2_b;
		int32_t L_122 = V_3;
		uint32_t L_123 = SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77;
		il2cpp_codegen_memcpy(L_124, ((Il2CppFullySharedGenericStruct*)il2cpp_codegen_add((intptr_t)L_121, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_122), (int32_t)L_123)))), SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericStruct*)V_12, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		il2cpp_codegen_memcpy(L_125, V_12, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		NullCheck(L_120);
		bool L_126;
		L_126 = VirtualFuncInvoker2Invoker< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(8, L_120, L_124, L_125);
		if (!L_126)
		{
			goto IL_02e4;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:355>
		V_1 = (bool)1;
	}

IL_02e4:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:358>
		bool L_127 = V_1;
		if (!L_127)
		{
			goto IL_02f7;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:359>
		int32_t L_128 = V_5;
		int32_t L_129 = V_6;
		int32_t L_130 = V_3;
		V_5 = ((int32_t)(L_128|((int32_t)(L_129&((int32_t)(1<<((int32_t)(L_130&((int32_t)31)))))))));
		goto IL_0327;
	}

IL_02f7:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:361>
		int32_t L_131 = V_5;
		int32_t L_132 = V_6;
		int32_t L_133 = V_3;
		V_5 = ((int32_t)(L_131|((int32_t)(((~L_132))&((int32_t)(1<<((int32_t)(L_133&((int32_t)31)))))))));
		goto IL_0327;
	}

IL_0308:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:364>
		int32_t L_134 = V_5;
		int32_t L_135 = V_6;
		int32_t L_136 = V_3;
		V_5 = ((int32_t)(L_134|((int32_t)(((~L_135))&((int32_t)(1<<((int32_t)(L_136&((int32_t)31)))))))));
		goto IL_0327;
	}

IL_0319:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:367>
		int32_t L_137 = V_5;
		int32_t L_138 = V_6;
		int32_t L_139 = V_3;
		V_5 = ((int32_t)(L_137|((int32_t)(L_138&((int32_t)(1<<((int32_t)(L_139&((int32_t)31)))))))));
	}

IL_0327:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:347>
		int32_t L_140 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_140, 1));
	}

IL_032b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:347>
		int32_t L_141 = V_3;
		int32_t L_142 = ___4_len;
		if ((((int32_t)L_141) < ((int32_t)L_142)))
		{
			goto IL_02ae;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:370>
		int32_t L_143 = V_5;
		return L_143;
	}
}
// Method Definition Index: 66212
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStringLength_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mD30812062AA4852D166ABCDF3D79FDD1856F173A_gshared (uint8_t* ___0_ptr, int32_t ___1_max, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	int32_t V_0 = 0;
	uint8_t V_1 = 0x0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:210>
		V_0 = 0;
		goto IL_002f;
	}

IL_0004:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:212>
		EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* L_0;
		L_0 = EqualityComparer_1_get_Default_m41DB4C0E0A508A8326E903331DC63D410B7AB9C4_inline(il2cpp_rgctx_method(method->rgctx_data, 0));
		uint8_t* L_1 = ___0_ptr;
		int32_t L_2 = V_0;
		uint32_t L_3 = sizeof(uint8_t);
		uint8_t L_4 = (*(uint8_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_1, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_2), (int32_t)L_3)))));
		il2cpp_codegen_initobj((&V_1), sizeof(uint8_t));
		uint8_t L_5 = V_1;
		NullCheck(L_0);
		bool L_6;
		L_6 = VirtualFuncInvoker2< bool, uint8_t, uint8_t >::Invoke(8, L_0, L_4, L_5);
		if (!L_6)
		{
			goto IL_002b;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:214>
		int32_t L_7 = V_0;
		return L_7;
	}

IL_002b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:210>
		int32_t L_8 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_8, 1));
	}

IL_002f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:210>
		int32_t L_9 = V_0;
		int32_t L_10 = ___1_max;
		if ((((int32_t)L_9) < ((int32_t)L_10)))
		{
			goto IL_0004;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:217>
		int32_t L_11 = ___1_max;
		return L_11;
	}
}
// Method Definition Index: 66212
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStringLength_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m3EBC75C6F39A7B1A5F62D88877C87C9F3B5617A3_gshared (int16_t* ___0_ptr, int32_t ___1_max, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	int32_t V_0 = 0;
	int16_t V_1 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:210>
		V_0 = 0;
		goto IL_002f;
	}

IL_0004:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:212>
		EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* L_0;
		L_0 = EqualityComparer_1_get_Default_m7D273CC532DC2164C9C86D28C639FDEA38173C88_inline(il2cpp_rgctx_method(method->rgctx_data, 0));
		int16_t* L_1 = ___0_ptr;
		int32_t L_2 = V_0;
		uint32_t L_3 = sizeof(int16_t);
		int16_t L_4 = (*(int16_t*)((int16_t*)il2cpp_codegen_add((intptr_t)L_1, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_2), (int32_t)L_3)))));
		il2cpp_codegen_initobj((&V_1), sizeof(int16_t));
		int16_t L_5 = V_1;
		NullCheck(L_0);
		bool L_6;
		L_6 = VirtualFuncInvoker2< bool, int16_t, int16_t >::Invoke(8, L_0, L_4, L_5);
		if (!L_6)
		{
			goto IL_002b;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:214>
		int32_t L_7 = V_0;
		return L_7;
	}

IL_002b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:210>
		int32_t L_8 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_8, 1));
	}

IL_002f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:210>
		int32_t L_9 = V_0;
		int32_t L_10 = ___1_max;
		if ((((int32_t)L_9) < ((int32_t)L_10)))
		{
			goto IL_0004;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:217>
		int32_t L_11 = ___1_max;
		return L_11;
	}
}
// Method Definition Index: 66212
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStringLength_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m73215CC1A28F076B0D2472385756C7AF58CBA171_gshared (int8_t* ___0_ptr, int32_t ___1_max, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	int32_t V_0 = 0;
	int8_t V_1 = 0x0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:210>
		V_0 = 0;
		goto IL_002f;
	}

IL_0004:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:212>
		EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* L_0;
		L_0 = EqualityComparer_1_get_Default_m7F71AAC0046A3CB8C4CEB06A5A52A1269AF7023D_inline(il2cpp_rgctx_method(method->rgctx_data, 0));
		int8_t* L_1 = ___0_ptr;
		int32_t L_2 = V_0;
		uint32_t L_3 = sizeof(int8_t);
		int8_t L_4 = (*(int8_t*)((int8_t*)il2cpp_codegen_add((intptr_t)L_1, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_2), (int32_t)L_3)))));
		il2cpp_codegen_initobj((&V_1), sizeof(int8_t));
		int8_t L_5 = V_1;
		NullCheck(L_0);
		bool L_6;
		L_6 = VirtualFuncInvoker2< bool, int8_t, int8_t >::Invoke(8, L_0, L_4, L_5);
		if (!L_6)
		{
			goto IL_002b;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:214>
		int32_t L_7 = V_0;
		return L_7;
	}

IL_002b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:210>
		int32_t L_8 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_8, 1));
	}

IL_002f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:210>
		int32_t L_9 = V_0;
		int32_t L_10 = ___1_max;
		if ((((int32_t)L_9) < ((int32_t)L_10)))
		{
			goto IL_0004;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:217>
		int32_t L_11 = ___1_max;
		return L_11;
	}
}
// Method Definition Index: 66212
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStringLength_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m000E8D7B908376D69E48EACF3E6811C4DEE7A05D_gshared (uint16_t* ___0_ptr, int32_t ___1_max, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	int32_t V_0 = 0;
	uint16_t V_1 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:210>
		V_0 = 0;
		goto IL_002f;
	}

IL_0004:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:212>
		EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* L_0;
		L_0 = EqualityComparer_1_get_Default_m80EE5C179E01BB38904781592AC72F8137541D7E_inline(il2cpp_rgctx_method(method->rgctx_data, 0));
		uint16_t* L_1 = ___0_ptr;
		int32_t L_2 = V_0;
		uint32_t L_3 = sizeof(uint16_t);
		uint16_t L_4 = (*(uint16_t*)((uint16_t*)il2cpp_codegen_add((intptr_t)L_1, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_2), (int32_t)L_3)))));
		il2cpp_codegen_initobj((&V_1), sizeof(uint16_t));
		uint16_t L_5 = V_1;
		NullCheck(L_0);
		bool L_6;
		L_6 = VirtualFuncInvoker2< bool, uint16_t, uint16_t >::Invoke(8, L_0, L_4, L_5);
		if (!L_6)
		{
			goto IL_002b;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:214>
		int32_t L_7 = V_0;
		return L_7;
	}

IL_002b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:210>
		int32_t L_8 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_8, 1));
	}

IL_002f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:210>
		int32_t L_9 = V_0;
		int32_t L_10 = ___1_max;
		if ((((int32_t)L_9) < ((int32_t)L_10)))
		{
			goto IL_0004;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:217>
		int32_t L_11 = ___1_max;
		return L_11;
	}
}
// Method Definition Index: 66212
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStringLength_TisIl2CppFullySharedGenericStruct_m764CDB4D47CB1C77EAA40D60D44F53C4E97CD8D6_gshared (Il2CppFullySharedGenericStruct* ___0_ptr, int32_t ___1_max, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t2125B686AA2A4D4755B95692CBE3C48B69824C64 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 4));
	const Il2CppFullySharedGenericStruct L_4 = alloca(SizeOf_T_t2125B686AA2A4D4755B95692CBE3C48B69824C64);
	const Il2CppFullySharedGenericStruct L_5 = alloca(SizeOf_T_t2125B686AA2A4D4755B95692CBE3C48B69824C64);
	int32_t V_0 = 0;
	Il2CppFullySharedGenericStruct V_1 = alloca(SizeOf_T_t2125B686AA2A4D4755B95692CBE3C48B69824C64);
	memset(V_1, 0, SizeOf_T_t2125B686AA2A4D4755B95692CBE3C48B69824C64);
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:210>
		V_0 = 0;
		goto IL_002f;
	}

IL_0004:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:212>
		EqualityComparer_1_t458C8DC3748A89A213F4738B57D3742C4896ABE9* L_0;
		L_0 = ((  EqualityComparer_1_t458C8DC3748A89A213F4738B57D3742C4896ABE9* (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		Il2CppFullySharedGenericStruct* L_1 = ___0_ptr;
		int32_t L_2 = V_0;
		uint32_t L_3 = SizeOf_T_t2125B686AA2A4D4755B95692CBE3C48B69824C64;
		il2cpp_codegen_memcpy(L_4, ((Il2CppFullySharedGenericStruct*)il2cpp_codegen_add((intptr_t)L_1, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_2), (int32_t)L_3)))), SizeOf_T_t2125B686AA2A4D4755B95692CBE3C48B69824C64);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericStruct*)V_1, SizeOf_T_t2125B686AA2A4D4755B95692CBE3C48B69824C64);
		il2cpp_codegen_memcpy(L_5, V_1, SizeOf_T_t2125B686AA2A4D4755B95692CBE3C48B69824C64);
		NullCheck(L_0);
		bool L_6;
		L_6 = VirtualFuncInvoker2Invoker< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(8, L_0, L_4, L_5);
		if (!L_6)
		{
			goto IL_002b;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:214>
		int32_t L_7 = V_0;
		return L_7;
	}

IL_002b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:210>
		int32_t L_8 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_8, 1));
	}

IL_002f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:210>
		int32_t L_9 = V_0;
		int32_t L_10 = ___1_max;
		if ((((int32_t)L_9) < ((int32_t)L_10)))
		{
			goto IL_0004;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:217>
		int32_t L_11 = ___1_max;
		return L_11;
	}
}
// Method Definition Index: 66208
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_ComputeStrmOutput_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1CC4D51DF3F513318DCC288B066D0018EAF9C235_gshared (int32_t ___0_len, int32_t ___1_imm8, uint8_t ___2_allOnesT, int32_t ___3_intRes2, const RuntimeMethod* method) 
{
	v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 V_0;
	memset((&V_0), 0, sizeof(V_0));
	uint8_t* V_1 = NULL;
	int32_t V_2 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:141>
		il2cpp_codegen_initobj((&V_0), sizeof(v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61));
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:142>
		int32_t L_0 = ___1_imm8;
		if (!((int32_t)(L_0&((int32_t)64))))
		{
			goto IL_0053;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:145>
		uint8_t* L_1 = (uint8_t*)(&(&V_0)->___Byte0);
		V_1 = (uint8_t*)((uintptr_t)L_1);
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:146>
		V_2 = 0;
		goto IL_004d;
	}

IL_001b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:148>
		int32_t L_2 = ___3_intRes2;
		int32_t L_3 = V_2;
		if (!((int32_t)(L_2&((int32_t)(1<<((int32_t)(L_3&((int32_t)31))))))))
		{
			goto IL_0038;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:150>
		uint8_t* L_4 = V_1;
		int32_t L_5 = V_2;
		uint32_t L_6 = sizeof(uint8_t);
		uint8_t L_7 = ___2_allOnesT;
		*(uint8_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_4, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_5), (int32_t)L_6)))) = L_7;
		goto IL_0049;
	}

IL_0038:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:154>
		uint8_t* L_8 = V_1;
		int32_t L_9 = V_2;
		uint32_t L_10 = sizeof(uint8_t);
		il2cpp_codegen_initobj(((uint8_t*)il2cpp_codegen_add((intptr_t)L_8, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_9), (int32_t)L_10)))), sizeof(uint8_t));
	}

IL_0049:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:146>
		int32_t L_11 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_004d:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:146>
		int32_t L_12 = V_2;
		int32_t L_13 = ___0_len;
		if ((((int32_t)L_12) < ((int32_t)L_13)))
		{
			goto IL_001b;
		}
	}
	{
		goto IL_005b;
	}

IL_0053:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:161>
		int32_t L_14 = ___3_intRes2;
		(&V_0)->___SInt0 = L_14;
	}

IL_005b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:164>
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_15 = V_0;
		return L_15;
	}
}
// Method Definition Index: 66208
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_ComputeStrmOutput_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_mE92FFA321425E5808CD20616DC308BA7B36886E8_gshared (int32_t ___0_len, int32_t ___1_imm8, int16_t ___2_allOnesT, int32_t ___3_intRes2, const RuntimeMethod* method) 
{
	v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 V_0;
	memset((&V_0), 0, sizeof(V_0));
	int16_t* V_1 = NULL;
	int32_t V_2 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:141>
		il2cpp_codegen_initobj((&V_0), sizeof(v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61));
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:142>
		int32_t L_0 = ___1_imm8;
		if (!((int32_t)(L_0&((int32_t)64))))
		{
			goto IL_0053;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:145>
		uint8_t* L_1 = (uint8_t*)(&(&V_0)->___Byte0);
		V_1 = (int16_t*)((uintptr_t)L_1);
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:146>
		V_2 = 0;
		goto IL_004d;
	}

IL_001b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:148>
		int32_t L_2 = ___3_intRes2;
		int32_t L_3 = V_2;
		if (!((int32_t)(L_2&((int32_t)(1<<((int32_t)(L_3&((int32_t)31))))))))
		{
			goto IL_0038;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:150>
		int16_t* L_4 = V_1;
		int32_t L_5 = V_2;
		uint32_t L_6 = sizeof(int16_t);
		int16_t L_7 = ___2_allOnesT;
		*(int16_t*)((int16_t*)il2cpp_codegen_add((intptr_t)L_4, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_5), (int32_t)L_6)))) = L_7;
		goto IL_0049;
	}

IL_0038:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:154>
		int16_t* L_8 = V_1;
		int32_t L_9 = V_2;
		uint32_t L_10 = sizeof(int16_t);
		il2cpp_codegen_initobj(((int16_t*)il2cpp_codegen_add((intptr_t)L_8, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_9), (int32_t)L_10)))), sizeof(int16_t));
	}

IL_0049:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:146>
		int32_t L_11 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_004d:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:146>
		int32_t L_12 = V_2;
		int32_t L_13 = ___0_len;
		if ((((int32_t)L_12) < ((int32_t)L_13)))
		{
			goto IL_001b;
		}
	}
	{
		goto IL_005b;
	}

IL_0053:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:161>
		int32_t L_14 = ___3_intRes2;
		(&V_0)->___SInt0 = L_14;
	}

IL_005b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:164>
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_15 = V_0;
		return L_15;
	}
}
// Method Definition Index: 66208
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_ComputeStrmOutput_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m5EFDDE5126FDB6BF9F9ED55B39751B517522C455_gshared (int32_t ___0_len, int32_t ___1_imm8, int8_t ___2_allOnesT, int32_t ___3_intRes2, const RuntimeMethod* method) 
{
	v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 V_0;
	memset((&V_0), 0, sizeof(V_0));
	int8_t* V_1 = NULL;
	int32_t V_2 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:141>
		il2cpp_codegen_initobj((&V_0), sizeof(v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61));
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:142>
		int32_t L_0 = ___1_imm8;
		if (!((int32_t)(L_0&((int32_t)64))))
		{
			goto IL_0053;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:145>
		uint8_t* L_1 = (uint8_t*)(&(&V_0)->___Byte0);
		V_1 = (int8_t*)((uintptr_t)L_1);
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:146>
		V_2 = 0;
		goto IL_004d;
	}

IL_001b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:148>
		int32_t L_2 = ___3_intRes2;
		int32_t L_3 = V_2;
		if (!((int32_t)(L_2&((int32_t)(1<<((int32_t)(L_3&((int32_t)31))))))))
		{
			goto IL_0038;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:150>
		int8_t* L_4 = V_1;
		int32_t L_5 = V_2;
		uint32_t L_6 = sizeof(int8_t);
		int8_t L_7 = ___2_allOnesT;
		*(int8_t*)((int8_t*)il2cpp_codegen_add((intptr_t)L_4, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_5), (int32_t)L_6)))) = L_7;
		goto IL_0049;
	}

IL_0038:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:154>
		int8_t* L_8 = V_1;
		int32_t L_9 = V_2;
		uint32_t L_10 = sizeof(int8_t);
		il2cpp_codegen_initobj(((int8_t*)il2cpp_codegen_add((intptr_t)L_8, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_9), (int32_t)L_10)))), sizeof(int8_t));
	}

IL_0049:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:146>
		int32_t L_11 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_004d:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:146>
		int32_t L_12 = V_2;
		int32_t L_13 = ___0_len;
		if ((((int32_t)L_12) < ((int32_t)L_13)))
		{
			goto IL_001b;
		}
	}
	{
		goto IL_005b;
	}

IL_0053:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:161>
		int32_t L_14 = ___3_intRes2;
		(&V_0)->___SInt0 = L_14;
	}

IL_005b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:164>
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_15 = V_0;
		return L_15;
	}
}
// Method Definition Index: 66208
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_ComputeStrmOutput_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_mD44F4B084A230ACD38B4FCF13923F8986AFF0AB1_gshared (int32_t ___0_len, int32_t ___1_imm8, uint16_t ___2_allOnesT, int32_t ___3_intRes2, const RuntimeMethod* method) 
{
	v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 V_0;
	memset((&V_0), 0, sizeof(V_0));
	uint16_t* V_1 = NULL;
	int32_t V_2 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:141>
		il2cpp_codegen_initobj((&V_0), sizeof(v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61));
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:142>
		int32_t L_0 = ___1_imm8;
		if (!((int32_t)(L_0&((int32_t)64))))
		{
			goto IL_0053;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:145>
		uint8_t* L_1 = (uint8_t*)(&(&V_0)->___Byte0);
		V_1 = (uint16_t*)((uintptr_t)L_1);
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:146>
		V_2 = 0;
		goto IL_004d;
	}

IL_001b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:148>
		int32_t L_2 = ___3_intRes2;
		int32_t L_3 = V_2;
		if (!((int32_t)(L_2&((int32_t)(1<<((int32_t)(L_3&((int32_t)31))))))))
		{
			goto IL_0038;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:150>
		uint16_t* L_4 = V_1;
		int32_t L_5 = V_2;
		uint32_t L_6 = sizeof(uint16_t);
		uint16_t L_7 = ___2_allOnesT;
		*(uint16_t*)((uint16_t*)il2cpp_codegen_add((intptr_t)L_4, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_5), (int32_t)L_6)))) = L_7;
		goto IL_0049;
	}

IL_0038:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:154>
		uint16_t* L_8 = V_1;
		int32_t L_9 = V_2;
		uint32_t L_10 = sizeof(uint16_t);
		il2cpp_codegen_initobj(((uint16_t*)il2cpp_codegen_add((intptr_t)L_8, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_9), (int32_t)L_10)))), sizeof(uint16_t));
	}

IL_0049:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:146>
		int32_t L_11 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_004d:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:146>
		int32_t L_12 = V_2;
		int32_t L_13 = ___0_len;
		if ((((int32_t)L_12) < ((int32_t)L_13)))
		{
			goto IL_001b;
		}
	}
	{
		goto IL_005b;
	}

IL_0053:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:161>
		int32_t L_14 = ___3_intRes2;
		(&V_0)->___SInt0 = L_14;
	}

IL_005b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:164>
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_15 = V_0;
		return L_15;
	}
}
// Method Definition Index: 66208
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_ComputeStrmOutput_TisIl2CppFullySharedGenericStruct_m64ADE71FB4B90FEC60799387186E249935DE041C_gshared (int32_t ___0_len, int32_t ___1_imm8, Il2CppFullySharedGenericStruct ___2_allOnesT, int32_t ___3_intRes2, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t4AB7E7218B07206B6D97D6E91CAC0F37510C246B = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 0));
	const Il2CppFullySharedGenericStruct L_7 = alloca(SizeOf_T_t4AB7E7218B07206B6D97D6E91CAC0F37510C246B);
	v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 V_0;
	memset((&V_0), 0, sizeof(V_0));
	Il2CppFullySharedGenericStruct* V_1 = NULL;
	int32_t V_2 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:141>
		il2cpp_codegen_initobj((&V_0), sizeof(v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61));
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:142>
		int32_t L_0 = ___1_imm8;
		if (!((int32_t)(L_0&((int32_t)64))))
		{
			goto IL_0053;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:145>
		uint8_t* L_1 = (uint8_t*)(&(&V_0)->___Byte0);
		V_1 = (Il2CppFullySharedGenericStruct*)((uintptr_t)L_1);
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:146>
		V_2 = 0;
		goto IL_004d;
	}

IL_001b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:148>
		int32_t L_2 = ___3_intRes2;
		int32_t L_3 = V_2;
		if (!((int32_t)(L_2&((int32_t)(1<<((int32_t)(L_3&((int32_t)31))))))))
		{
			goto IL_0038;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:150>
		Il2CppFullySharedGenericStruct* L_4 = V_1;
		int32_t L_5 = V_2;
		uint32_t L_6 = SizeOf_T_t4AB7E7218B07206B6D97D6E91CAC0F37510C246B;
		il2cpp_codegen_memcpy(L_7, ___2_allOnesT, SizeOf_T_t4AB7E7218B07206B6D97D6E91CAC0F37510C246B);
		il2cpp_codegen_memcpy((Il2CppFullySharedGenericStruct*)((Il2CppFullySharedGenericStruct*)il2cpp_codegen_add((intptr_t)L_4, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_5), (int32_t)L_6)))), L_7, SizeOf_T_t4AB7E7218B07206B6D97D6E91CAC0F37510C246B);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(method->rgctx_data, 0), (void**)(Il2CppFullySharedGenericStruct*)((Il2CppFullySharedGenericStruct*)il2cpp_codegen_add((intptr_t)L_4, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_5), (int32_t)L_6)))), (void*)L_7);
		goto IL_0049;
	}

IL_0038:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:154>
		Il2CppFullySharedGenericStruct* L_8 = V_1;
		int32_t L_9 = V_2;
		uint32_t L_10 = SizeOf_T_t4AB7E7218B07206B6D97D6E91CAC0F37510C246B;
		il2cpp_codegen_initobj(((Il2CppFullySharedGenericStruct*)il2cpp_codegen_add((intptr_t)L_8, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_9), (int32_t)L_10)))), SizeOf_T_t4AB7E7218B07206B6D97D6E91CAC0F37510C246B);
	}

IL_0049:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:146>
		int32_t L_11 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_004d:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:146>
		int32_t L_12 = V_2;
		int32_t L_13 = ___0_len;
		if ((((int32_t)L_12) < ((int32_t)L_13)))
		{
			goto IL_001b;
		}
	}
	{
		goto IL_005b;
	}

IL_0053:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:161>
		int32_t L_14 = ___3_intRes2;
		(&V_0)->___SInt0 = L_14;
	}

IL_005b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:164>
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_15 = V_0;
		return L_15;
	}
}
// Method Definition Index: 66210
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_cmpestri_emulation_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mD4107C2F2DB7508841779CE414BD21B61FA3183F_gshared (uint8_t* ___0_a, int32_t ___1_alen, uint8_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, uint8_t ___7_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:176>
		uint8_t* L_0 = ___0_a;
		int32_t L_1 = ___1_alen;
		uint8_t* L_2 = ___2_b;
		int32_t L_3 = ___3_blen;
		int32_t L_4 = ___4_len;
		int32_t L_5 = ___5_imm8;
		int32_t L_6 = ___6_allOnes;
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_7;
		L_7 = Sse4_2_ComputeStrCmpIntRes2_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m5D9BE946098FA4C7FC8CC23DEE63A0877E8D6C8B(L_0, L_1, L_2, L_3, L_4, L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_7;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:178>
		int32_t L_8 = ___4_len;
		int32_t L_9 = ___5_imm8;
		int32_t L_10 = V_0;
		int32_t L_11;
		L_11 = Sse4_2_ComputeStriOutput_mC9EFEB2A2B9B95760CEE913DF4EF7F57BE662123(L_8, L_9, L_10, NULL);
		return L_11;
	}
}
// Method Definition Index: 66210
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_cmpestri_emulation_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m797C4B561EC2527267C18CF422EBBD9FCDD306EF_gshared (int16_t* ___0_a, int32_t ___1_alen, int16_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, int16_t ___7_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:176>
		int16_t* L_0 = ___0_a;
		int32_t L_1 = ___1_alen;
		int16_t* L_2 = ___2_b;
		int32_t L_3 = ___3_blen;
		int32_t L_4 = ___4_len;
		int32_t L_5 = ___5_imm8;
		int32_t L_6 = ___6_allOnes;
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_7;
		L_7 = Sse4_2_ComputeStrCmpIntRes2_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_mB3F9377B1A57D35D5514DEF77B3D9279A8622960(L_0, L_1, L_2, L_3, L_4, L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_7;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:178>
		int32_t L_8 = ___4_len;
		int32_t L_9 = ___5_imm8;
		int32_t L_10 = V_0;
		int32_t L_11;
		L_11 = Sse4_2_ComputeStriOutput_mC9EFEB2A2B9B95760CEE913DF4EF7F57BE662123(L_8, L_9, L_10, NULL);
		return L_11;
	}
}
// Method Definition Index: 66210
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_cmpestri_emulation_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m8934296ABE51C76314606C484F93554C529BD77A_gshared (int8_t* ___0_a, int32_t ___1_alen, int8_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, int8_t ___7_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:176>
		int8_t* L_0 = ___0_a;
		int32_t L_1 = ___1_alen;
		int8_t* L_2 = ___2_b;
		int32_t L_3 = ___3_blen;
		int32_t L_4 = ___4_len;
		int32_t L_5 = ___5_imm8;
		int32_t L_6 = ___6_allOnes;
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_7;
		L_7 = Sse4_2_ComputeStrCmpIntRes2_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_mA23FD3A0C3B4448E4721DA31DA7B4B93A636A3FD(L_0, L_1, L_2, L_3, L_4, L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_7;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:178>
		int32_t L_8 = ___4_len;
		int32_t L_9 = ___5_imm8;
		int32_t L_10 = V_0;
		int32_t L_11;
		L_11 = Sse4_2_ComputeStriOutput_mC9EFEB2A2B9B95760CEE913DF4EF7F57BE662123(L_8, L_9, L_10, NULL);
		return L_11;
	}
}
// Method Definition Index: 66210
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_cmpestri_emulation_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m6A20624B95FD608D46A450719A26FC173F4C0780_gshared (uint16_t* ___0_a, int32_t ___1_alen, uint16_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, uint16_t ___7_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:176>
		uint16_t* L_0 = ___0_a;
		int32_t L_1 = ___1_alen;
		uint16_t* L_2 = ___2_b;
		int32_t L_3 = ___3_blen;
		int32_t L_4 = ___4_len;
		int32_t L_5 = ___5_imm8;
		int32_t L_6 = ___6_allOnes;
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_7;
		L_7 = Sse4_2_ComputeStrCmpIntRes2_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m331D979D640CF9DF04C505875F9FB702E217B2AB(L_0, L_1, L_2, L_3, L_4, L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_7;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:178>
		int32_t L_8 = ___4_len;
		int32_t L_9 = ___5_imm8;
		int32_t L_10 = V_0;
		int32_t L_11;
		L_11 = Sse4_2_ComputeStriOutput_mC9EFEB2A2B9B95760CEE913DF4EF7F57BE662123(L_8, L_9, L_10, NULL);
		return L_11;
	}
}
// Method Definition Index: 66210
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_cmpestri_emulation_TisIl2CppFullySharedGenericStruct_m92A1CC07F00E8D1EFF164A7AAA2CEF3A90BC8071_gshared (Il2CppFullySharedGenericStruct* ___0_a, int32_t ___1_alen, Il2CppFullySharedGenericStruct* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, Il2CppFullySharedGenericStruct ___7_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:176>
		Il2CppFullySharedGenericStruct* L_0 = ___0_a;
		int32_t L_1 = ___1_alen;
		Il2CppFullySharedGenericStruct* L_2 = ___2_b;
		int32_t L_3 = ___3_blen;
		int32_t L_4 = ___4_len;
		int32_t L_5 = ___5_imm8;
		int32_t L_6 = ___6_allOnes;
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_7;
		L_7 = ((  int32_t (*) (Il2CppFullySharedGenericStruct*, int32_t, Il2CppFullySharedGenericStruct*, int32_t, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(L_0, L_1, L_2, L_3, L_4, L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_7;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:178>
		int32_t L_8 = ___4_len;
		int32_t L_9 = ___5_imm8;
		int32_t L_10 = V_0;
		int32_t L_11;
		L_11 = Sse4_2_ComputeStriOutput_mC9EFEB2A2B9B95760CEE913DF4EF7F57BE662123(L_8, L_9, L_10, NULL);
		return L_11;
	}
}
// Method Definition Index: 66207
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_cmpestrm_emulation_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m179C750FBD381FF2897A9140CF7C2661939C7E71_gshared (uint8_t* ___0_a, int32_t ___1_alen, uint8_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, uint8_t ___7_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:133>
		uint8_t* L_0 = ___0_a;
		int32_t L_1 = ___1_alen;
		uint8_t* L_2 = ___2_b;
		int32_t L_3 = ___3_blen;
		int32_t L_4 = ___4_len;
		int32_t L_5 = ___5_imm8;
		int32_t L_6 = ___6_allOnes;
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_7;
		L_7 = Sse4_2_ComputeStrCmpIntRes2_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m5D9BE946098FA4C7FC8CC23DEE63A0877E8D6C8B(L_0, L_1, L_2, L_3, L_4, L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_7;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:135>
		int32_t L_8 = ___4_len;
		int32_t L_9 = ___5_imm8;
		uint8_t L_10 = ___7_allOnesT;
		int32_t L_11 = V_0;
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_12;
		L_12 = Sse4_2_ComputeStrmOutput_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1CC4D51DF3F513318DCC288B066D0018EAF9C235(L_8, L_9, L_10, L_11, il2cpp_rgctx_method(method->rgctx_data, 3));
		return L_12;
	}
}
// Method Definition Index: 66207
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_cmpestrm_emulation_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m9F860C6A223CB8744EB0C859B49E573C300C9F7B_gshared (int16_t* ___0_a, int32_t ___1_alen, int16_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, int16_t ___7_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:133>
		int16_t* L_0 = ___0_a;
		int32_t L_1 = ___1_alen;
		int16_t* L_2 = ___2_b;
		int32_t L_3 = ___3_blen;
		int32_t L_4 = ___4_len;
		int32_t L_5 = ___5_imm8;
		int32_t L_6 = ___6_allOnes;
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_7;
		L_7 = Sse4_2_ComputeStrCmpIntRes2_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_mB3F9377B1A57D35D5514DEF77B3D9279A8622960(L_0, L_1, L_2, L_3, L_4, L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_7;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:135>
		int32_t L_8 = ___4_len;
		int32_t L_9 = ___5_imm8;
		int16_t L_10 = ___7_allOnesT;
		int32_t L_11 = V_0;
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_12;
		L_12 = Sse4_2_ComputeStrmOutput_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_mE92FFA321425E5808CD20616DC308BA7B36886E8(L_8, L_9, L_10, L_11, il2cpp_rgctx_method(method->rgctx_data, 3));
		return L_12;
	}
}
// Method Definition Index: 66207
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_cmpestrm_emulation_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_mEC9DD6EE9C8D66BCFFABD5A19993FDA06444F20C_gshared (int8_t* ___0_a, int32_t ___1_alen, int8_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, int8_t ___7_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:133>
		int8_t* L_0 = ___0_a;
		int32_t L_1 = ___1_alen;
		int8_t* L_2 = ___2_b;
		int32_t L_3 = ___3_blen;
		int32_t L_4 = ___4_len;
		int32_t L_5 = ___5_imm8;
		int32_t L_6 = ___6_allOnes;
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_7;
		L_7 = Sse4_2_ComputeStrCmpIntRes2_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_mA23FD3A0C3B4448E4721DA31DA7B4B93A636A3FD(L_0, L_1, L_2, L_3, L_4, L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_7;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:135>
		int32_t L_8 = ___4_len;
		int32_t L_9 = ___5_imm8;
		int8_t L_10 = ___7_allOnesT;
		int32_t L_11 = V_0;
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_12;
		L_12 = Sse4_2_ComputeStrmOutput_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m5EFDDE5126FDB6BF9F9ED55B39751B517522C455(L_8, L_9, L_10, L_11, il2cpp_rgctx_method(method->rgctx_data, 3));
		return L_12;
	}
}
// Method Definition Index: 66207
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_cmpestrm_emulation_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m8784D19FC1B4BAC48D00E8623FE1872EFEFD3496_gshared (uint16_t* ___0_a, int32_t ___1_alen, uint16_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, uint16_t ___7_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:133>
		uint16_t* L_0 = ___0_a;
		int32_t L_1 = ___1_alen;
		uint16_t* L_2 = ___2_b;
		int32_t L_3 = ___3_blen;
		int32_t L_4 = ___4_len;
		int32_t L_5 = ___5_imm8;
		int32_t L_6 = ___6_allOnes;
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_7;
		L_7 = Sse4_2_ComputeStrCmpIntRes2_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m331D979D640CF9DF04C505875F9FB702E217B2AB(L_0, L_1, L_2, L_3, L_4, L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_7;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:135>
		int32_t L_8 = ___4_len;
		int32_t L_9 = ___5_imm8;
		uint16_t L_10 = ___7_allOnesT;
		int32_t L_11 = V_0;
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_12;
		L_12 = Sse4_2_ComputeStrmOutput_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_mD44F4B084A230ACD38B4FCF13923F8986AFF0AB1(L_8, L_9, L_10, L_11, il2cpp_rgctx_method(method->rgctx_data, 3));
		return L_12;
	}
}
// Method Definition Index: 66207
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_cmpestrm_emulation_TisIl2CppFullySharedGenericStruct_m81548202F0BF107992042F154D34BCB0C7366524_gshared (Il2CppFullySharedGenericStruct* ___0_a, int32_t ___1_alen, Il2CppFullySharedGenericStruct* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, Il2CppFullySharedGenericStruct ___7_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	const uint32_t SizeOf_T_t42FC5CD236BFE90D4A941BFCE621367A7EA03BDC = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 2));
	const Il2CppFullySharedGenericStruct L_10 = alloca(SizeOf_T_t42FC5CD236BFE90D4A941BFCE621367A7EA03BDC);
	int32_t V_0 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:133>
		Il2CppFullySharedGenericStruct* L_0 = ___0_a;
		int32_t L_1 = ___1_alen;
		Il2CppFullySharedGenericStruct* L_2 = ___2_b;
		int32_t L_3 = ___3_blen;
		int32_t L_4 = ___4_len;
		int32_t L_5 = ___5_imm8;
		int32_t L_6 = ___6_allOnes;
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_7;
		L_7 = ((  int32_t (*) (Il2CppFullySharedGenericStruct*, int32_t, Il2CppFullySharedGenericStruct*, int32_t, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(L_0, L_1, L_2, L_3, L_4, L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_7;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:135>
		int32_t L_8 = ___4_len;
		int32_t L_9 = ___5_imm8;
		il2cpp_codegen_memcpy(L_10, ___7_allOnesT, SizeOf_T_t42FC5CD236BFE90D4A941BFCE621367A7EA03BDC);
		int32_t L_11 = V_0;
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_12;
		L_12 = InvokerFuncInvoker4< v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61, int32_t, int32_t, Il2CppFullySharedGenericStruct, int32_t >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)), il2cpp_rgctx_method(method->rgctx_data, 3), NULL, L_8, L_9, L_10, L_11);
		return L_12;
	}
}
// Method Definition Index: 66209
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_cmpistri_emulation_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m2E6D2FDB31E3BFDFC30BDD2389A5A50C0F3286BB_gshared (uint8_t* ___0_a, uint8_t* ___1_b, int32_t ___2_len, int32_t ___3_imm8, int32_t ___4_allOnes, uint8_t ___5_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:169>
		uint8_t* L_0 = ___0_a;
		uint8_t* L_1 = ___0_a;
		int32_t L_2 = ___2_len;
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_3;
		L_3 = Sse4_2_ComputeStringLength_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mD30812062AA4852D166ABCDF3D79FDD1856F173A(L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		uint8_t* L_4 = ___1_b;
		uint8_t* L_5 = ___1_b;
		int32_t L_6 = ___2_len;
		int32_t L_7;
		L_7 = Sse4_2_ComputeStringLength_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mD30812062AA4852D166ABCDF3D79FDD1856F173A(L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_8 = ___2_len;
		int32_t L_9 = ___3_imm8;
		int32_t L_10 = ___4_allOnes;
		int32_t L_11;
		L_11 = Sse4_2_ComputeStrCmpIntRes2_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m5D9BE946098FA4C7FC8CC23DEE63A0877E8D6C8B(L_0, L_3, L_4, L_7, L_8, L_9, L_10, il2cpp_rgctx_method(method->rgctx_data, 2));
		V_0 = L_11;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:171>
		int32_t L_12 = ___2_len;
		int32_t L_13 = ___3_imm8;
		int32_t L_14 = V_0;
		int32_t L_15;
		L_15 = Sse4_2_ComputeStriOutput_mC9EFEB2A2B9B95760CEE913DF4EF7F57BE662123(L_12, L_13, L_14, NULL);
		return L_15;
	}
}
// Method Definition Index: 66209
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_cmpistri_emulation_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m4786E128EACDF39A8B13B696D31429E7C8D6EBF6_gshared (int16_t* ___0_a, int16_t* ___1_b, int32_t ___2_len, int32_t ___3_imm8, int32_t ___4_allOnes, int16_t ___5_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:169>
		int16_t* L_0 = ___0_a;
		int16_t* L_1 = ___0_a;
		int32_t L_2 = ___2_len;
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_3;
		L_3 = Sse4_2_ComputeStringLength_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m3EBC75C6F39A7B1A5F62D88877C87C9F3B5617A3(L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		int16_t* L_4 = ___1_b;
		int16_t* L_5 = ___1_b;
		int32_t L_6 = ___2_len;
		int32_t L_7;
		L_7 = Sse4_2_ComputeStringLength_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m3EBC75C6F39A7B1A5F62D88877C87C9F3B5617A3(L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_8 = ___2_len;
		int32_t L_9 = ___3_imm8;
		int32_t L_10 = ___4_allOnes;
		int32_t L_11;
		L_11 = Sse4_2_ComputeStrCmpIntRes2_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_mB3F9377B1A57D35D5514DEF77B3D9279A8622960(L_0, L_3, L_4, L_7, L_8, L_9, L_10, il2cpp_rgctx_method(method->rgctx_data, 2));
		V_0 = L_11;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:171>
		int32_t L_12 = ___2_len;
		int32_t L_13 = ___3_imm8;
		int32_t L_14 = V_0;
		int32_t L_15;
		L_15 = Sse4_2_ComputeStriOutput_mC9EFEB2A2B9B95760CEE913DF4EF7F57BE662123(L_12, L_13, L_14, NULL);
		return L_15;
	}
}
// Method Definition Index: 66209
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_cmpistri_emulation_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m12535D1A7206DB4C56C55B642E9F5F0B072810A3_gshared (int8_t* ___0_a, int8_t* ___1_b, int32_t ___2_len, int32_t ___3_imm8, int32_t ___4_allOnes, int8_t ___5_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:169>
		int8_t* L_0 = ___0_a;
		int8_t* L_1 = ___0_a;
		int32_t L_2 = ___2_len;
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_3;
		L_3 = Sse4_2_ComputeStringLength_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m73215CC1A28F076B0D2472385756C7AF58CBA171(L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		int8_t* L_4 = ___1_b;
		int8_t* L_5 = ___1_b;
		int32_t L_6 = ___2_len;
		int32_t L_7;
		L_7 = Sse4_2_ComputeStringLength_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m73215CC1A28F076B0D2472385756C7AF58CBA171(L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_8 = ___2_len;
		int32_t L_9 = ___3_imm8;
		int32_t L_10 = ___4_allOnes;
		int32_t L_11;
		L_11 = Sse4_2_ComputeStrCmpIntRes2_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_mA23FD3A0C3B4448E4721DA31DA7B4B93A636A3FD(L_0, L_3, L_4, L_7, L_8, L_9, L_10, il2cpp_rgctx_method(method->rgctx_data, 2));
		V_0 = L_11;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:171>
		int32_t L_12 = ___2_len;
		int32_t L_13 = ___3_imm8;
		int32_t L_14 = V_0;
		int32_t L_15;
		L_15 = Sse4_2_ComputeStriOutput_mC9EFEB2A2B9B95760CEE913DF4EF7F57BE662123(L_12, L_13, L_14, NULL);
		return L_15;
	}
}
// Method Definition Index: 66209
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_cmpistri_emulation_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m875686166B80F44B2A7B5837256932C7A6560E7D_gshared (uint16_t* ___0_a, uint16_t* ___1_b, int32_t ___2_len, int32_t ___3_imm8, int32_t ___4_allOnes, uint16_t ___5_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:169>
		uint16_t* L_0 = ___0_a;
		uint16_t* L_1 = ___0_a;
		int32_t L_2 = ___2_len;
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_3;
		L_3 = Sse4_2_ComputeStringLength_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m000E8D7B908376D69E48EACF3E6811C4DEE7A05D(L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		uint16_t* L_4 = ___1_b;
		uint16_t* L_5 = ___1_b;
		int32_t L_6 = ___2_len;
		int32_t L_7;
		L_7 = Sse4_2_ComputeStringLength_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m000E8D7B908376D69E48EACF3E6811C4DEE7A05D(L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_8 = ___2_len;
		int32_t L_9 = ___3_imm8;
		int32_t L_10 = ___4_allOnes;
		int32_t L_11;
		L_11 = Sse4_2_ComputeStrCmpIntRes2_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m331D979D640CF9DF04C505875F9FB702E217B2AB(L_0, L_3, L_4, L_7, L_8, L_9, L_10, il2cpp_rgctx_method(method->rgctx_data, 2));
		V_0 = L_11;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:171>
		int32_t L_12 = ___2_len;
		int32_t L_13 = ___3_imm8;
		int32_t L_14 = V_0;
		int32_t L_15;
		L_15 = Sse4_2_ComputeStriOutput_mC9EFEB2A2B9B95760CEE913DF4EF7F57BE662123(L_12, L_13, L_14, NULL);
		return L_15;
	}
}
// Method Definition Index: 66209
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_cmpistri_emulation_TisIl2CppFullySharedGenericStruct_m0723D40FF7E3DA850D8AF6948CB6C949F855583D_gshared (Il2CppFullySharedGenericStruct* ___0_a, Il2CppFullySharedGenericStruct* ___1_b, int32_t ___2_len, int32_t ___3_imm8, int32_t ___4_allOnes, Il2CppFullySharedGenericStruct ___5_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:169>
		Il2CppFullySharedGenericStruct* L_0 = ___0_a;
		Il2CppFullySharedGenericStruct* L_1 = ___0_a;
		int32_t L_2 = ___2_len;
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_3;
		L_3 = ((  int32_t (*) (Il2CppFullySharedGenericStruct*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		Il2CppFullySharedGenericStruct* L_4 = ___1_b;
		Il2CppFullySharedGenericStruct* L_5 = ___1_b;
		int32_t L_6 = ___2_len;
		int32_t L_7;
		L_7 = ((  int32_t (*) (Il2CppFullySharedGenericStruct*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_8 = ___2_len;
		int32_t L_9 = ___3_imm8;
		int32_t L_10 = ___4_allOnes;
		int32_t L_11;
		L_11 = ((  int32_t (*) (Il2CppFullySharedGenericStruct*, int32_t, Il2CppFullySharedGenericStruct*, int32_t, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(L_0, L_3, L_4, L_7, L_8, L_9, L_10, il2cpp_rgctx_method(method->rgctx_data, 2));
		V_0 = L_11;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:171>
		int32_t L_12 = ___2_len;
		int32_t L_13 = ___3_imm8;
		int32_t L_14 = V_0;
		int32_t L_15;
		L_15 = Sse4_2_ComputeStriOutput_mC9EFEB2A2B9B95760CEE913DF4EF7F57BE662123(L_12, L_13, L_14, NULL);
		return L_15;
	}
}
// Method Definition Index: 66206
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_cmpistrm_emulation_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1E1CCF579BEBAD09719E3B27BCAB1A607CED8C89_gshared (uint8_t* ___0_a, uint8_t* ___1_b, int32_t ___2_len, int32_t ___3_imm8, int32_t ___4_allOnes, uint8_t ___5_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:126>
		uint8_t* L_0 = ___0_a;
		uint8_t* L_1 = ___0_a;
		int32_t L_2 = ___2_len;
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_3;
		L_3 = Sse4_2_ComputeStringLength_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mD30812062AA4852D166ABCDF3D79FDD1856F173A(L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		uint8_t* L_4 = ___1_b;
		uint8_t* L_5 = ___1_b;
		int32_t L_6 = ___2_len;
		int32_t L_7;
		L_7 = Sse4_2_ComputeStringLength_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mD30812062AA4852D166ABCDF3D79FDD1856F173A(L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_8 = ___2_len;
		int32_t L_9 = ___3_imm8;
		int32_t L_10 = ___4_allOnes;
		int32_t L_11;
		L_11 = Sse4_2_ComputeStrCmpIntRes2_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m5D9BE946098FA4C7FC8CC23DEE63A0877E8D6C8B(L_0, L_3, L_4, L_7, L_8, L_9, L_10, il2cpp_rgctx_method(method->rgctx_data, 2));
		V_0 = L_11;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:128>
		int32_t L_12 = ___2_len;
		int32_t L_13 = ___3_imm8;
		uint8_t L_14 = ___5_allOnesT;
		int32_t L_15 = V_0;
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_16;
		L_16 = Sse4_2_ComputeStrmOutput_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1CC4D51DF3F513318DCC288B066D0018EAF9C235(L_12, L_13, L_14, L_15, il2cpp_rgctx_method(method->rgctx_data, 4));
		return L_16;
	}
}
// Method Definition Index: 66206
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_cmpistrm_emulation_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m31A82E20D7EB7CDFCDF7EEA3E75BA4F38F8501D4_gshared (int16_t* ___0_a, int16_t* ___1_b, int32_t ___2_len, int32_t ___3_imm8, int32_t ___4_allOnes, int16_t ___5_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:126>
		int16_t* L_0 = ___0_a;
		int16_t* L_1 = ___0_a;
		int32_t L_2 = ___2_len;
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_3;
		L_3 = Sse4_2_ComputeStringLength_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m3EBC75C6F39A7B1A5F62D88877C87C9F3B5617A3(L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		int16_t* L_4 = ___1_b;
		int16_t* L_5 = ___1_b;
		int32_t L_6 = ___2_len;
		int32_t L_7;
		L_7 = Sse4_2_ComputeStringLength_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m3EBC75C6F39A7B1A5F62D88877C87C9F3B5617A3(L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_8 = ___2_len;
		int32_t L_9 = ___3_imm8;
		int32_t L_10 = ___4_allOnes;
		int32_t L_11;
		L_11 = Sse4_2_ComputeStrCmpIntRes2_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_mB3F9377B1A57D35D5514DEF77B3D9279A8622960(L_0, L_3, L_4, L_7, L_8, L_9, L_10, il2cpp_rgctx_method(method->rgctx_data, 2));
		V_0 = L_11;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:128>
		int32_t L_12 = ___2_len;
		int32_t L_13 = ___3_imm8;
		int16_t L_14 = ___5_allOnesT;
		int32_t L_15 = V_0;
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_16;
		L_16 = Sse4_2_ComputeStrmOutput_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_mE92FFA321425E5808CD20616DC308BA7B36886E8(L_12, L_13, L_14, L_15, il2cpp_rgctx_method(method->rgctx_data, 4));
		return L_16;
	}
}
// Method Definition Index: 66206
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_cmpistrm_emulation_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_mEA9E446133608807E4CF1C806055621BECFD93CF_gshared (int8_t* ___0_a, int8_t* ___1_b, int32_t ___2_len, int32_t ___3_imm8, int32_t ___4_allOnes, int8_t ___5_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:126>
		int8_t* L_0 = ___0_a;
		int8_t* L_1 = ___0_a;
		int32_t L_2 = ___2_len;
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_3;
		L_3 = Sse4_2_ComputeStringLength_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m73215CC1A28F076B0D2472385756C7AF58CBA171(L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		int8_t* L_4 = ___1_b;
		int8_t* L_5 = ___1_b;
		int32_t L_6 = ___2_len;
		int32_t L_7;
		L_7 = Sse4_2_ComputeStringLength_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m73215CC1A28F076B0D2472385756C7AF58CBA171(L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_8 = ___2_len;
		int32_t L_9 = ___3_imm8;
		int32_t L_10 = ___4_allOnes;
		int32_t L_11;
		L_11 = Sse4_2_ComputeStrCmpIntRes2_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_mA23FD3A0C3B4448E4721DA31DA7B4B93A636A3FD(L_0, L_3, L_4, L_7, L_8, L_9, L_10, il2cpp_rgctx_method(method->rgctx_data, 2));
		V_0 = L_11;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:128>
		int32_t L_12 = ___2_len;
		int32_t L_13 = ___3_imm8;
		int8_t L_14 = ___5_allOnesT;
		int32_t L_15 = V_0;
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_16;
		L_16 = Sse4_2_ComputeStrmOutput_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m5EFDDE5126FDB6BF9F9ED55B39751B517522C455(L_12, L_13, L_14, L_15, il2cpp_rgctx_method(method->rgctx_data, 4));
		return L_16;
	}
}
// Method Definition Index: 66206
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_cmpistrm_emulation_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m084B5A607615E44BC1926F6FF9CF11754A074B06_gshared (uint16_t* ___0_a, uint16_t* ___1_b, int32_t ___2_len, int32_t ___3_imm8, int32_t ___4_allOnes, uint16_t ___5_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:126>
		uint16_t* L_0 = ___0_a;
		uint16_t* L_1 = ___0_a;
		int32_t L_2 = ___2_len;
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_3;
		L_3 = Sse4_2_ComputeStringLength_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m000E8D7B908376D69E48EACF3E6811C4DEE7A05D(L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		uint16_t* L_4 = ___1_b;
		uint16_t* L_5 = ___1_b;
		int32_t L_6 = ___2_len;
		int32_t L_7;
		L_7 = Sse4_2_ComputeStringLength_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m000E8D7B908376D69E48EACF3E6811C4DEE7A05D(L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_8 = ___2_len;
		int32_t L_9 = ___3_imm8;
		int32_t L_10 = ___4_allOnes;
		int32_t L_11;
		L_11 = Sse4_2_ComputeStrCmpIntRes2_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m331D979D640CF9DF04C505875F9FB702E217B2AB(L_0, L_3, L_4, L_7, L_8, L_9, L_10, il2cpp_rgctx_method(method->rgctx_data, 2));
		V_0 = L_11;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:128>
		int32_t L_12 = ___2_len;
		int32_t L_13 = ___3_imm8;
		uint16_t L_14 = ___5_allOnesT;
		int32_t L_15 = V_0;
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_16;
		L_16 = Sse4_2_ComputeStrmOutput_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_mD44F4B084A230ACD38B4FCF13923F8986AFF0AB1(L_12, L_13, L_14, L_15, il2cpp_rgctx_method(method->rgctx_data, 4));
		return L_16;
	}
}
// Method Definition Index: 66206
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_cmpistrm_emulation_TisIl2CppFullySharedGenericStruct_m16F77547DC1C2BE0F6959A4B639E1210EF674C66_gshared (Il2CppFullySharedGenericStruct* ___0_a, Il2CppFullySharedGenericStruct* ___1_b, int32_t ___2_len, int32_t ___3_imm8, int32_t ___4_allOnes, Il2CppFullySharedGenericStruct ___5_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	const uint32_t SizeOf_T_tC319464E6946647CC7BFD95709030A0B11A82E13 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 3));
	const Il2CppFullySharedGenericStruct L_14 = alloca(SizeOf_T_tC319464E6946647CC7BFD95709030A0B11A82E13);
	int32_t V_0 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:126>
		Il2CppFullySharedGenericStruct* L_0 = ___0_a;
		Il2CppFullySharedGenericStruct* L_1 = ___0_a;
		int32_t L_2 = ___2_len;
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_3;
		L_3 = ((  int32_t (*) (Il2CppFullySharedGenericStruct*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		Il2CppFullySharedGenericStruct* L_4 = ___1_b;
		Il2CppFullySharedGenericStruct* L_5 = ___1_b;
		int32_t L_6 = ___2_len;
		int32_t L_7;
		L_7 = ((  int32_t (*) (Il2CppFullySharedGenericStruct*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_8 = ___2_len;
		int32_t L_9 = ___3_imm8;
		int32_t L_10 = ___4_allOnes;
		int32_t L_11;
		L_11 = ((  int32_t (*) (Il2CppFullySharedGenericStruct*, int32_t, Il2CppFullySharedGenericStruct*, int32_t, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(L_0, L_3, L_4, L_7, L_8, L_9, L_10, il2cpp_rgctx_method(method->rgctx_data, 2));
		V_0 = L_11;
		//<source_info:./Library/PackageCache/com.unity.burst@f7a407abf4d5/Runtime/Intrinsics/x86/Sse4_2.cs:128>
		int32_t L_12 = ___2_len;
		int32_t L_13 = ___3_imm8;
		il2cpp_codegen_memcpy(L_14, ___5_allOnesT, SizeOf_T_tC319464E6946647CC7BFD95709030A0B11A82E13);
		int32_t L_15 = V_0;
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_16;
		L_16 = InvokerFuncInvoker4< v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61, int32_t, int32_t, Il2CppFullySharedGenericStruct, int32_t >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 4)), il2cpp_rgctx_method(method->rgctx_data, 4), NULL, L_12, L_13, L_14, L_15);
		return L_16;
	}
}
// Method Definition Index: 59062
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StreamingState_Update_TisContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7_mF9E800270D3570EFABD72A330AC68B875E236375_gshared (StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020* __this, ContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7* ___0_input, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/xxHash3.StreamingState.cs:145>
		ContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7* L_0 = ___0_input;
		void* L_1;
		L_1 = UnsafeUtilityExtensions_AddressOf_TisContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7_m85266A04E5B522991EBAA42F3FC3CCB8519D0C5D_inline(L_0, il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_2;
		L_2 = UnsafeUtility_SizeOf_TisContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7_m65ADB6FA4CDF3D140FA70FD5EECA5FB8FBFCFC7C_inline(il2cpp_rgctx_method(method->rgctx_data, 2));
		il2cpp_codegen_runtime_class_init_inline(StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020_il2cpp_TypeInfo_var);
		StreamingState_Update_mD0C172FBC9AB99BC72DF8CC3665ABB61658AB9E5(__this, L_1, L_2, NULL);
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/xxHash3.StreamingState.cs:146>
		return;
	}
}
IL2CPP_EXTERN_C  void StreamingState_Update_TisContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7_mF9E800270D3570EFABD72A330AC68B875E236375_AdjustorThunk (RuntimeObject* __this, ContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7* ___0_input, const RuntimeMethod* method)
{
	StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020*>(__this + _offset);
	StreamingState_Update_TisContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7_mF9E800270D3570EFABD72A330AC68B875E236375(_thisAdjusted, ___0_input, method);
}
// Method Definition Index: 59062
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StreamingState_Update_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mAEB133EB1AAAA88E4A720F913C58CAB0DA1F7B5B_gshared (StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020* __this, int32_t* ___0_input, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/xxHash3.StreamingState.cs:145>
		int32_t* L_0 = ___0_input;
		void* L_1;
		L_1 = UnsafeUtilityExtensions_AddressOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mEED178608CB87EEA96C8A7B57B13B0172B827EEC_inline(L_0, il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_2;
		L_2 = UnsafeUtility_SizeOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mED481D505BF43CBD96972069EDD4E3509BE84931_inline(il2cpp_rgctx_method(method->rgctx_data, 2));
		il2cpp_codegen_runtime_class_init_inline(StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020_il2cpp_TypeInfo_var);
		StreamingState_Update_mD0C172FBC9AB99BC72DF8CC3665ABB61658AB9E5(__this, L_1, L_2, NULL);
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/xxHash3.StreamingState.cs:146>
		return;
	}
}
IL2CPP_EXTERN_C  void StreamingState_Update_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mAEB133EB1AAAA88E4A720F913C58CAB0DA1F7B5B_AdjustorThunk (RuntimeObject* __this, int32_t* ___0_input, const RuntimeMethod* method)
{
	StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020*>(__this + _offset);
	StreamingState_Update_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mAEB133EB1AAAA88E4A720F913C58CAB0DA1F7B5B(_thisAdjusted, ___0_input, method);
}
// Method Definition Index: 59062
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StreamingState_Update_TisIl2CppFullySharedGenericStruct_m301FBB6A80BBA46BB5AC2B0DF206CAB72593DE1D_gshared (StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020* __this, Il2CppFullySharedGenericStruct* ___0_input, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/xxHash3.StreamingState.cs:145>
		Il2CppFullySharedGenericStruct* L_0 = ___0_input;
		void* L_1;
		L_1 = ((  void* (*) (Il2CppFullySharedGenericStruct*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(L_0, il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_2;
		L_2 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		il2cpp_codegen_runtime_class_init_inline(StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020_il2cpp_TypeInfo_var);
		StreamingState_Update_mD0C172FBC9AB99BC72DF8CC3665ABB61658AB9E5(__this, L_1, L_2, NULL);
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/xxHash3.StreamingState.cs:146>
		return;
	}
}
IL2CPP_EXTERN_C  void StreamingState_Update_TisIl2CppFullySharedGenericStruct_m301FBB6A80BBA46BB5AC2B0DF206CAB72593DE1D_AdjustorThunk (RuntimeObject* __this, Il2CppFullySharedGenericStruct* ___0_input, const RuntimeMethod* method)
{
	StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020*>(__this + _offset);
	StreamingState_Update_TisIl2CppFullySharedGenericStruct_m301FBB6A80BBA46BB5AC2B0DF206CAB72593DE1D(_thisAdjusted, ___0_input, method);
}
// Method Definition Index: 58082
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t* Array_Allocate_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m2E404D8AF8D8A7E55C35E5BF8695276E1C998C1D_gshared (int64_t ___0_count, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:103>
		int64_t L_0 = ___0_count;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_1 = ___1_allocator;
		int32_t* L_2;
		L_2 = Array_Resize_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mEE512F558B8B16B19497E4DF8445518F289534BE((int32_t*)((uintptr_t)0), ((int64_t)0), L_0, L_1, il2cpp_rgctx_method(method->rgctx_data, 0));
		return L_2;
	}
}
// Method Definition Index: 58082
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericStruct* Array_Allocate_TisIl2CppFullySharedGenericStruct_m472C3AE183E3C768741B28481DD1F012013B13A6_gshared (int64_t ___0_count, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:103>
		int64_t L_0 = ___0_count;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_1 = ___1_allocator;
		Il2CppFullySharedGenericStruct* L_2;
		L_2 = ((  Il2CppFullySharedGenericStruct* (*) (Il2CppFullySharedGenericStruct*, int64_t, int64_t, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))((Il2CppFullySharedGenericStruct*)((uintptr_t)0), ((int64_t)0), L_0, L_1, il2cpp_rgctx_method(method->rgctx_data, 0));
		return L_2;
	}
}
// Method Definition Index: 58082
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* Array_Allocate_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_mCDBD1381CA662F016D4B6003D9BA89FE592EB6D8_gshared (int64_t ___0_count, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:103>
		int64_t L_0 = ___0_count;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_1 = ___1_allocator;
		MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* L_2;
		L_2 = Array_Resize_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m66D39A0700C852DFD578157D9E4862A8230233F3((MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84*)((uintptr_t)0), ((int64_t)0), L_0, L_1, il2cpp_rgctx_method(method->rgctx_data, 0));
		return L_2;
	}
}
// Method Definition Index: 58083
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Free_TisIl2CppFullySharedGenericStruct_m6AA7597FA98F8020ABEFACEA0A1D00A384716627_gshared (Il2CppFullySharedGenericStruct* ___0_pointer, int64_t ___1_count, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___2_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:110>
		Il2CppFullySharedGenericStruct* L_0 = ___0_pointer;
		if ((!(((uintptr_t)L_0) == ((uintptr_t)((uintptr_t)0)))))
		{
			goto IL_0006;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:111>
		return;
	}

IL_0006:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:112>
		Il2CppFullySharedGenericStruct* L_1 = ___0_pointer;
		int64_t L_2 = ___1_count;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___2_allocator;
		Il2CppFullySharedGenericStruct* L_4;
		L_4 = ((  Il2CppFullySharedGenericStruct* (*) (Il2CppFullySharedGenericStruct*, int64_t, int64_t, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(L_1, L_2, ((int64_t)0), L_3, il2cpp_rgctx_method(method->rgctx_data, 1));
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:113>
		return;
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AllocatorHelper_1_t0290FF01C365B75408A8E7D00CC67BF0D92CB97B* Array_Resize_TisAllocatorHelper_1_t0290FF01C365B75408A8E7D00CC67BF0D92CB97B_m1BB178E6D0ABE20B6120DAC0117124ABF9431AE9_gshared (AllocatorHelper_1_t0290FF01C365B75408A8E7D00CC67BF0D92CB97B* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		AllocatorHelper_1_t0290FF01C365B75408A8E7D00CC67BF0D92CB97B* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisAllocatorHelper_1_t0290FF01C365B75408A8E7D00CC67BF0D92CB97B_m3EAEE0ECC422E640B90E49964F53573F9D59D9B7_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisAllocatorHelper_1_t0290FF01C365B75408A8E7D00CC67BF0D92CB97B_m2982C28E643EA6FD5D84036353B642C3169A6775(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (AllocatorHelper_1_t0290FF01C365B75408A8E7D00CC67BF0D92CB97B*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR HashMapHelper_1_t1922B493DF75C945824746A291BE8AD04E7A6910* Array_Resize_TisHashMapHelper_1_t1922B493DF75C945824746A291BE8AD04E7A6910_m5A219217E61D575B84462435AC885BDE02743803_gshared (HashMapHelper_1_t1922B493DF75C945824746A291BE8AD04E7A6910* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		HashMapHelper_1_t1922B493DF75C945824746A291BE8AD04E7A6910* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisHashMapHelper_1_t1922B493DF75C945824746A291BE8AD04E7A6910_mEACF1ADDBA4E72AA75650188B2C43D216732A0A2_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisHashMapHelper_1_t1922B493DF75C945824746A291BE8AD04E7A6910_mDC1000E76EB4699ECD216942EA8B893E2414871A(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (HashMapHelper_1_t1922B493DF75C945824746A291BE8AD04E7A6910*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR HashMapHelper_1_tB74757C88AFC77B83E59303BFF915A4BDED9A5A5* Array_Resize_TisHashMapHelper_1_tB74757C88AFC77B83E59303BFF915A4BDED9A5A5_mB30780F04BA82E86C12DF1432DE19DDD4AC07205_gshared (HashMapHelper_1_tB74757C88AFC77B83E59303BFF915A4BDED9A5A5* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		HashMapHelper_1_tB74757C88AFC77B83E59303BFF915A4BDED9A5A5* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisHashMapHelper_1_tB74757C88AFC77B83E59303BFF915A4BDED9A5A5_mEA64A1F1EC2CEE94044343CE8EFB46206629AB77_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisHashMapHelper_1_tB74757C88AFC77B83E59303BFF915A4BDED9A5A5_m148858A5CC66194B13FF0CD3CFD111AEA0AE3979(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (HashMapHelper_1_tB74757C88AFC77B83E59303BFF915A4BDED9A5A5*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR HashMapHelper_1_tF4097677DF54F9B7101CE52DA301CACDF02D8AD9* Array_Resize_TisHashMapHelper_1_tF4097677DF54F9B7101CE52DA301CACDF02D8AD9_mA79CE685A626CC9AC81049061F87FB6D5305C23F_gshared (HashMapHelper_1_tF4097677DF54F9B7101CE52DA301CACDF02D8AD9* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		HashMapHelper_1_tF4097677DF54F9B7101CE52DA301CACDF02D8AD9* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisHashMapHelper_1_tF4097677DF54F9B7101CE52DA301CACDF02D8AD9_mBE257998246FC27D92E08B57914641E77B6D310A_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisHashMapHelper_1_tF4097677DF54F9B7101CE52DA301CACDF02D8AD9_mD632058B768B6CFE85AFD1CC15A00EF3CF56D26F(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (HashMapHelper_1_tF4097677DF54F9B7101CE52DA301CACDF02D8AD9*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR HashMapHelper_1_t55F6D796BFB8E5F42BE6369F25DF63EC9F81AFBC* Array_Resize_TisHashMapHelper_1_t55F6D796BFB8E5F42BE6369F25DF63EC9F81AFBC_m98BE3A4781EF217479254C9ED972AA53B015FAD2_gshared (HashMapHelper_1_t55F6D796BFB8E5F42BE6369F25DF63EC9F81AFBC* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		HashMapHelper_1_t55F6D796BFB8E5F42BE6369F25DF63EC9F81AFBC* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisHashMapHelper_1_t55F6D796BFB8E5F42BE6369F25DF63EC9F81AFBC_m4C50BC02467EFFE9FE6A6A9671C70458FD444C55_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisHashMapHelper_1_t55F6D796BFB8E5F42BE6369F25DF63EC9F81AFBC_mC03E522A34FA831417562DBAC1448B62C17F2757(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (HashMapHelper_1_t55F6D796BFB8E5F42BE6369F25DF63EC9F81AFBC*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B* Array_Resize_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m3411CCE45309DF743A524C406531532C4FC8CD72_gshared (HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m8058188B2884F5674C5A4C9C7AFC0A59000CC56F_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m9D33FAB445EBAAEAB91BED2D158B3290B610D47E(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR HashMapHelper_1_t52DEB1D232D9067231DF945A04789178DDC0119D* Array_Resize_TisHashMapHelper_1_t52DEB1D232D9067231DF945A04789178DDC0119D_mF0B6C14EA37ECD78A3F6DD56A7392A0B336B476A_gshared (HashMapHelper_1_t52DEB1D232D9067231DF945A04789178DDC0119D* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		HashMapHelper_1_t52DEB1D232D9067231DF945A04789178DDC0119D* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisHashMapHelper_1_t52DEB1D232D9067231DF945A04789178DDC0119D_m77A04380E3226A5E4F4A53E9B2C20D8C7AB95983_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisHashMapHelper_1_t52DEB1D232D9067231DF945A04789178DDC0119D_m54E02D815E5622CFC48D78494D838723A951EED5(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (HashMapHelper_1_t52DEB1D232D9067231DF945A04789178DDC0119D*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR HashMapHelper_1_t2DD122ED66B38FE6A3FF1935D7FDFE0E07AA7C09* Array_Resize_TisHashMapHelper_1_t2DD122ED66B38FE6A3FF1935D7FDFE0E07AA7C09_m06F94DA226C3DF4D7104F6A2D30287F2F4382CF2_gshared (HashMapHelper_1_t2DD122ED66B38FE6A3FF1935D7FDFE0E07AA7C09* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		HashMapHelper_1_t2DD122ED66B38FE6A3FF1935D7FDFE0E07AA7C09* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisHashMapHelper_1_t2DD122ED66B38FE6A3FF1935D7FDFE0E07AA7C09_m978FAC1AAB7675C2941BCE49E452082F18DD4C53_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisHashMapHelper_1_t2DD122ED66B38FE6A3FF1935D7FDFE0E07AA7C09_m06B8198277B6B1F22CF35D804493FB2EBAE1E9AE(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (HashMapHelper_1_t2DD122ED66B38FE6A3FF1935D7FDFE0E07AA7C09*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR HashMapHelper_1_tE18033C6B74BE6B9BAE79F2ADD9BC2C916DFA729* Array_Resize_TisHashMapHelper_1_tE18033C6B74BE6B9BAE79F2ADD9BC2C916DFA729_mC1BCEB1E663FCB1FAB803532004A54CE234668F8_gshared (HashMapHelper_1_tE18033C6B74BE6B9BAE79F2ADD9BC2C916DFA729* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		HashMapHelper_1_tE18033C6B74BE6B9BAE79F2ADD9BC2C916DFA729* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisHashMapHelper_1_tE18033C6B74BE6B9BAE79F2ADD9BC2C916DFA729_m56495057B39DFE5087EA47F7331FD40597492A2A_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisHashMapHelper_1_tE18033C6B74BE6B9BAE79F2ADD9BC2C916DFA729_mF8605C6E2C9BE41D89B23148AA5A7F67596C0D63(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (HashMapHelper_1_tE18033C6B74BE6B9BAE79F2ADD9BC2C916DFA729*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* Array_Resize_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_m56B4A5FA244655F35F0482ADF8BFAE16F683FAF1_gshared (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_m3446503708EF53FF3664993B371F061F2C98A44F_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_mC94DEDD2611C7C84632B957D3FDB324F2C85EA7A(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR HashMapHelper_1_tFE70D47D7D4D5A59CFA6D8E68852A7EE5BDB4854* Array_Resize_TisHashMapHelper_1_tFE70D47D7D4D5A59CFA6D8E68852A7EE5BDB4854_mCD239831F72D362C3D4AA1EE128A5FEAB61557F6_gshared (HashMapHelper_1_tFE70D47D7D4D5A59CFA6D8E68852A7EE5BDB4854* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		HashMapHelper_1_tFE70D47D7D4D5A59CFA6D8E68852A7EE5BDB4854* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisHashMapHelper_1_tFE70D47D7D4D5A59CFA6D8E68852A7EE5BDB4854_m806F9CFE9718FE6DF13E117477C17767D1708279_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisHashMapHelper_1_tFE70D47D7D4D5A59CFA6D8E68852A7EE5BDB4854_m0660231136B868BA362E8045755B0F3C57CC67BA(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (HashMapHelper_1_tFE70D47D7D4D5A59CFA6D8E68852A7EE5BDB4854*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258* Array_Resize_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m87C047C9A0252B77CBF08B5DDEF1D493A14DD276_gshared (UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m9DD3BAE2675B37478EA2C9AA9DAFD2C6C1F5BF4E_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m796E3C1D5F3A55A9EFFD1AA98C09AB788198C7A1(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD* Array_Resize_TisUnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD_mFF71C2DBFEFF6594159B5324E0EC19D878450E2E_gshared (UnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		UnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD_m201D21D3AC9187C9EFEF16F0B593FAC6BE19EE72_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD_m70E5F2C375F3B4039114929EBDF86DFCBF1EF99C(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (UnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515* Array_Resize_TisUnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515_mCFE5759D51678924C8C9E90B0A2ABA0AEF5AB6F6_gshared (UnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		UnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515_m067749C993CAF4A3AA0673C46673216D995516DE_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515_m756E0E44BD2515C8949896575600531B61F5B16B(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (UnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6* Array_Resize_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_mCA2193874571CACB1B8D75FBD095B8AD29C6403A_gshared (UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m9108AF5F196154FF71AD62376A7411B92391F000_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m219DC3BB1EF8E9E18A66470555A9974E2C7D9EC6(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeRingQueue_1_t916A7CB801E880FD1A00447CC4815827882753ED* Array_Resize_TisUnsafeRingQueue_1_t916A7CB801E880FD1A00447CC4815827882753ED_m79D605D658ABB9FFCFC6F6CCCFAD77357CE92ED2_gshared (UnsafeRingQueue_1_t916A7CB801E880FD1A00447CC4815827882753ED* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		UnsafeRingQueue_1_t916A7CB801E880FD1A00447CC4815827882753ED* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUnsafeRingQueue_1_t916A7CB801E880FD1A00447CC4815827882753ED_m6F51DC601209DBB54B5546FC945C0B69D996922D_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUnsafeRingQueue_1_t916A7CB801E880FD1A00447CC4815827882753ED_m84ACE3D5E56DC5439E2DA35A7C00916492258492(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (UnsafeRingQueue_1_t916A7CB801E880FD1A00447CC4815827882753ED*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR BlobAssetBatch_tE7DAEECF09D38F983FE3F829F7774B40F4FD6B46* Array_Resize_TisBlobAssetBatch_tE7DAEECF09D38F983FE3F829F7774B40F4FD6B46_m88AB149EF2F638906F9BAC5040CC13687AA9C720_gshared (BlobAssetBatch_tE7DAEECF09D38F983FE3F829F7774B40F4FD6B46* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		BlobAssetBatch_tE7DAEECF09D38F983FE3F829F7774B40F4FD6B46* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisBlobAssetBatch_tE7DAEECF09D38F983FE3F829F7774B40F4FD6B46_m1B05D4B205551B035C03FC4B7D1757D2D1A5C4CD_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisBlobAssetBatch_tE7DAEECF09D38F983FE3F829F7774B40F4FD6B46_mBBE1A454562855891445DF33C1BB6CDA67E79903(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (BlobAssetBatch_tE7DAEECF09D38F983FE3F829F7774B40F4FD6B46*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR BlobAssetHeader_t3EC5AD955B287949B57D36BBDE25A4D1BA85E639* Array_Resize_TisBlobAssetHeader_t3EC5AD955B287949B57D36BBDE25A4D1BA85E639_mDA3B3913A792AEE470437FD488846DBF09AF0DB4_gshared (BlobAssetHeader_t3EC5AD955B287949B57D36BBDE25A4D1BA85E639* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		BlobAssetHeader_t3EC5AD955B287949B57D36BBDE25A4D1BA85E639* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisBlobAssetHeader_t3EC5AD955B287949B57D36BBDE25A4D1BA85E639_mCC8381920C8736C7CFCA6E556B49BE02B71FE34C_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisBlobAssetHeader_t3EC5AD955B287949B57D36BBDE25A4D1BA85E639_mEBE2379486D6F502175AFA8545E6B0459F1F340C(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (BlobAssetHeader_t3EC5AD955B287949B57D36BBDE25A4D1BA85E639*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint8_t* Array_Resize_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1767423622567D1059537F40EF99A5522126FBD0_gshared (uint8_t* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		uint8_t* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m97C7D5E5DE74DC60A0ECAA914830BEDF2C46ACAA_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mB152D3C658FB48DEDB6E662EEB0C91018E7F2857(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (uint8_t*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ChainCleanup_t720381A951125FF2EAA04EA1E544B86820F30122* Array_Resize_TisChainCleanup_t720381A951125FF2EAA04EA1E544B86820F30122_mC4213BAC6D4F2943C3A25CEE4E2B86E58AAAFD1F_gshared (ChainCleanup_t720381A951125FF2EAA04EA1E544B86820F30122* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		ChainCleanup_t720381A951125FF2EAA04EA1E544B86820F30122* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisChainCleanup_t720381A951125FF2EAA04EA1E544B86820F30122_mD5270B21C83F2AE30AEA6AABCBF5AC537D97A6ED_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisChainCleanup_t720381A951125FF2EAA04EA1E544B86820F30122_m12E55909AEBB7242169E344DD51218DBDA18F9F6(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (ChainCleanup_t720381A951125FF2EAA04EA1E544B86820F30122*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR DoubleRewindableAllocators_t8D3615CDAAECEE59D64F85F9E0F46D07168A7069* Array_Resize_TisDoubleRewindableAllocators_t8D3615CDAAECEE59D64F85F9E0F46D07168A7069_m6523C471361B1036241A7F0E9CCFDC6B02E54D53_gshared (DoubleRewindableAllocators_t8D3615CDAAECEE59D64F85F9E0F46D07168A7069* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		DoubleRewindableAllocators_t8D3615CDAAECEE59D64F85F9E0F46D07168A7069* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisDoubleRewindableAllocators_t8D3615CDAAECEE59D64F85F9E0F46D07168A7069_m12CD64E162BDD4E9964F0A20D7221DF379B37569_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisDoubleRewindableAllocators_t8D3615CDAAECEE59D64F85F9E0F46D07168A7069_m92DFB3274CFF4B4484E6655675E1C1BF4AFB554E(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (DoubleRewindableAllocators_t8D3615CDAAECEE59D64F85F9E0F46D07168A7069*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR DynamicBlobAssetBatch_tAF1A195EBA8DD36359A9439ED1BB2D99AD81F027* Array_Resize_TisDynamicBlobAssetBatch_tAF1A195EBA8DD36359A9439ED1BB2D99AD81F027_mD047E2103B69ADE532725361F3A30D34E758227A_gshared (DynamicBlobAssetBatch_tAF1A195EBA8DD36359A9439ED1BB2D99AD81F027* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		DynamicBlobAssetBatch_tAF1A195EBA8DD36359A9439ED1BB2D99AD81F027* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisDynamicBlobAssetBatch_tAF1A195EBA8DD36359A9439ED1BB2D99AD81F027_mB42BE557FD211C59CE7C30170B290F71275A669F_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisDynamicBlobAssetBatch_tAF1A195EBA8DD36359A9439ED1BB2D99AD81F027_m4C583B0CA45B53C9B24E8765BCCC2A3B9A835EA1(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (DynamicBlobAssetBatch_tAF1A195EBA8DD36359A9439ED1BB2D99AD81F027*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ECBChainHeapElement_tE83963A87C0B8B2EEDE315AF9DFF749A38C666DD* Array_Resize_TisECBChainHeapElement_tE83963A87C0B8B2EEDE315AF9DFF749A38C666DD_m3FC5D20DEB689AD27C4DB65700CA2AF1611CBC4B_gshared (ECBChainHeapElement_tE83963A87C0B8B2EEDE315AF9DFF749A38C666DD* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		ECBChainHeapElement_tE83963A87C0B8B2EEDE315AF9DFF749A38C666DD* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisECBChainHeapElement_tE83963A87C0B8B2EEDE315AF9DFF749A38C666DD_m72A92B4DB122FC4BC45F18FB459B619269492BC7_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisECBChainHeapElement_tE83963A87C0B8B2EEDE315AF9DFF749A38C666DD_mD8DF741CD89D1CEF5C4F9A493181908BDC5C56F5(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (ECBChainHeapElement_tE83963A87C0B8B2EEDE315AF9DFF749A38C666DD*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ECBChunk_tF8E51552DBA320AB90FCAE9CF1185FAFD3764F4F* Array_Resize_TisECBChunk_tF8E51552DBA320AB90FCAE9CF1185FAFD3764F4F_m80272E94DE8B2A79DF76F85036F133DB50414F61_gshared (ECBChunk_tF8E51552DBA320AB90FCAE9CF1185FAFD3764F4F* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		ECBChunk_tF8E51552DBA320AB90FCAE9CF1185FAFD3764F4F* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisECBChunk_tF8E51552DBA320AB90FCAE9CF1185FAFD3764F4F_mB2F57AD808C223787F8F2F7FE94F1CA09478E439_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisECBChunk_tF8E51552DBA320AB90FCAE9CF1185FAFD3764F4F_mA06C51E42878473801E3CCADF345EC64265E1025(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (ECBChunk_tF8E51552DBA320AB90FCAE9CF1185FAFD3764F4F*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Entity_t56176FC78C475061A82383D9E0CEE352C6C52ABD* Array_Resize_TisEntity_t56176FC78C475061A82383D9E0CEE352C6C52ABD_mE007DF62B8C9B1CD5FBF5D0781DDAAB88A82321B_gshared (Entity_t56176FC78C475061A82383D9E0CEE352C6C52ABD* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		Entity_t56176FC78C475061A82383D9E0CEE352C6C52ABD* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisEntity_t56176FC78C475061A82383D9E0CEE352C6C52ABD_m177EBEBF64B94FE192C8268AE6BCB9A563047C3C_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisEntity_t56176FC78C475061A82383D9E0CEE352C6C52ABD_mC7729F36ED36489AFC5470E4D99F9EE076B9C40B(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (Entity_t56176FC78C475061A82383D9E0CEE352C6C52ABD*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB* Array_Resize_TisEntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB_m84CF0779226E831E80C175FCC8E9390C268C023B_gshared (EntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		EntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisEntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB_m8B4CD5160A7C28D2A54CB1E185FC3B59AD633CC2_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisEntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB_m70E6D94B1AA9B8CFBA3C7654EDB0E506990B6808(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (EntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityCommandBufferData_t88C8EFD5BBEF42F8008AF73FA2C27B60E5A31DC2* Array_Resize_TisEntityCommandBufferData_t88C8EFD5BBEF42F8008AF73FA2C27B60E5A31DC2_mF04572F5246CAD605EA9968455C511577797530C_gshared (EntityCommandBufferData_t88C8EFD5BBEF42F8008AF73FA2C27B60E5A31DC2* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		EntityCommandBufferData_t88C8EFD5BBEF42F8008AF73FA2C27B60E5A31DC2* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisEntityCommandBufferData_t88C8EFD5BBEF42F8008AF73FA2C27B60E5A31DC2_mF2283D03D9B90B77481B9489B742165F9BB40EF5_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisEntityCommandBufferData_t88C8EFD5BBEF42F8008AF73FA2C27B60E5A31DC2_m47AC89596CA42CA8709BCEF28C51EC7D4611668F(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (EntityCommandBufferData_t88C8EFD5BBEF42F8008AF73FA2C27B60E5A31DC2*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* Array_Resize_TisEntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_mD7E6EC5CA9692383A95A2437EF91028D9299BDE9_gshared (EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisEntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_m1D3A68FF0C582ADAE2A63F86DA45E6C4C5F713B9_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisEntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_mFB3AC0FA7E1BDFF541B132DAE5CEA6917E2A2E48(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityNameStoreAccessData_t5AC842F68D9F5083E23B12C17F81F43535F2ED1F* Array_Resize_TisEntityNameStoreAccessData_t5AC842F68D9F5083E23B12C17F81F43535F2ED1F_m1BCCE627E59DB0EBC2972ABE5736EF548E05669D_gshared (EntityNameStoreAccessData_t5AC842F68D9F5083E23B12C17F81F43535F2ED1F* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		EntityNameStoreAccessData_t5AC842F68D9F5083E23B12C17F81F43535F2ED1F* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisEntityNameStoreAccessData_t5AC842F68D9F5083E23B12C17F81F43535F2ED1F_mBBB7A97578412E4A4A38B2F30EE24BE2425B70B8_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisEntityNameStoreAccessData_t5AC842F68D9F5083E23B12C17F81F43535F2ED1F_m0B3318CDE808F4FA12401BD3E39E889029BAB85F(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (EntityNameStoreAccessData_t5AC842F68D9F5083E23B12C17F81F43535F2ED1F*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* Array_Resize_TisEntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_m2BA136E25A4B106A2F4CDAE9B228BFB7CDCFA1F8_gshared (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisEntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_m2F10D3E64E3CB71DD152025B3F5A3103ABB2DD07_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisEntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_m2569D7A993EADB9F70B33CDC2042DE372E7C2F74(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t* Array_Resize_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mEE512F558B8B16B19497E4DF8445518F289534BE_gshared (int32_t* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		int32_t* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mED481D505BF43CBD96972069EDD4E3509BE84931_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m274F833CD001C63E56A22D8F42C76CE8C6CC39DF(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (int32_t*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t* Array_Resize_TisIntPtr_t_mE1CA5D0262B2B8D4C9453D51DF34A94A0CF3556F_gshared (intptr_t* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		intptr_t* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisIntPtr_t_mB2B3CFF1CB804C99734D4E2F5D8A8C9DB0D209A8_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisIntPtr_t_mB17C6C168D8CA088879EDD0D5B9923F70F5269B8(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (intptr_t*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* Array_Resize_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_mE2D2B34B431BF961875B8E0ED2F5410332545CE5_gshared (JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m9648A6CA697B17B009BBEDCE817AF98293EA07A8_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_mC7DDA799532A41B6BBF8F2B145215B78667BE6CE(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint16_t* Array_Resize_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m41C40ADC5F3A02E9C5ED1D9C17AFA35A8134922A_gshared (uint16_t* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		uint16_t* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_mEC9469DBD91362D6135B8F5A81E90486BF328075_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m742C058FF2011B81DD081BA92DC32E0E34CEAAC8(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (uint16_t*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t* Array_Resize_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mD3BD6186C5C7D5B3952897C2602B7C5BEA1A7E81_gshared (uint64_t* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		uint64_t* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m6C198B51ACD7B8EC62D5E0E75433C12BE9D65A58_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m8127223B00E08567EC09EF1D992F89C74F248AB0(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (uint64_t*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4* Array_Resize_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_m61718F1D9CCF897E5BE50BB484C8D816C988DF6F_gshared (UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_mCCA7CED28D808054F7C94E1BF58205316AEE194F_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_m56B5B812224539B0C633BABE891ADDE1973580F6(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* Array_Resize_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_m1576AD06CC03F6E9D06FC13A0F280519B1666726_gshared (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mB6FE4CAF35894EF5E357881DA5A0EAE9EDAD3754_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mC1EBD5161294EF95B8AC378DDF616869D287DC36(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C* Array_Resize_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_mF6857EF793C9156A611EAA1E63A02352EFE46784_gshared (UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_mEBEAA7CA1C71A37FA5CBCF89A0C9B78ABAD5C8C7_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m3DF404928C7038CCD5C05BBBA41C4B2FD35A4253(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* Array_Resize_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m1082D56F32F50ECA3CFFDB87DB3512F2CE7544F4_gshared (UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m25193E03B20C96400F243B7A682AF5BB8F030297_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_mD84C2AFFB4ED036B913CEAD2FBF8A60E9C3A017D(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67* Array_Resize_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m520F16927035702AB0DF9C30EE88686BDC346F21_gshared (UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m79CAC169FC4593612624CB619E7D6F6FD7447517_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m5892DF1B875736B0E3612716E560A4E4AD5F6591(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UntypedWeakReferenceId_tE6BA94FD975EA12B639C0A568532BD1AB874492A* Array_Resize_TisUntypedWeakReferenceId_tE6BA94FD975EA12B639C0A568532BD1AB874492A_mFDC30F29248610D815C39F45B8F345AA08AEE4C3_gshared (UntypedWeakReferenceId_tE6BA94FD975EA12B639C0A568532BD1AB874492A* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		UntypedWeakReferenceId_tE6BA94FD975EA12B639C0A568532BD1AB874492A* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUntypedWeakReferenceId_tE6BA94FD975EA12B639C0A568532BD1AB874492A_mFAA6F9C6A87B112BBD85F22709B4E18563AA5593_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUntypedWeakReferenceId_tE6BA94FD975EA12B639C0A568532BD1AB874492A_m2BDC205D9F080390F4B1A1097C470377D56579B0(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (UntypedWeakReferenceId_tE6BA94FD975EA12B639C0A568532BD1AB874492A*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericStruct* Array_Resize_TisIl2CppFullySharedGenericStruct_m07039200651D43DBB7FBC0CB244761DA34C164FD_gshared (Il2CppFullySharedGenericStruct* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		Il2CppFullySharedGenericStruct* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (Il2CppFullySharedGenericStruct*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR DependencyHandle_t73038501598DF9B7E83BF8486D87B9DED6200B15* Array_Resize_TisDependencyHandle_t73038501598DF9B7E83BF8486D87B9DED6200B15_m0094C8B059968F4CFEBDDE8C828B9F9E35EACD3C_gshared (DependencyHandle_t73038501598DF9B7E83BF8486D87B9DED6200B15* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		DependencyHandle_t73038501598DF9B7E83BF8486D87B9DED6200B15* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisDependencyHandle_t73038501598DF9B7E83BF8486D87B9DED6200B15_m372324DEBD6B906BB1927888F56DCBFBDC0DAC4C_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisDependencyHandle_t73038501598DF9B7E83BF8486D87B9DED6200B15_mCEA60798AAEFB42EBE92BFD4C8BFE55710CF1C17(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (DependencyHandle_t73038501598DF9B7E83BF8486D87B9DED6200B15*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NodeHeader_tC393A021B9635C19BEC9CEEA905E76D4B90FDC4F* Array_Resize_TisNodeHeader_tC393A021B9635C19BEC9CEEA905E76D4B90FDC4F_mD6D3FF1C7DE90BCF2778DEEE1BE417217DDEE9A0_gshared (NodeHeader_tC393A021B9635C19BEC9CEEA905E76D4B90FDC4F* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		NodeHeader_tC393A021B9635C19BEC9CEEA905E76D4B90FDC4F* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisNodeHeader_tC393A021B9635C19BEC9CEEA905E76D4B90FDC4F_mBBB27F335B5822EB0F181EA661BBCF2EA0519A3C_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisNodeHeader_tC393A021B9635C19BEC9CEEA905E76D4B90FDC4F_m4035D9C7ED339F00B807E15D0E453D04898D957F(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (NodeHeader_tC393A021B9635C19BEC9CEEA905E76D4B90FDC4F*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR BufferWithFixUp_tDFD5630DDFDBC051A462A026DFAEAA4A047FB3B6* Array_Resize_TisBufferWithFixUp_tDFD5630DDFDBC051A462A026DFAEAA4A047FB3B6_m7DAE1ADD2CE4F9F542E9AF8FD9C173FD9161CBFE_gshared (BufferWithFixUp_tDFD5630DDFDBC051A462A026DFAEAA4A047FB3B6* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		BufferWithFixUp_tDFD5630DDFDBC051A462A026DFAEAA4A047FB3B6* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisBufferWithFixUp_tDFD5630DDFDBC051A462A026DFAEAA4A047FB3B6_m36A4E0B3E7DFA48026FB77ABAFB38AC1F999BB1F_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisBufferWithFixUp_tDFD5630DDFDBC051A462A026DFAEAA4A047FB3B6_m17951F8123258E416C8A1B9CB83A5DDE16A48C3C(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (BufferWithFixUp_tDFD5630DDFDBC051A462A026DFAEAA4A047FB3B6*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* Array_Resize_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m66D39A0700C852DFD578157D9E4862A8230233F3_gshared (MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m4A0947EA519A2614EC19544513888A4DC5F42919_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m6AD8B4EF31CDD94CA734378B1443806DAFE68A05(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR HeaderData_t5CE38A1426623168DB817F1D87E639856A2614B3* Array_Resize_TisHeaderData_t5CE38A1426623168DB817F1D87E639856A2614B3_mF3EFD027B80ED48FA9F9721C8ED03D33942B0E79_gshared (HeaderData_t5CE38A1426623168DB817F1D87E639856A2614B3* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		HeaderData_t5CE38A1426623168DB817F1D87E639856A2614B3* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisHeaderData_t5CE38A1426623168DB817F1D87E639856A2614B3_m9007635FD7971062D616805DB88395EEB43C920B_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisHeaderData_t5CE38A1426623168DB817F1D87E639856A2614B3_m47321A559CE5DBAD9A16E3C2DF5FF899C1410244(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (HeaderData_t5CE38A1426623168DB817F1D87E639856A2614B3*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StateAllocLevel1_t93303AA6CAA1A10E9819D11E131EDD90DE20043D* Array_Resize_TisStateAllocLevel1_t93303AA6CAA1A10E9819D11E131EDD90DE20043D_m030644A15F625BA380D7D7E10D2D98F07DF082BC_gshared (StateAllocLevel1_t93303AA6CAA1A10E9819D11E131EDD90DE20043D* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		StateAllocLevel1_t93303AA6CAA1A10E9819D11E131EDD90DE20043D* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisStateAllocLevel1_t93303AA6CAA1A10E9819D11E131EDD90DE20043D_m5D881A2223FC0BF2CB68E2EF91BF123C506FA136_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisStateAllocLevel1_t93303AA6CAA1A10E9819D11E131EDD90DE20043D_m821747001EAE919BBF7212AA6497A81A78FC2B36(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (StateAllocLevel1_t93303AA6CAA1A10E9819D11E131EDD90DE20043D*)(L_6);
	}
}
// Method Definition Index: 58081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR PerChunkData_t1837BB30B95C4DD39A4908ECC71AB0B75DFF9135* Array_Resize_TisPerChunkData_t1837BB30B95C4DD39A4908ECC71AB0B75DFF9135_mB768BCB7449AAC58D79DB64AB3EE0116E3C865C4_gshared (PerChunkData_t1837BB30B95C4DD39A4908ECC71AB0B75DFF9135* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/Memory.cs:96>
		PerChunkData_t1837BB30B95C4DD39A4908ECC71AB0B75DFF9135* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisPerChunkData_t1837BB30B95C4DD39A4908ECC71AB0B75DFF9135_mAB06B6453863E5D5F9644288D86E39C5848BEB1B_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisPerChunkData_t1837BB30B95C4DD39A4908ECC71AB0B75DFF9135_mA7BD893DD0B8C45C36CE456C8EC87EC2907E3172(il2cpp_rgctx_method(method->rgctx_data, 2));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		return (PerChunkData_t1837BB30B95C4DD39A4908ECC71AB0B75DFF9135*)(L_6);
	}
}
// Method Definition Index: 9997
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* EqualityComparer_1_get_Default_m7D273CC532DC2164C9C86D28C639FDEA38173C88_gshared_inline (const RuntimeMethod* method) 
{
	EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* V_0 = NULL;
	{
		EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* L_0 = ((EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 2)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* L_2;
		L_2 = EqualityComparer_1_CreateComparer_m22AF3135664449980749E1EC32EB92DB49219F9B(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 3));
		V_0 = L_2;
		EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 2)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 2)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 9997
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* EqualityComparer_1_get_Default_m7F71AAC0046A3CB8C4CEB06A5A52A1269AF7023D_gshared_inline (const RuntimeMethod* method) 
{
	EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* V_0 = NULL;
	{
		EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* L_0 = ((EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 2)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* L_2;
		L_2 = EqualityComparer_1_CreateComparer_mD5EE323D1C48F0C09CBB944FA81707B8FEE2DB6D(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 3));
		V_0 = L_2;
		EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 2)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 2)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 9997
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* EqualityComparer_1_get_Default_m80EE5C179E01BB38904781592AC72F8137541D7E_gshared_inline (const RuntimeMethod* method) 
{
	EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* V_0 = NULL;
	{
		EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* L_0 = ((EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 2)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* L_2;
		L_2 = EqualityComparer_1_CreateComparer_m5F906E9B13BCCCDF51EF0852BD9E5E0065D185F8(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 3));
		V_0 = L_2;
		EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 2)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 2)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 9997
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* EqualityComparer_1_get_Default_m41DB4C0E0A508A8326E903331DC63D410B7AB9C4_gshared_inline (const RuntimeMethod* method) 
{
	EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* V_0 = NULL;
	{
		EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* L_0 = ((EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 2)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* L_2;
		L_2 = EqualityComparer_1_CreateComparer_mEBC7BD29A8FD796A4DAA1DF4428B95D1BA4FB377(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 3));
		V_0 = L_2;
		EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 2)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 2)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 59841
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void* UnsafeUtilityExtensions_AddressOf_TisContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7_m85266A04E5B522991EBAA42F3FC3CCB8519D0C5D_gshared_inline (ContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7* ___0_value, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/UnsafeUtilityEx.cs:90>
		ContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7* L_0 = ___0_value;
		void* L_1;
		L_1 = ILSupport_AddressOf_TisContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7_m01D2486E5139DD8D56B5A959FBDD5892F83B5C23_inline(L_0, il2cpp_rgctx_method(method->rgctx_data, 1));
		return L_1;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7_m65ADB6FA4CDF3D140FA70FD5EECA5FB8FBFCFC7C_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(ContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 59841
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void* UnsafeUtilityExtensions_AddressOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mEED178608CB87EEA96C8A7B57B13B0172B827EEC_gshared_inline (int32_t* ___0_value, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		//<source_info:./Library/PackageCache/com.unity.collections@d49facba0036/Unity.Collections/UnsafeUtilityEx.cs:90>
		int32_t* L_0 = ___0_value;
		void* L_1;
		L_1 = ILSupport_AddressOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m8544D06F32E3436CE779A52F9FF3B72256EBAFAC_inline(L_0, il2cpp_rgctx_method(method->rgctx_data, 1));
		return L_1;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mED481D505BF43CBD96972069EDD4E3509BE84931_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(int32_t);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisAllocatorHelper_1_t0290FF01C365B75408A8E7D00CC67BF0D92CB97B_m3EAEE0ECC422E640B90E49964F53573F9D59D9B7_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AllocatorHelper_1_t0290FF01C365B75408A8E7D00CC67BF0D92CB97B);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_t1922B493DF75C945824746A291BE8AD04E7A6910_mEACF1ADDBA4E72AA75650188B2C43D216732A0A2_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(HashMapHelper_1_t1922B493DF75C945824746A291BE8AD04E7A6910);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_tB74757C88AFC77B83E59303BFF915A4BDED9A5A5_mEA64A1F1EC2CEE94044343CE8EFB46206629AB77_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(HashMapHelper_1_tB74757C88AFC77B83E59303BFF915A4BDED9A5A5);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_tF4097677DF54F9B7101CE52DA301CACDF02D8AD9_mBE257998246FC27D92E08B57914641E77B6D310A_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(HashMapHelper_1_tF4097677DF54F9B7101CE52DA301CACDF02D8AD9);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_t55F6D796BFB8E5F42BE6369F25DF63EC9F81AFBC_m4C50BC02467EFFE9FE6A6A9671C70458FD444C55_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(HashMapHelper_1_t55F6D796BFB8E5F42BE6369F25DF63EC9F81AFBC);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m8058188B2884F5674C5A4C9C7AFC0A59000CC56F_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_t52DEB1D232D9067231DF945A04789178DDC0119D_m77A04380E3226A5E4F4A53E9B2C20D8C7AB95983_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(HashMapHelper_1_t52DEB1D232D9067231DF945A04789178DDC0119D);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_t2DD122ED66B38FE6A3FF1935D7FDFE0E07AA7C09_m978FAC1AAB7675C2941BCE49E452082F18DD4C53_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(HashMapHelper_1_t2DD122ED66B38FE6A3FF1935D7FDFE0E07AA7C09);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_tE18033C6B74BE6B9BAE79F2ADD9BC2C916DFA729_m56495057B39DFE5087EA47F7331FD40597492A2A_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(HashMapHelper_1_tE18033C6B74BE6B9BAE79F2ADD9BC2C916DFA729);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_m3446503708EF53FF3664993B371F061F2C98A44F_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_tFE70D47D7D4D5A59CFA6D8E68852A7EE5BDB4854_m806F9CFE9718FE6DF13E117477C17767D1708279_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(HashMapHelper_1_tFE70D47D7D4D5A59CFA6D8E68852A7EE5BDB4854);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m9DD3BAE2675B37478EA2C9AA9DAFD2C6C1F5BF4E_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD_m201D21D3AC9187C9EFEF16F0B593FAC6BE19EE72_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515_m067749C993CAF4A3AA0673C46673216D995516DE_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m9108AF5F196154FF71AD62376A7411B92391F000_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeRingQueue_1_t916A7CB801E880FD1A00447CC4815827882753ED_m6F51DC601209DBB54B5546FC945C0B69D996922D_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeRingQueue_1_t916A7CB801E880FD1A00447CC4815827882753ED);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisBlobAssetBatch_tE7DAEECF09D38F983FE3F829F7774B40F4FD6B46_m1B05D4B205551B035C03FC4B7D1757D2D1A5C4CD_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(BlobAssetBatch_tE7DAEECF09D38F983FE3F829F7774B40F4FD6B46);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisBlobAssetHeader_t3EC5AD955B287949B57D36BBDE25A4D1BA85E639_mCC8381920C8736C7CFCA6E556B49BE02B71FE34C_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(BlobAssetHeader_t3EC5AD955B287949B57D36BBDE25A4D1BA85E639);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m97C7D5E5DE74DC60A0ECAA914830BEDF2C46ACAA_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(uint8_t);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisChainCleanup_t720381A951125FF2EAA04EA1E544B86820F30122_mD5270B21C83F2AE30AEA6AABCBF5AC537D97A6ED_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(ChainCleanup_t720381A951125FF2EAA04EA1E544B86820F30122);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisDoubleRewindableAllocators_t8D3615CDAAECEE59D64F85F9E0F46D07168A7069_m12CD64E162BDD4E9964F0A20D7221DF379B37569_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(DoubleRewindableAllocators_t8D3615CDAAECEE59D64F85F9E0F46D07168A7069);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisDynamicBlobAssetBatch_tAF1A195EBA8DD36359A9439ED1BB2D99AD81F027_mB42BE557FD211C59CE7C30170B290F71275A669F_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(DynamicBlobAssetBatch_tAF1A195EBA8DD36359A9439ED1BB2D99AD81F027);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisECBChainHeapElement_tE83963A87C0B8B2EEDE315AF9DFF749A38C666DD_m72A92B4DB122FC4BC45F18FB459B619269492BC7_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(ECBChainHeapElement_tE83963A87C0B8B2EEDE315AF9DFF749A38C666DD);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisECBChunk_tF8E51552DBA320AB90FCAE9CF1185FAFD3764F4F_mB2F57AD808C223787F8F2F7FE94F1CA09478E439_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(ECBChunk_tF8E51552DBA320AB90FCAE9CF1185FAFD3764F4F);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisEntity_t56176FC78C475061A82383D9E0CEE352C6C52ABD_m177EBEBF64B94FE192C8268AE6BCB9A563047C3C_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(Entity_t56176FC78C475061A82383D9E0CEE352C6C52ABD);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisEntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB_m8B4CD5160A7C28D2A54CB1E185FC3B59AD633CC2_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(EntityCommandBufferChain_tCC0FFFC083A93ADF15F28AAF7E69C8BB3D6F7CCB);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisEntityCommandBufferData_t88C8EFD5BBEF42F8008AF73FA2C27B60E5A31DC2_mF2283D03D9B90B77481B9489B742165F9BB40EF5_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(EntityCommandBufferData_t88C8EFD5BBEF42F8008AF73FA2C27B60E5A31DC2);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisEntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_m1D3A68FF0C582ADAE2A63F86DA45E6C4C5F713B9_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisEntityNameStoreAccessData_t5AC842F68D9F5083E23B12C17F81F43535F2ED1F_mBBB7A97578412E4A4A38B2F30EE24BE2425B70B8_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(EntityNameStoreAccessData_t5AC842F68D9F5083E23B12C17F81F43535F2ED1F);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisEntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_m2F10D3E64E3CB71DD152025B3F5A3103ABB2DD07_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisIntPtr_t_mB2B3CFF1CB804C99734D4E2F5D8A8C9DB0D209A8_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(intptr_t);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m9648A6CA697B17B009BBEDCE817AF98293EA07A8_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_mEC9469DBD91362D6135B8F5A81E90486BF328075_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(uint16_t);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m6C198B51ACD7B8EC62D5E0E75433C12BE9D65A58_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(uint64_t);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_mCCA7CED28D808054F7C94E1BF58205316AEE194F_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mB6FE4CAF35894EF5E357881DA5A0EAE9EDAD3754_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_mEBEAA7CA1C71A37FA5CBCF89A0C9B78ABAD5C8C7_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m25193E03B20C96400F243B7A682AF5BB8F030297_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m79CAC169FC4593612624CB619E7D6F6FD7447517_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUntypedWeakReferenceId_tE6BA94FD975EA12B639C0A568532BD1AB874492A_mFAA6F9C6A87B112BBD85F22709B4E18563AA5593_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UntypedWeakReferenceId_tE6BA94FD975EA12B639C0A568532BD1AB874492A);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisDependencyHandle_t73038501598DF9B7E83BF8486D87B9DED6200B15_m372324DEBD6B906BB1927888F56DCBFBDC0DAC4C_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(DependencyHandle_t73038501598DF9B7E83BF8486D87B9DED6200B15);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisNodeHeader_tC393A021B9635C19BEC9CEEA905E76D4B90FDC4F_mBBB27F335B5822EB0F181EA661BBCF2EA0519A3C_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(NodeHeader_tC393A021B9635C19BEC9CEEA905E76D4B90FDC4F);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisBufferWithFixUp_tDFD5630DDFDBC051A462A026DFAEAA4A047FB3B6_m36A4E0B3E7DFA48026FB77ABAFB38AC1F999BB1F_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(BufferWithFixUp_tDFD5630DDFDBC051A462A026DFAEAA4A047FB3B6);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m4A0947EA519A2614EC19544513888A4DC5F42919_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHeaderData_t5CE38A1426623168DB817F1D87E639856A2614B3_m9007635FD7971062D616805DB88395EEB43C920B_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(HeaderData_t5CE38A1426623168DB817F1D87E639856A2614B3);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisStateAllocLevel1_t93303AA6CAA1A10E9819D11E131EDD90DE20043D_m5D881A2223FC0BF2CB68E2EF91BF123C506FA136_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(StateAllocLevel1_t93303AA6CAA1A10E9819D11E131EDD90DE20043D);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 38452
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisPerChunkData_t1837BB30B95C4DD39A4908ECC71AB0B75DFF9135_mAB06B6453863E5D5F9644288D86E39C5848BEB1B_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(PerChunkData_t1837BB30B95C4DD39A4908ECC71AB0B75DFF9135);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 80964
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void* ILSupport_AddressOf_TisContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7_m01D2486E5139DD8D56B5A959FBDD5892F83B5C23_gshared_inline (ContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7* ___0_thing, const RuntimeMethod* method) 
{
	{
		ContentFileId_t630F8A1A207C9248EE434BA833823A2D5C384FD7* L_0 = ___0_thing;
		return (void*)(L_0);
	}
}
// Method Definition Index: 80964
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void* ILSupport_AddressOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m8544D06F32E3436CE779A52F9FF3B72256EBAFAC_gshared_inline (int32_t* ___0_thing, const RuntimeMethod* method) 
{
	{
		int32_t* L_0 = ___0_thing;
		return (void*)(L_0);
	}
}
