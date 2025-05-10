; ModuleID = 'xdp_prog_kern.c'
source_filename = "xdp_prog_kern.c"
target datalayout = "e-m:e-p:64:64-i64:64-i128:128-n32:64-S128"
target triple = "bpf"

%struct.anon = type { [2 x i32]*, i32*, %struct.datarec*, [5 x i32]* }
%struct.datarec = type { i64, i64 }
%struct.xdp_md = type { i32, i32, i32, i32, i32 }

@xdp_stats_map = dso_local global %struct.anon zeroinitializer, section ".maps", align 8, !dbg !0
@_license = dso_local global [4 x i8] c"GPL\00", section "license", align 1, !dbg !18
@llvm.used = appending global [3 x i8*] [i8* getelementptr inbounds ([4 x i8], [4 x i8]* @_license, i32 0, i32 0), i8* bitcast (i32 (%struct.xdp_md*)* @xdp_stats1_func to i8*), i8* bitcast (%struct.anon* @xdp_stats_map to i8*)], section "llvm.metadata"

; Function Attrs: nounwind
define dso_local i32 @xdp_stats1_func(%struct.xdp_md* nocapture readonly %0) #0 section "xdp" !dbg !62 {
  %2 = alloca i32, align 4
  call void @llvm.dbg.value(metadata %struct.xdp_md* %0, metadata !74, metadata !DIExpression()), !dbg !80
  %3 = getelementptr inbounds %struct.xdp_md, %struct.xdp_md* %0, i64 0, i32 1, !dbg !81
  %4 = load i32, i32* %3, align 4, !dbg !81, !tbaa !82
  call void @llvm.dbg.value(metadata i32 %4, metadata !75, metadata !DIExpression(DW_OP_LLVM_convert, 32, DW_ATE_unsigned, DW_OP_LLVM_convert, 64, DW_ATE_unsigned, DW_OP_stack_value)), !dbg !80
  %5 = getelementptr inbounds %struct.xdp_md, %struct.xdp_md* %0, i64 0, i32 0, !dbg !87
  %6 = load i32, i32* %5, align 4, !dbg !87, !tbaa !88
  call void @llvm.dbg.value(metadata i32 %6, metadata !76, metadata !DIExpression(DW_OP_LLVM_convert, 32, DW_ATE_unsigned, DW_OP_LLVM_convert, 64, DW_ATE_unsigned, DW_OP_stack_value)), !dbg !80
  %7 = bitcast i32* %2 to i8*, !dbg !89
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %7) #3, !dbg !89
  call void @llvm.dbg.value(metadata i32 2, metadata !78, metadata !DIExpression()), !dbg !80
  store i32 2, i32* %2, align 4, !dbg !90, !tbaa !91
  call void @llvm.dbg.value(metadata i64 undef, metadata !79, metadata !DIExpression()), !dbg !80
  call void @llvm.dbg.value(metadata i32* %2, metadata !78, metadata !DIExpression(DW_OP_deref)), !dbg !80
  %8 = call i8* inttoptr (i64 1 to i8* (i8*, i8*)*)(i8* bitcast (%struct.anon* @xdp_stats_map to i8*), i8* nonnull %7) #3, !dbg !92
  call void @llvm.dbg.value(metadata i8* %8, metadata !77, metadata !DIExpression()), !dbg !80
  %9 = icmp eq i8* %8, null, !dbg !93
  br i1 %9, label %19, label %10, !dbg !95

10:                                               ; preds = %1
  call void @llvm.dbg.value(metadata i8* %8, metadata !77, metadata !DIExpression()), !dbg !80
  %11 = zext i32 %4 to i64, !dbg !96
  call void @llvm.dbg.value(metadata i64 %11, metadata !75, metadata !DIExpression()), !dbg !80
  %12 = zext i32 %6 to i64, !dbg !97
  call void @llvm.dbg.value(metadata i64 %12, metadata !76, metadata !DIExpression()), !dbg !80
  %13 = sub nsw i64 %11, %12, !dbg !98
  call void @llvm.dbg.value(metadata i64 %13, metadata !79, metadata !DIExpression()), !dbg !80
  %14 = bitcast i8* %8 to i64*, !dbg !99
  %15 = atomicrmw add i64* %14, i64 1 seq_cst, !dbg !99
  %16 = getelementptr inbounds i8, i8* %8, i64 8, !dbg !100
  %17 = bitcast i8* %16 to i64*, !dbg !100
  %18 = atomicrmw add i64* %17, i64 %13 seq_cst, !dbg !100
  br label %19, !dbg !101

19:                                               ; preds = %1, %10
  %20 = phi i32 [ 2, %10 ], [ 0, %1 ], !dbg !80
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %7) #3, !dbg !102
  ret i32 %20, !dbg !102
}

; Function Attrs: argmemonly nounwind willreturn
declare void @llvm.lifetime.start.p0i8(i64 immarg, i8* nocapture) #1

; Function Attrs: argmemonly nounwind willreturn
declare void @llvm.lifetime.end.p0i8(i64 immarg, i8* nocapture) #1

; Function Attrs: nounwind readnone speculatable willreturn
declare void @llvm.dbg.value(metadata, metadata, metadata) #2

attributes #0 = { nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { argmemonly nounwind willreturn }
attributes #2 = { nounwind readnone speculatable willreturn }
attributes #3 = { nounwind }

!llvm.dbg.cu = !{!2}
!llvm.module.flags = !{!58, !59, !60}
!llvm.ident = !{!61}

!0 = !DIGlobalVariableExpression(var: !1, expr: !DIExpression())
!1 = distinct !DIGlobalVariable(name: "xdp_stats_map", scope: !2, file: !3, line: 16, type: !32, isLocal: false, isDefinition: true)
!2 = distinct !DICompileUnit(language: DW_LANG_C99, file: !3, producer: "Ubuntu clang version 11.0.0-2~ubuntu20.04.1", isOptimized: true, runtimeVersion: 0, emissionKind: FullDebug, enums: !4, retainedTypes: !14, globals: !17, splitDebugInlining: false, nameTableKind: None)
!3 = !DIFile(filename: "xdp_prog_kern.c", directory: "/home/nene/xdp-tutorial/basic03-map-counter")
!4 = !{!5}
!5 = !DICompositeType(tag: DW_TAG_enumeration_type, name: "xdp_action", file: !6, line: 3153, baseType: !7, size: 32, elements: !8)
!6 = !DIFile(filename: "/usr/include/linux/bpf.h", directory: "")
!7 = !DIBasicType(name: "unsigned int", size: 32, encoding: DW_ATE_unsigned)
!8 = !{!9, !10, !11, !12, !13}
!9 = !DIEnumerator(name: "XDP_ABORTED", value: 0, isUnsigned: true)
!10 = !DIEnumerator(name: "XDP_DROP", value: 1, isUnsigned: true)
!11 = !DIEnumerator(name: "XDP_PASS", value: 2, isUnsigned: true)
!12 = !DIEnumerator(name: "XDP_TX", value: 3, isUnsigned: true)
!13 = !DIEnumerator(name: "XDP_REDIRECT", value: 4, isUnsigned: true)
!14 = !{!15, !16}
!15 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: null, size: 64)
!16 = !DIBasicType(name: "long int", size: 64, encoding: DW_ATE_signed)
!17 = !{!18, !0, !24}
!18 = !DIGlobalVariableExpression(var: !19, expr: !DIExpression())
!19 = distinct !DIGlobalVariable(name: "_license", scope: !2, file: !3, line: 57, type: !20, isLocal: false, isDefinition: true)
!20 = !DICompositeType(tag: DW_TAG_array_type, baseType: !21, size: 32, elements: !22)
!21 = !DIBasicType(name: "char", size: 8, encoding: DW_ATE_signed_char)
!22 = !{!23}
!23 = !DISubrange(count: 4)
!24 = !DIGlobalVariableExpression(var: !25, expr: !DIExpression())
!25 = distinct !DIGlobalVariable(name: "bpf_map_lookup_elem", scope: !2, file: !26, line: 56, type: !27, isLocal: true, isDefinition: true)
!26 = !DIFile(filename: "../lib/install/include/bpf/bpf_helper_defs.h", directory: "/home/nene/xdp-tutorial/basic03-map-counter")
!27 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !28, size: 64)
!28 = !DISubroutineType(types: !29)
!29 = !{!15, !15, !30}
!30 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !31, size: 64)
!31 = !DIDerivedType(tag: DW_TAG_const_type, baseType: null)
!32 = distinct !DICompositeType(tag: DW_TAG_structure_type, file: !3, line: 11, size: 256, elements: !33)
!33 = !{!34, !40, !44, !53}
!34 = !DIDerivedType(tag: DW_TAG_member, name: "type", scope: !32, file: !3, line: 12, baseType: !35, size: 64)
!35 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !36, size: 64)
!36 = !DICompositeType(tag: DW_TAG_array_type, baseType: !37, size: 64, elements: !38)
!37 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!38 = !{!39}
!39 = !DISubrange(count: 2)
!40 = !DIDerivedType(tag: DW_TAG_member, name: "key", scope: !32, file: !3, line: 13, baseType: !41, size: 64, offset: 64)
!41 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !42, size: 64)
!42 = !DIDerivedType(tag: DW_TAG_typedef, name: "__u32", file: !43, line: 27, baseType: !7)
!43 = !DIFile(filename: "/usr/include/asm-generic/int-ll64.h", directory: "")
!44 = !DIDerivedType(tag: DW_TAG_member, name: "value", scope: !32, file: !3, line: 14, baseType: !45, size: 64, offset: 128)
!45 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !46, size: 64)
!46 = distinct !DICompositeType(tag: DW_TAG_structure_type, name: "datarec", file: !47, line: 8, size: 128, elements: !48)
!47 = !DIFile(filename: "./common_kern_user.h", directory: "/home/nene/xdp-tutorial/basic03-map-counter")
!48 = !{!49, !52}
!49 = !DIDerivedType(tag: DW_TAG_member, name: "rx_packets", scope: !46, file: !47, line: 9, baseType: !50, size: 64)
!50 = !DIDerivedType(tag: DW_TAG_typedef, name: "__u64", file: !43, line: 31, baseType: !51)
!51 = !DIBasicType(name: "long long unsigned int", size: 64, encoding: DW_ATE_unsigned)
!52 = !DIDerivedType(tag: DW_TAG_member, name: "rx_bytes", scope: !46, file: !47, line: 10, baseType: !50, size: 64, offset: 64)
!53 = !DIDerivedType(tag: DW_TAG_member, name: "max_entries", scope: !32, file: !3, line: 15, baseType: !54, size: 64, offset: 192)
!54 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !55, size: 64)
!55 = !DICompositeType(tag: DW_TAG_array_type, baseType: !37, size: 160, elements: !56)
!56 = !{!57}
!57 = !DISubrange(count: 5)
!58 = !{i32 7, !"Dwarf Version", i32 4}
!59 = !{i32 2, !"Debug Info Version", i32 3}
!60 = !{i32 1, !"wchar_size", i32 4}
!61 = !{!"Ubuntu clang version 11.0.0-2~ubuntu20.04.1"}
!62 = distinct !DISubprogram(name: "xdp_stats1_func", scope: !3, file: !3, line: 26, type: !63, scopeLine: 27, flags: DIFlagPrototyped | DIFlagAllCallsDescribed, spFlags: DISPFlagDefinition | DISPFlagOptimized, unit: !2, retainedNodes: !73)
!63 = !DISubroutineType(types: !64)
!64 = !{!37, !65}
!65 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !66, size: 64)
!66 = distinct !DICompositeType(tag: DW_TAG_structure_type, name: "xdp_md", file: !6, line: 3164, size: 160, elements: !67)
!67 = !{!68, !69, !70, !71, !72}
!68 = !DIDerivedType(tag: DW_TAG_member, name: "data", scope: !66, file: !6, line: 3165, baseType: !42, size: 32)
!69 = !DIDerivedType(tag: DW_TAG_member, name: "data_end", scope: !66, file: !6, line: 3166, baseType: !42, size: 32, offset: 32)
!70 = !DIDerivedType(tag: DW_TAG_member, name: "data_meta", scope: !66, file: !6, line: 3167, baseType: !42, size: 32, offset: 64)
!71 = !DIDerivedType(tag: DW_TAG_member, name: "ingress_ifindex", scope: !66, file: !6, line: 3169, baseType: !42, size: 32, offset: 96)
!72 = !DIDerivedType(tag: DW_TAG_member, name: "rx_queue_index", scope: !66, file: !6, line: 3170, baseType: !42, size: 32, offset: 128)
!73 = !{!74, !75, !76, !77, !78, !79}
!74 = !DILocalVariable(name: "ctx", arg: 1, scope: !62, file: !3, line: 26, type: !65)
!75 = !DILocalVariable(name: "data_end", scope: !62, file: !3, line: 28, type: !15)
!76 = !DILocalVariable(name: "data", scope: !62, file: !3, line: 29, type: !15)
!77 = !DILocalVariable(name: "rec", scope: !62, file: !3, line: 30, type: !45)
!78 = !DILocalVariable(name: "key", scope: !62, file: !3, line: 31, type: !42)
!79 = !DILocalVariable(name: "bytes", scope: !62, file: !3, line: 32, type: !50)
!80 = !DILocation(line: 0, scope: !62)
!81 = !DILocation(line: 28, column: 38, scope: !62)
!82 = !{!83, !84, i64 4}
!83 = !{!"xdp_md", !84, i64 0, !84, i64 4, !84, i64 8, !84, i64 12, !84, i64 16}
!84 = !{!"int", !85, i64 0}
!85 = !{!"omnipotent char", !86, i64 0}
!86 = !{!"Simple C/C++ TBAA"}
!87 = !DILocation(line: 29, column: 38, scope: !62)
!88 = !{!83, !84, i64 0}
!89 = !DILocation(line: 31, column: 2, scope: !62)
!90 = !DILocation(line: 31, column: 8, scope: !62)
!91 = !{!84, !84, i64 0}
!92 = !DILocation(line: 34, column: 8, scope: !62)
!93 = !DILocation(line: 39, column: 7, scope: !94)
!94 = distinct !DILexicalBlock(scope: !62, file: !3, line: 39, column: 6)
!95 = !DILocation(line: 39, column: 6, scope: !62)
!96 = !DILocation(line: 28, column: 27, scope: !62)
!97 = !DILocation(line: 29, column: 27, scope: !62)
!98 = !DILocation(line: 32, column: 25, scope: !62)
!99 = !DILocation(line: 45, column: 2, scope: !62)
!100 = !DILocation(line: 46, column: 2, scope: !62)
!101 = !DILocation(line: 54, column: 2, scope: !62)
!102 = !DILocation(line: 55, column: 1, scope: !62)
