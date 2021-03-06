// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <xnnpack/common.h>


// Table of exp2(k / 2048) values decremented (as integer) by (k << 12), k = 0..2047
XNN_INTERNAL const float xnn_table_exp2minus_k_over_2048[2048] = {
  0x1.000000p+0, 0x1.FFF630p-1, 0x1.FFEC60p-1, 0x1.FFE294p-1,
  0x1.FFD8C8p-1, 0x1.FFCF00p-1, 0x1.FFC538p-1, 0x1.FFBB72p-1,
  0x1.FFB1B0p-1, 0x1.FFA7EEp-1, 0x1.FF9E2Ep-1, 0x1.FF9472p-1,
  0x1.FF8AB6p-1, 0x1.FF80FCp-1, 0x1.FF7744p-1, 0x1.FF6D8Ep-1,
  0x1.FF63DAp-1, 0x1.FF5A28p-1, 0x1.FF5078p-1, 0x1.FF46CAp-1,
  0x1.FF3D1Ep-1, 0x1.FF3374p-1, 0x1.FF29CCp-1, 0x1.FF2026p-1,
  0x1.FF1682p-1, 0x1.FF0CDEp-1, 0x1.FF033Ep-1, 0x1.FEF9A0p-1,
  0x1.FEF004p-1, 0x1.FEE668p-1, 0x1.FEDCD0p-1, 0x1.FED338p-1,
  0x1.FEC9A4p-1, 0x1.FEC010p-1, 0x1.FEB680p-1, 0x1.FEACF0p-1,
  0x1.FEA364p-1, 0x1.FE99D8p-1, 0x1.FE9050p-1, 0x1.FE86C8p-1,
  0x1.FE7D42p-1, 0x1.FE73C0p-1, 0x1.FE6A3Ep-1, 0x1.FE60BEp-1,
  0x1.FE5742p-1, 0x1.FE4DC6p-1, 0x1.FE444Cp-1, 0x1.FE3AD4p-1,
  0x1.FE315Ep-1, 0x1.FE27EAp-1, 0x1.FE1E78p-1, 0x1.FE150Ap-1,
  0x1.FE0B9Cp-1, 0x1.FE0230p-1, 0x1.FDF8C6p-1, 0x1.FDEF5Ep-1,
  0x1.FDE5F8p-1, 0x1.FDDC94p-1, 0x1.FDD330p-1, 0x1.FDC9D0p-1,
  0x1.FDC072p-1, 0x1.FDB716p-1, 0x1.FDADBCp-1, 0x1.FDA464p-1,
  0x1.FD9B0Ep-1, 0x1.FD91B8p-1, 0x1.FD8866p-1, 0x1.FD7F16p-1,
  0x1.FD75C8p-1, 0x1.FD6C7Ap-1, 0x1.FD6330p-1, 0x1.FD59E8p-1,
  0x1.FD50A0p-1, 0x1.FD475Cp-1, 0x1.FD3E1Ap-1, 0x1.FD34D8p-1,
  0x1.FD2B9Ap-1, 0x1.FD225Ep-1, 0x1.FD1922p-1, 0x1.FD0FEAp-1,
  0x1.FD06B2p-1, 0x1.FCFD7Ep-1, 0x1.FCF44Ap-1, 0x1.FCEB1Ap-1,
  0x1.FCE1EAp-1, 0x1.FCD8BEp-1, 0x1.FCCF92p-1, 0x1.FCC66Ap-1,
  0x1.FCBD42p-1, 0x1.FCB41Ep-1, 0x1.FCAAFAp-1, 0x1.FCA1DAp-1,
  0x1.FC98BAp-1, 0x1.FC8F9Ep-1, 0x1.FC8682p-1, 0x1.FC7D68p-1,
  0x1.FC7452p-1, 0x1.FC6B3Cp-1, 0x1.FC622Ap-1, 0x1.FC5918p-1,
  0x1.FC5008p-1, 0x1.FC46FCp-1, 0x1.FC3DF0p-1, 0x1.FC34E6p-1,
  0x1.FC2BE0p-1, 0x1.FC22DAp-1, 0x1.FC19D6p-1, 0x1.FC10D6p-1,
  0x1.FC07D6p-1, 0x1.FBFED8p-1, 0x1.FBF5DEp-1, 0x1.FBECE4p-1,
  0x1.FBE3ECp-1, 0x1.FBDAF8p-1, 0x1.FBD204p-1, 0x1.FBC912p-1,
  0x1.FBC024p-1, 0x1.FBB736p-1, 0x1.FBAE4Ap-1, 0x1.FBA562p-1,
  0x1.FB9C7Ap-1, 0x1.FB9394p-1, 0x1.FB8AB0p-1, 0x1.FB81D0p-1,
  0x1.FB78F0p-1, 0x1.FB7012p-1, 0x1.FB6738p-1, 0x1.FB5E5Ep-1,
  0x1.FB5586p-1, 0x1.FB4CB2p-1, 0x1.FB43DEp-1, 0x1.FB3B0Cp-1,
  0x1.FB323Ep-1, 0x1.FB2970p-1, 0x1.FB20A4p-1, 0x1.FB17DCp-1,
  0x1.FB0F14p-1, 0x1.FB0650p-1, 0x1.FAFD8Cp-1, 0x1.FAF4CAp-1,
  0x1.FAEC0Cp-1, 0x1.FAE34Ep-1, 0x1.FADA94p-1, 0x1.FAD1DAp-1,
  0x1.FAC922p-1, 0x1.FAC06Ep-1, 0x1.FAB7BAp-1, 0x1.FAAF0Ap-1,
  0x1.FAA65Ap-1, 0x1.FA9DAEp-1, 0x1.FA9502p-1, 0x1.FA8C5Ap-1,
  0x1.FA83B2p-1, 0x1.FA7B0Ep-1, 0x1.FA726Ap-1, 0x1.FA69CAp-1,
  0x1.FA612Ap-1, 0x1.FA588Ep-1, 0x1.FA4FF2p-1, 0x1.FA475Ap-1,
  0x1.FA3EC4p-1, 0x1.FA362Ep-1, 0x1.FA2D9Cp-1, 0x1.FA250Ap-1,
  0x1.FA1C7Cp-1, 0x1.FA13F0p-1, 0x1.FA0B66p-1, 0x1.FA02DCp-1,
  0x1.F9FA56p-1, 0x1.F9F1D2p-1, 0x1.F9E950p-1, 0x1.F9E0CEp-1,
  0x1.F9D850p-1, 0x1.F9CFD4p-1, 0x1.F9C75Ap-1, 0x1.F9BEE2p-1,
  0x1.F9B66Ap-1, 0x1.F9ADF6p-1, 0x1.F9A584p-1, 0x1.F99D14p-1,
  0x1.F994A6p-1, 0x1.F98C3Ap-1, 0x1.F983D0p-1, 0x1.F97B68p-1,
  0x1.F97302p-1, 0x1.F96A9Ep-1, 0x1.F9623Cp-1, 0x1.F959DEp-1,
  0x1.F95180p-1, 0x1.F94924p-1, 0x1.F940CAp-1, 0x1.F93872p-1,
  0x1.F9301Ep-1, 0x1.F927CAp-1, 0x1.F91F78p-1, 0x1.F91728p-1,
  0x1.F90EDCp-1, 0x1.F90690p-1, 0x1.F8FE46p-1, 0x1.F8F600p-1,
  0x1.F8EDBAp-1, 0x1.F8E578p-1, 0x1.F8DD36p-1, 0x1.F8D4F8p-1,
  0x1.F8CCBAp-1, 0x1.F8C480p-1, 0x1.F8BC48p-1, 0x1.F8B410p-1,
  0x1.F8ABDCp-1, 0x1.F8A3AAp-1, 0x1.F89B78p-1, 0x1.F8934Ap-1,
  0x1.F88B1Ep-1, 0x1.F882F4p-1, 0x1.F87ACCp-1, 0x1.F872A6p-1,
  0x1.F86A82p-1, 0x1.F86260p-1, 0x1.F85A40p-1, 0x1.F85222p-1,
  0x1.F84A06p-1, 0x1.F841ECp-1, 0x1.F839D4p-1, 0x1.F831BEp-1,
  0x1.F829AAp-1, 0x1.F8219Ap-1, 0x1.F8198Ap-1, 0x1.F8117Cp-1,
  0x1.F80972p-1, 0x1.F80168p-1, 0x1.F7F962p-1, 0x1.F7F15Cp-1,
  0x1.F7E95Ap-1, 0x1.F7E158p-1, 0x1.F7D95Ap-1, 0x1.F7D15Cp-1,
  0x1.F7C962p-1, 0x1.F7C16Ap-1, 0x1.F7B974p-1, 0x1.F7B17Ep-1,
  0x1.F7A98Cp-1, 0x1.F7A19Cp-1, 0x1.F799AEp-1, 0x1.F791C2p-1,
  0x1.F789D8p-1, 0x1.F781F0p-1, 0x1.F77A0Ap-1, 0x1.F77226p-1,
  0x1.F76A46p-1, 0x1.F76266p-1, 0x1.F75A88p-1, 0x1.F752AEp-1,
  0x1.F74AD4p-1, 0x1.F742FCp-1, 0x1.F73B28p-1, 0x1.F73354p-1,
  0x1.F72B84p-1, 0x1.F723B6p-1, 0x1.F71BE8p-1, 0x1.F7141Ep-1,
  0x1.F70C56p-1, 0x1.F7048Ep-1, 0x1.F6FCCAp-1, 0x1.F6F508p-1,
  0x1.F6ED48p-1, 0x1.F6E58Ap-1, 0x1.F6DDCEp-1, 0x1.F6D614p-1,
  0x1.F6CE5Ep-1, 0x1.F6C6A8p-1, 0x1.F6BEF4p-1, 0x1.F6B742p-1,
  0x1.F6AF94p-1, 0x1.F6A7E6p-1, 0x1.F6A03Cp-1, 0x1.F69892p-1,
  0x1.F690ECp-1, 0x1.F68946p-1, 0x1.F681A4p-1, 0x1.F67A04p-1,
  0x1.F67266p-1, 0x1.F66ACAp-1, 0x1.F66330p-1, 0x1.F65B98p-1,
  0x1.F65402p-1, 0x1.F64C6Ep-1, 0x1.F644DCp-1, 0x1.F63D4Cp-1,
  0x1.F635BEp-1, 0x1.F62E34p-1, 0x1.F626AAp-1, 0x1.F61F24p-1,
  0x1.F6179Ep-1, 0x1.F6101Cp-1, 0x1.F6089Ap-1, 0x1.F6011Cp-1,
  0x1.F5F9A0p-1, 0x1.F5F226p-1, 0x1.F5EAACp-1, 0x1.F5E336p-1,
  0x1.F5DBC2p-1, 0x1.F5D452p-1, 0x1.F5CCE2p-1, 0x1.F5C574p-1,
  0x1.F5BE08p-1, 0x1.F5B69Ep-1, 0x1.F5AF38p-1, 0x1.F5A7D2p-1,
  0x1.F5A070p-1, 0x1.F5990Ep-1, 0x1.F591B0p-1, 0x1.F58A54p-1,
  0x1.F582FAp-1, 0x1.F57BA2p-1, 0x1.F5744Ap-1, 0x1.F56CF6p-1,
  0x1.F565A6p-1, 0x1.F55E56p-1, 0x1.F55708p-1, 0x1.F54FBCp-1,
  0x1.F54874p-1, 0x1.F5412Cp-1, 0x1.F539E6p-1, 0x1.F532A4p-1,
  0x1.F52B64p-1, 0x1.F52424p-1, 0x1.F51CE8p-1, 0x1.F515AEp-1,
  0x1.F50E76p-1, 0x1.F50740p-1, 0x1.F5000Cp-1, 0x1.F4F8DAp-1,
  0x1.F4F1AAp-1, 0x1.F4EA7Ep-1, 0x1.F4E352p-1, 0x1.F4DC2Ap-1,
  0x1.F4D502p-1, 0x1.F4CDDEp-1, 0x1.F4C6BAp-1, 0x1.F4BF9Ap-1,
  0x1.F4B87Cp-1, 0x1.F4B160p-1, 0x1.F4AA46p-1, 0x1.F4A32Ep-1,
  0x1.F49C18p-1, 0x1.F49504p-1, 0x1.F48DF4p-1, 0x1.F486E4p-1,
  0x1.F47FD8p-1, 0x1.F478CCp-1, 0x1.F471C4p-1, 0x1.F46ABCp-1,
  0x1.F463B8p-1, 0x1.F45CB6p-1, 0x1.F455B6p-1, 0x1.F44EB8p-1,
  0x1.F447BCp-1, 0x1.F440C4p-1, 0x1.F439CCp-1, 0x1.F432D6p-1,
  0x1.F42BE4p-1, 0x1.F424F2p-1, 0x1.F41E04p-1, 0x1.F41718p-1,
  0x1.F4102Cp-1, 0x1.F40944p-1, 0x1.F4025Ep-1, 0x1.F3FB7Ap-1,
  0x1.F3F49Ap-1, 0x1.F3EDBAp-1, 0x1.F3E6DCp-1, 0x1.F3E002p-1,
  0x1.F3D928p-1, 0x1.F3D252p-1, 0x1.F3CB7Cp-1, 0x1.F3C4AAp-1,
  0x1.F3BDDAp-1, 0x1.F3B70Cp-1, 0x1.F3B040p-1, 0x1.F3A976p-1,
  0x1.F3A2B0p-1, 0x1.F39BEAp-1, 0x1.F39526p-1, 0x1.F38E66p-1,
  0x1.F387A6p-1, 0x1.F380EAp-1, 0x1.F37A30p-1, 0x1.F37378p-1,
  0x1.F36CC2p-1, 0x1.F3660Ep-1, 0x1.F35F5Cp-1, 0x1.F358ACp-1,
  0x1.F35200p-1, 0x1.F34B54p-1, 0x1.F344ACp-1, 0x1.F33E06p-1,
  0x1.F33760p-1, 0x1.F330BEp-1, 0x1.F32A1Ep-1, 0x1.F32380p-1,
  0x1.F31CE4p-1, 0x1.F3164Cp-1, 0x1.F30FB4p-1, 0x1.F30920p-1,
  0x1.F3028Cp-1, 0x1.F2FBFCp-1, 0x1.F2F56Ep-1, 0x1.F2EEE2p-1,
  0x1.F2E858p-1, 0x1.F2E1D0p-1, 0x1.F2DB4Ap-1, 0x1.F2D4C6p-1,
  0x1.F2CE46p-1, 0x1.F2C7C6p-1, 0x1.F2C14Ap-1, 0x1.F2BACEp-1,
  0x1.F2B456p-1, 0x1.F2ADE0p-1, 0x1.F2A76Cp-1, 0x1.F2A0FAp-1,
  0x1.F29A8Cp-1, 0x1.F2941Ep-1, 0x1.F28DB2p-1, 0x1.F2874Ap-1,
  0x1.F280E4p-1, 0x1.F27A7Ep-1, 0x1.F2741Cp-1, 0x1.F26DBCp-1,
  0x1.F2675Ep-1, 0x1.F26104p-1, 0x1.F25AAAp-1, 0x1.F25452p-1,
  0x1.F24DFEp-1, 0x1.F247ACp-1, 0x1.F2415Cp-1, 0x1.F23B0Cp-1,
  0x1.F234C0p-1, 0x1.F22E78p-1, 0x1.F22830p-1, 0x1.F221EAp-1,
  0x1.F21BA8p-1, 0x1.F21566p-1, 0x1.F20F28p-1, 0x1.F208ECp-1,
  0x1.F202B2p-1, 0x1.F1FC7Ap-1, 0x1.F1F644p-1, 0x1.F1F010p-1,
  0x1.F1E9E0p-1, 0x1.F1E3B0p-1, 0x1.F1DD84p-1, 0x1.F1D75Ap-1,
  0x1.F1D130p-1, 0x1.F1CB0Ap-1, 0x1.F1C4E8p-1, 0x1.F1BEC6p-1,
  0x1.F1B8A6p-1, 0x1.F1B28Ap-1, 0x1.F1AC6Ep-1, 0x1.F1A656p-1,
  0x1.F1A040p-1, 0x1.F19A2Cp-1, 0x1.F1941Ap-1, 0x1.F18E0Ap-1,
  0x1.F187FEp-1, 0x1.F181F2p-1, 0x1.F17BEAp-1, 0x1.F175E2p-1,
  0x1.F16FDEp-1, 0x1.F169DCp-1, 0x1.F163DCp-1, 0x1.F15DDEp-1,
  0x1.F157E4p-1, 0x1.F151EAp-1, 0x1.F14BF4p-1, 0x1.F14600p-1,
  0x1.F1400Cp-1, 0x1.F13A1Cp-1, 0x1.F13430p-1, 0x1.F12E44p-1,
  0x1.F1285Ap-1, 0x1.F12274p-1, 0x1.F11C8Ep-1, 0x1.F116ACp-1,
  0x1.F110CCp-1, 0x1.F10AEEp-1, 0x1.F10512p-1, 0x1.F0FF3Ap-1,
  0x1.F0F962p-1, 0x1.F0F38Ep-1, 0x1.F0EDBAp-1, 0x1.F0E7EAp-1,
  0x1.F0E21Cp-1, 0x1.F0DC50p-1, 0x1.F0D686p-1, 0x1.F0D0C0p-1,
  0x1.F0CAFAp-1, 0x1.F0C538p-1, 0x1.F0BF78p-1, 0x1.F0B9BAp-1,
  0x1.F0B3FEp-1, 0x1.F0AE44p-1, 0x1.F0A88Cp-1, 0x1.F0A2D8p-1,
  0x1.F09D24p-1, 0x1.F09774p-1, 0x1.F091C6p-1, 0x1.F08C1Ap-1,
  0x1.F08670p-1, 0x1.F080CAp-1, 0x1.F07B24p-1, 0x1.F07582p-1,
  0x1.F06FE0p-1, 0x1.F06A42p-1, 0x1.F064A6p-1, 0x1.F05F0Cp-1,
  0x1.F05976p-1, 0x1.F053E0p-1, 0x1.F04E4Ep-1, 0x1.F048BEp-1,
  0x1.F0432Ep-1, 0x1.F03DA2p-1, 0x1.F0381Ap-1, 0x1.F03292p-1,
  0x1.F02D0Cp-1, 0x1.F0278Ap-1, 0x1.F0220Ap-1, 0x1.F01C8Cp-1,
  0x1.F01710p-1, 0x1.F01196p-1, 0x1.F00C1Ep-1, 0x1.F006AAp-1,
  0x1.F00138p-1, 0x1.EFFBC6p-1, 0x1.EFF658p-1, 0x1.EFF0EEp-1,
  0x1.EFEB84p-1, 0x1.EFE61Cp-1, 0x1.EFE0B8p-1, 0x1.EFDB56p-1,
  0x1.EFD5F4p-1, 0x1.EFD098p-1, 0x1.EFCB3Cp-1, 0x1.EFC5E2p-1,
  0x1.EFC08Cp-1, 0x1.EFBB36p-1, 0x1.EFB5E4p-1, 0x1.EFB094p-1,
  0x1.EFAB46p-1, 0x1.EFA5FAp-1, 0x1.EFA0B2p-1, 0x1.EF9B6Ap-1,
  0x1.EF9626p-1, 0x1.EF90E4p-1, 0x1.EF8BA4p-1, 0x1.EF8666p-1,
  0x1.EF812Cp-1, 0x1.EF7BF2p-1, 0x1.EF76BCp-1, 0x1.EF7188p-1,
  0x1.EF6C56p-1, 0x1.EF6726p-1, 0x1.EF61FAp-1, 0x1.EF5CCEp-1,
  0x1.EF57A6p-1, 0x1.EF5280p-1, 0x1.EF4D5Cp-1, 0x1.EF483Ap-1,
  0x1.EF431Ap-1, 0x1.EF3DFEp-1, 0x1.EF38E2p-1, 0x1.EF33CAp-1,
  0x1.EF2EB4p-1, 0x1.EF29A0p-1, 0x1.EF2490p-1, 0x1.EF1F80p-1,
  0x1.EF1A74p-1, 0x1.EF156Ap-1, 0x1.EF1062p-1, 0x1.EF0B5Cp-1,
  0x1.EF0658p-1, 0x1.EF0158p-1, 0x1.EEFC58p-1, 0x1.EEF75Cp-1,
  0x1.EEF262p-1, 0x1.EEED6Ap-1, 0x1.EEE876p-1, 0x1.EEE382p-1,
  0x1.EEDE92p-1, 0x1.EED9A4p-1, 0x1.EED4B8p-1, 0x1.EECFCEp-1,
  0x1.EECAE6p-1, 0x1.EEC602p-1, 0x1.EEC120p-1, 0x1.EEBC40p-1,
  0x1.EEB762p-1, 0x1.EEB286p-1, 0x1.EEADACp-1, 0x1.EEA8D6p-1,
  0x1.EEA402p-1, 0x1.EE9F30p-1, 0x1.EE9A60p-1, 0x1.EE9592p-1,
  0x1.EE90C8p-1, 0x1.EE8C00p-1, 0x1.EE8738p-1, 0x1.EE8274p-1,
  0x1.EE7DB4p-1, 0x1.EE78F4p-1, 0x1.EE7438p-1, 0x1.EE6F7Cp-1,
  0x1.EE6AC4p-1, 0x1.EE6610p-1, 0x1.EE615Cp-1, 0x1.EE5CAAp-1,
  0x1.EE57FCp-1, 0x1.EE5350p-1, 0x1.EE4EA6p-1, 0x1.EE49FEp-1,
  0x1.EE455Ap-1, 0x1.EE40B6p-1, 0x1.EE3C16p-1, 0x1.EE3778p-1,
  0x1.EE32DCp-1, 0x1.EE2E42p-1, 0x1.EE29ACp-1, 0x1.EE2518p-1,
  0x1.EE2086p-1, 0x1.EE1BF6p-1, 0x1.EE1768p-1, 0x1.EE12DCp-1,
  0x1.EE0E54p-1, 0x1.EE09CEp-1, 0x1.EE054Ap-1, 0x1.EE00C8p-1,
  0x1.EDFC4Ap-1, 0x1.EDF7CCp-1, 0x1.EDF352p-1, 0x1.EDEEDAp-1,
  0x1.EDEA64p-1, 0x1.EDE5F2p-1, 0x1.EDE180p-1, 0x1.EDDD12p-1,
  0x1.EDD8A6p-1, 0x1.EDD43Cp-1, 0x1.EDCFD6p-1, 0x1.EDCB70p-1,
  0x1.EDC70Ep-1, 0x1.EDC2AEp-1, 0x1.EDBE50p-1, 0x1.EDB9F4p-1,
  0x1.EDB59Cp-1, 0x1.EDB146p-1, 0x1.EDACF2p-1, 0x1.EDA8A0p-1,
  0x1.EDA450p-1, 0x1.EDA004p-1, 0x1.ED9BB8p-1, 0x1.ED9770p-1,
  0x1.ED932Cp-1, 0x1.ED8EE8p-1, 0x1.ED8AA6p-1, 0x1.ED8668p-1,
  0x1.ED822Cp-1, 0x1.ED7DF2p-1, 0x1.ED79BCp-1, 0x1.ED7586p-1,
  0x1.ED7154p-1, 0x1.ED6D24p-1, 0x1.ED68F6p-1, 0x1.ED64CAp-1,
  0x1.ED60A2p-1, 0x1.ED5C7Cp-1, 0x1.ED5858p-1, 0x1.ED5436p-1,
  0x1.ED5016p-1, 0x1.ED4BFAp-1, 0x1.ED47E0p-1, 0x1.ED43C8p-1,
  0x1.ED3FB2p-1, 0x1.ED3BA0p-1, 0x1.ED378Ep-1, 0x1.ED3380p-1,
  0x1.ED2F74p-1, 0x1.ED2B6Cp-1, 0x1.ED2764p-1, 0x1.ED2360p-1,
  0x1.ED1F5Ep-1, 0x1.ED1B5Ep-1, 0x1.ED1760p-1, 0x1.ED1366p-1,
  0x1.ED0F6Ep-1, 0x1.ED0B78p-1, 0x1.ED0784p-1, 0x1.ED0392p-1,
  0x1.ECFFA4p-1, 0x1.ECFBB8p-1, 0x1.ECF7CEp-1, 0x1.ECF3E6p-1,
  0x1.ECF002p-1, 0x1.ECEC1Ep-1, 0x1.ECE83Ep-1, 0x1.ECE462p-1,
  0x1.ECE086p-1, 0x1.ECDCAEp-1, 0x1.ECD8D6p-1, 0x1.ECD504p-1,
  0x1.ECD132p-1, 0x1.ECCD62p-1, 0x1.ECC996p-1, 0x1.ECC5CCp-1,
  0x1.ECC204p-1, 0x1.ECBE3Ep-1, 0x1.ECBA7Cp-1, 0x1.ECB6BCp-1,
  0x1.ECB2FEp-1, 0x1.ECAF42p-1, 0x1.ECAB8Ap-1, 0x1.ECA7D2p-1,
  0x1.ECA41Ep-1, 0x1.ECA06Ep-1, 0x1.EC9CBEp-1, 0x1.EC9912p-1,
  0x1.EC9566p-1, 0x1.EC91C0p-1, 0x1.EC8E1Ap-1, 0x1.EC8A76p-1,
  0x1.EC86D6p-1, 0x1.EC8338p-1, 0x1.EC7F9Cp-1, 0x1.EC7C04p-1,
  0x1.EC786Ep-1, 0x1.EC74DAp-1, 0x1.EC7148p-1, 0x1.EC6DB8p-1,
  0x1.EC6A2Cp-1, 0x1.EC66A2p-1, 0x1.EC631Ap-1, 0x1.EC5F94p-1,
  0x1.EC5C10p-1, 0x1.EC5890p-1, 0x1.EC5512p-1, 0x1.EC5198p-1,
  0x1.EC4E1Ep-1, 0x1.EC4AA8p-1, 0x1.EC4734p-1, 0x1.EC43C2p-1,
  0x1.EC4052p-1, 0x1.EC3CE6p-1, 0x1.EC397Cp-1, 0x1.EC3614p-1,
  0x1.EC32B0p-1, 0x1.EC2F4Cp-1, 0x1.EC2BECp-1, 0x1.EC288Ep-1,
  0x1.EC2532p-1, 0x1.EC21DAp-1, 0x1.EC1E84p-1, 0x1.EC1B30p-1,
  0x1.EC17DEp-1, 0x1.EC1490p-1, 0x1.EC1144p-1, 0x1.EC0DFAp-1,
  0x1.EC0AB2p-1, 0x1.EC076Ep-1, 0x1.EC042Ap-1, 0x1.EC00EAp-1,
  0x1.EBFDAEp-1, 0x1.EBFA72p-1, 0x1.EBF73Ap-1, 0x1.EBF404p-1,
  0x1.EBF0D0p-1, 0x1.EBEDA0p-1, 0x1.EBEA70p-1, 0x1.EBE744p-1,
  0x1.EBE41Cp-1, 0x1.EBE0F4p-1, 0x1.EBDDD0p-1, 0x1.EBDAAEp-1,
  0x1.EBD78Ep-1, 0x1.EBD472p-1, 0x1.EBD158p-1, 0x1.EBCE40p-1,
  0x1.EBCB2Ap-1, 0x1.EBC816p-1, 0x1.EBC506p-1, 0x1.EBC1F8p-1,
  0x1.EBBEECp-1, 0x1.EBBBE4p-1, 0x1.EBB8DEp-1, 0x1.EBB5DAp-1,
  0x1.EBB2D8p-1, 0x1.EBAFDAp-1, 0x1.EBACDCp-1, 0x1.EBA9E2p-1,
  0x1.EBA6ECp-1, 0x1.EBA3F6p-1, 0x1.EBA104p-1, 0x1.EB9E14p-1,
  0x1.EB9B28p-1, 0x1.EB983Cp-1, 0x1.EB9554p-1, 0x1.EB926Ep-1,
  0x1.EB8F8Cp-1, 0x1.EB8CAAp-1, 0x1.EB89CCp-1, 0x1.EB86F2p-1,
  0x1.EB8418p-1, 0x1.EB8142p-1, 0x1.EB7E6Ep-1, 0x1.EB7B9Cp-1,
  0x1.EB78CCp-1, 0x1.EB7600p-1, 0x1.EB7336p-1, 0x1.EB7070p-1,
  0x1.EB6DAAp-1, 0x1.EB6AE8p-1, 0x1.EB6828p-1, 0x1.EB656Ap-1,
  0x1.EB62B0p-1, 0x1.EB5FF8p-1, 0x1.EB5D42p-1, 0x1.EB5A90p-1,
  0x1.EB57DEp-1, 0x1.EB5530p-1, 0x1.EB5284p-1, 0x1.EB4FDCp-1,
  0x1.EB4D36p-1, 0x1.EB4A92p-1, 0x1.EB47F0p-1, 0x1.EB4552p-1,
  0x1.EB42B6p-1, 0x1.EB401Cp-1, 0x1.EB3D84p-1, 0x1.EB3AF0p-1,
  0x1.EB385Ep-1, 0x1.EB35CEp-1, 0x1.EB3342p-1, 0x1.EB30B8p-1,
  0x1.EB2E30p-1, 0x1.EB2BAAp-1, 0x1.EB2928p-1, 0x1.EB26A8p-1,
  0x1.EB242Ap-1, 0x1.EB21AEp-1, 0x1.EB1F36p-1, 0x1.EB1CC0p-1,
  0x1.EB1A4Cp-1, 0x1.EB17DCp-1, 0x1.EB156Ep-1, 0x1.EB1302p-1,
  0x1.EB1098p-1, 0x1.EB0E32p-1, 0x1.EB0BCEp-1, 0x1.EB096Cp-1,
  0x1.EB070Ep-1, 0x1.EB04B2p-1, 0x1.EB0258p-1, 0x1.EB0000p-1,
  0x1.EAFDACp-1, 0x1.EAFB5Ap-1, 0x1.EAF90Ap-1, 0x1.EAF6BEp-1,
  0x1.EAF474p-1, 0x1.EAF22Cp-1, 0x1.EAEFE6p-1, 0x1.EAEDA4p-1,
  0x1.EAEB64p-1, 0x1.EAE926p-1, 0x1.EAE6ECp-1, 0x1.EAE4B4p-1,
  0x1.EAE27Ep-1, 0x1.EAE04Ap-1, 0x1.EADE1Ap-1, 0x1.EADBECp-1,
  0x1.EAD9C0p-1, 0x1.EAD798p-1, 0x1.EAD572p-1, 0x1.EAD34Ep-1,
  0x1.EAD12Ep-1, 0x1.EACF0Ep-1, 0x1.EACCF4p-1, 0x1.EACADAp-1,
  0x1.EAC8C4p-1, 0x1.EAC6B0p-1, 0x1.EAC49Ep-1, 0x1.EAC28Ep-1,
  0x1.EAC082p-1, 0x1.EABE78p-1, 0x1.EABC72p-1, 0x1.EABA6Ep-1,
  0x1.EAB86Cp-1, 0x1.EAB66Cp-1, 0x1.EAB470p-1, 0x1.EAB276p-1,
  0x1.EAB07Ep-1, 0x1.EAAE88p-1, 0x1.EAAC96p-1, 0x1.EAAAA6p-1,
  0x1.EAA8BAp-1, 0x1.EAA6D0p-1, 0x1.EAA4E8p-1, 0x1.EAA302p-1,
  0x1.EAA120p-1, 0x1.EA9F40p-1, 0x1.EA9D62p-1, 0x1.EA9B88p-1,
  0x1.EA99B0p-1, 0x1.EA97DAp-1, 0x1.EA9606p-1, 0x1.EA9436p-1,
  0x1.EA9268p-1, 0x1.EA909Ep-1, 0x1.EA8ED6p-1, 0x1.EA8D10p-1,
  0x1.EA8B4Cp-1, 0x1.EA898Cp-1, 0x1.EA87CEp-1, 0x1.EA8612p-1,
  0x1.EA845Ap-1, 0x1.EA82A2p-1, 0x1.EA80F0p-1, 0x1.EA7F3Ep-1,
  0x1.EA7D90p-1, 0x1.EA7BE4p-1, 0x1.EA7A3Cp-1, 0x1.EA7896p-1,
  0x1.EA76F2p-1, 0x1.EA7550p-1, 0x1.EA73B2p-1, 0x1.EA7216p-1,
  0x1.EA707Cp-1, 0x1.EA6EE6p-1, 0x1.EA6D52p-1, 0x1.EA6BC0p-1,
  0x1.EA6A32p-1, 0x1.EA68A6p-1, 0x1.EA671Cp-1, 0x1.EA6596p-1,
  0x1.EA6412p-1, 0x1.EA6290p-1, 0x1.EA6112p-1, 0x1.EA5F96p-1,
  0x1.EA5E1Cp-1, 0x1.EA5CA4p-1, 0x1.EA5B30p-1, 0x1.EA59BEp-1,
  0x1.EA5850p-1, 0x1.EA56E4p-1, 0x1.EA557Ap-1, 0x1.EA5412p-1,
  0x1.EA52AEp-1, 0x1.EA514Cp-1, 0x1.EA4FEEp-1, 0x1.EA4E92p-1,
  0x1.EA4D38p-1, 0x1.EA4BE0p-1, 0x1.EA4A8Cp-1, 0x1.EA493Ap-1,
  0x1.EA47ECp-1, 0x1.EA469Ep-1, 0x1.EA4554p-1, 0x1.EA440Ep-1,
  0x1.EA42CAp-1, 0x1.EA4188p-1, 0x1.EA4048p-1, 0x1.EA3F0Cp-1,
  0x1.EA3DD2p-1, 0x1.EA3C9Ap-1, 0x1.EA3B66p-1, 0x1.EA3A34p-1,
  0x1.EA3906p-1, 0x1.EA37D8p-1, 0x1.EA36AEp-1, 0x1.EA3588p-1,
  0x1.EA3464p-1, 0x1.EA3342p-1, 0x1.EA3222p-1, 0x1.EA3106p-1,
  0x1.EA2FECp-1, 0x1.EA2ED6p-1, 0x1.EA2DC0p-1, 0x1.EA2CAEp-1,
  0x1.EA2BA0p-1, 0x1.EA2A94p-1, 0x1.EA298Ap-1, 0x1.EA2882p-1,
  0x1.EA277Ep-1, 0x1.EA267Cp-1, 0x1.EA257Ep-1, 0x1.EA2482p-1,
  0x1.EA2388p-1, 0x1.EA2292p-1, 0x1.EA219Ep-1, 0x1.EA20ACp-1,
  0x1.EA1FBCp-1, 0x1.EA1ED0p-1, 0x1.EA1DE8p-1, 0x1.EA1D00p-1,
  0x1.EA1C1Cp-1, 0x1.EA1B3Cp-1, 0x1.EA1A5Cp-1, 0x1.EA1980p-1,
  0x1.EA18A8p-1, 0x1.EA17D0p-1, 0x1.EA16FCp-1, 0x1.EA162Cp-1,
  0x1.EA155Ep-1, 0x1.EA1492p-1, 0x1.EA13C8p-1, 0x1.EA1302p-1,
  0x1.EA123Ep-1, 0x1.EA117Ep-1, 0x1.EA10C0p-1, 0x1.EA1004p-1,
  0x1.EA0F4Cp-1, 0x1.EA0E96p-1, 0x1.EA0DE2p-1, 0x1.EA0D30p-1,
  0x1.EA0C84p-1, 0x1.EA0BD8p-1, 0x1.EA0B30p-1, 0x1.EA0A8Ap-1,
  0x1.EA09E6p-1, 0x1.EA0946p-1, 0x1.EA08A8p-1, 0x1.EA080Ep-1,
  0x1.EA0776p-1, 0x1.EA06E0p-1, 0x1.EA064Ep-1, 0x1.EA05BCp-1,
  0x1.EA0530p-1, 0x1.EA04A6p-1, 0x1.EA041Ep-1, 0x1.EA0398p-1,
  0x1.EA0316p-1, 0x1.EA0296p-1, 0x1.EA021Ap-1, 0x1.EA019Ep-1,
  0x1.EA0128p-1, 0x1.EA00B2p-1, 0x1.EA0040p-1, 0x1.E9FFD2p-1,
  0x1.E9FF64p-1, 0x1.E9FEFAp-1, 0x1.E9FE94p-1, 0x1.E9FE30p-1,
  0x1.E9FDCEp-1, 0x1.E9FD70p-1, 0x1.E9FD12p-1, 0x1.E9FCBAp-1,
  0x1.E9FC62p-1, 0x1.E9FC0Ep-1, 0x1.E9FBBEp-1, 0x1.E9FB70p-1,
  0x1.E9FB24p-1, 0x1.E9FADAp-1, 0x1.E9FA94p-1, 0x1.E9FA52p-1,
  0x1.E9FA10p-1, 0x1.E9F9D2p-1, 0x1.E9F998p-1, 0x1.E9F960p-1,
  0x1.E9F92Ap-1, 0x1.E9F8F6p-1, 0x1.E9F8C6p-1, 0x1.E9F89Ap-1,
  0x1.E9F86Ep-1, 0x1.E9F846p-1, 0x1.E9F822p-1, 0x1.E9F800p-1,
  0x1.E9F7E0p-1, 0x1.E9F7C2p-1, 0x1.E9F7A8p-1, 0x1.E9F792p-1,
  0x1.E9F77Cp-1, 0x1.E9F76Cp-1, 0x1.E9F75Cp-1, 0x1.E9F750p-1,
  0x1.E9F746p-1, 0x1.E9F740p-1, 0x1.E9F73Cp-1, 0x1.E9F73Ap-1,
  0x1.E9F73Cp-1, 0x1.E9F740p-1, 0x1.E9F748p-1, 0x1.E9F752p-1,
  0x1.E9F75Ep-1, 0x1.E9F76Ep-1, 0x1.E9F780p-1, 0x1.E9F796p-1,
  0x1.E9F7AEp-1, 0x1.E9F7C8p-1, 0x1.E9F7E6p-1, 0x1.E9F806p-1,
  0x1.E9F828p-1, 0x1.E9F84Ep-1, 0x1.E9F876p-1, 0x1.E9F8A2p-1,
  0x1.E9F8D0p-1, 0x1.E9F902p-1, 0x1.E9F934p-1, 0x1.E9F96Cp-1,
  0x1.E9F9A4p-1, 0x1.E9F9E0p-1, 0x1.E9FA20p-1, 0x1.E9FA62p-1,
  0x1.E9FAA6p-1, 0x1.E9FAECp-1, 0x1.E9FB36p-1, 0x1.E9FB84p-1,
  0x1.E9FBD4p-1, 0x1.E9FC26p-1, 0x1.E9FC7Cp-1, 0x1.E9FCD4p-1,
  0x1.E9FD2Ep-1, 0x1.E9FD8Cp-1, 0x1.E9FDECp-1, 0x1.E9FE50p-1,
  0x1.E9FEB6p-1, 0x1.E9FF1Ep-1, 0x1.E9FF8Ap-1, 0x1.E9FFF8p-1,
  0x1.EA006Ap-1, 0x1.EA00DEp-1, 0x1.EA0154p-1, 0x1.EA01CEp-1,
  0x1.EA024Cp-1, 0x1.EA02CAp-1, 0x1.EA034Cp-1, 0x1.EA03D2p-1,
  0x1.EA045Ap-1, 0x1.EA04E4p-1, 0x1.EA0572p-1, 0x1.EA0602p-1,
  0x1.EA0694p-1, 0x1.EA072Ap-1, 0x1.EA07C4p-1, 0x1.EA0860p-1,
  0x1.EA08FEp-1, 0x1.EA099Ep-1, 0x1.EA0A42p-1, 0x1.EA0AEAp-1,
  0x1.EA0B94p-1, 0x1.EA0C40p-1, 0x1.EA0CF0p-1, 0x1.EA0DA2p-1,
  0x1.EA0E56p-1, 0x1.EA0F0Ep-1, 0x1.EA0FCAp-1, 0x1.EA1086p-1,
  0x1.EA1148p-1, 0x1.EA120Ap-1, 0x1.EA12D0p-1, 0x1.EA139Ap-1,
  0x1.EA1466p-1, 0x1.EA1534p-1, 0x1.EA1606p-1, 0x1.EA16DAp-1,
  0x1.EA17B0p-1, 0x1.EA188Ap-1, 0x1.EA1968p-1, 0x1.EA1A48p-1,
  0x1.EA1B2Ap-1, 0x1.EA1C0Ep-1, 0x1.EA1CF8p-1, 0x1.EA1DE2p-1,
  0x1.EA1ED0p-1, 0x1.EA1FC0p-1, 0x1.EA20B4p-1, 0x1.EA21AAp-1,
  0x1.EA22A4p-1, 0x1.EA23A0p-1, 0x1.EA24A0p-1, 0x1.EA25A2p-1,
  0x1.EA26A6p-1, 0x1.EA27AEp-1, 0x1.EA28B8p-1, 0x1.EA29C6p-1,
  0x1.EA2AD6p-1, 0x1.EA2BE8p-1, 0x1.EA2CFEp-1, 0x1.EA2E18p-1,
  0x1.EA2F34p-1, 0x1.EA3052p-1, 0x1.EA3174p-1, 0x1.EA3298p-1,
  0x1.EA33BEp-1, 0x1.EA34E8p-1, 0x1.EA3616p-1, 0x1.EA3746p-1,
  0x1.EA3878p-1, 0x1.EA39AEp-1, 0x1.EA3AE6p-1, 0x1.EA3C22p-1,
  0x1.EA3D60p-1, 0x1.EA3EA0p-1, 0x1.EA3FE4p-1, 0x1.EA412Cp-1,
  0x1.EA4276p-1, 0x1.EA43C2p-1, 0x1.EA4512p-1, 0x1.EA4664p-1,
  0x1.EA47B8p-1, 0x1.EA4912p-1, 0x1.EA4A6Cp-1, 0x1.EA4BCAp-1,
  0x1.EA4D2Ap-1, 0x1.EA4E8Ep-1, 0x1.EA4FF6p-1, 0x1.EA515Ep-1,
  0x1.EA52CCp-1, 0x1.EA543Ap-1, 0x1.EA55ACp-1, 0x1.EA5722p-1,
  0x1.EA589Ap-1, 0x1.EA5A14p-1, 0x1.EA5B92p-1, 0x1.EA5D12p-1,
  0x1.EA5E96p-1, 0x1.EA601Ep-1, 0x1.EA61A6p-1, 0x1.EA6332p-1,
  0x1.EA64C2p-1, 0x1.EA6654p-1, 0x1.EA67EAp-1, 0x1.EA6982p-1,
  0x1.EA6B1Cp-1, 0x1.EA6CBAp-1, 0x1.EA6E5Ap-1, 0x1.EA6FFEp-1,
  0x1.EA71A4p-1, 0x1.EA734Ep-1, 0x1.EA74FAp-1, 0x1.EA76AAp-1,
  0x1.EA785Cp-1, 0x1.EA7A10p-1, 0x1.EA7BC8p-1, 0x1.EA7D84p-1,
  0x1.EA7F42p-1, 0x1.EA8102p-1, 0x1.EA82C6p-1, 0x1.EA848Cp-1,
  0x1.EA8656p-1, 0x1.EA8822p-1, 0x1.EA89F2p-1, 0x1.EA8BC4p-1,
  0x1.EA8D9Ap-1, 0x1.EA8F72p-1, 0x1.EA914Ep-1, 0x1.EA932Cp-1,
  0x1.EA950Cp-1, 0x1.EA96F0p-1, 0x1.EA98D6p-1, 0x1.EA9AC0p-1,
  0x1.EA9CAEp-1, 0x1.EA9E9Ep-1, 0x1.EAA090p-1, 0x1.EAA286p-1,
  0x1.EAA47Ep-1, 0x1.EAA67Ap-1, 0x1.EAA878p-1, 0x1.EAAA7Ap-1,
  0x1.EAAC7Ep-1, 0x1.EAAE84p-1, 0x1.EAB090p-1, 0x1.EAB29Cp-1,
  0x1.EAB4ACp-1, 0x1.EAB6C0p-1, 0x1.EAB8D6p-1, 0x1.EABAEEp-1,
  0x1.EABD0Ap-1, 0x1.EABF2Ap-1, 0x1.EAC14Ap-1, 0x1.EAC370p-1,
  0x1.EAC598p-1, 0x1.EAC7C2p-1, 0x1.EAC9F0p-1, 0x1.EACC20p-1,
  0x1.EACE54p-1, 0x1.EAD08Ap-1, 0x1.EAD2C4p-1, 0x1.EAD500p-1,
  0x1.EAD740p-1, 0x1.EAD982p-1, 0x1.EADBC8p-1, 0x1.EADE10p-1,
  0x1.EAE05Cp-1, 0x1.EAE2AAp-1, 0x1.EAE4FCp-1, 0x1.EAE750p-1,
  0x1.EAE9A6p-1, 0x1.EAEC00p-1, 0x1.EAEE5Ep-1, 0x1.EAF0BEp-1,
  0x1.EAF322p-1, 0x1.EAF588p-1, 0x1.EAF7F0p-1, 0x1.EAFA5Cp-1,
  0x1.EAFCCCp-1, 0x1.EAFF3Ep-1, 0x1.EB01B2p-1, 0x1.EB042Ap-1,
  0x1.EB06A6p-1, 0x1.EB0924p-1, 0x1.EB0BA4p-1, 0x1.EB0E28p-1,
  0x1.EB10B0p-1, 0x1.EB133Ap-1, 0x1.EB15C6p-1, 0x1.EB1856p-1,
  0x1.EB1AEAp-1, 0x1.EB1D80p-1, 0x1.EB2018p-1, 0x1.EB22B4p-1,
  0x1.EB2554p-1, 0x1.EB27F6p-1, 0x1.EB2A9Ap-1, 0x1.EB2D42p-1,
  0x1.EB2FEEp-1, 0x1.EB329Ap-1, 0x1.EB354Cp-1, 0x1.EB3800p-1,
  0x1.EB3AB6p-1, 0x1.EB3D70p-1, 0x1.EB402Ep-1, 0x1.EB42EEp-1,
  0x1.EB45B0p-1, 0x1.EB4876p-1, 0x1.EB4B40p-1, 0x1.EB4E0Cp-1,
  0x1.EB50DAp-1, 0x1.EB53ACp-1, 0x1.EB5682p-1, 0x1.EB595Ap-1,
  0x1.EB5C36p-1, 0x1.EB5F14p-1, 0x1.EB61F4p-1, 0x1.EB64D8p-1,
  0x1.EB67C0p-1, 0x1.EB6AAAp-1, 0x1.EB6D98p-1, 0x1.EB7088p-1,
  0x1.EB737Cp-1, 0x1.EB7672p-1, 0x1.EB796Ap-1, 0x1.EB7C68p-1,
  0x1.EB7F66p-1, 0x1.EB826Ap-1, 0x1.EB856Ep-1, 0x1.EB8878p-1,
  0x1.EB8B82p-1, 0x1.EB8E92p-1, 0x1.EB91A2p-1, 0x1.EB94B8p-1,
  0x1.EB97D0p-1, 0x1.EB9AEAp-1, 0x1.EB9E08p-1, 0x1.EBA128p-1,
  0x1.EBA44Cp-1, 0x1.EBA774p-1, 0x1.EBAA9Ep-1, 0x1.EBADCAp-1,
  0x1.EBB0FAp-1, 0x1.EBB42Ep-1, 0x1.EBB764p-1, 0x1.EBBA9Ep-1,
  0x1.EBBDDAp-1, 0x1.EBC118p-1, 0x1.EBC45Cp-1, 0x1.EBC7A0p-1,
  0x1.EBCAEAp-1, 0x1.EBCE34p-1, 0x1.EBD184p-1, 0x1.EBD4D6p-1,
  0x1.EBD82Ap-1, 0x1.EBDB82p-1, 0x1.EBDEDCp-1, 0x1.EBE23Ap-1,
  0x1.EBE59Cp-1, 0x1.EBE900p-1, 0x1.EBEC66p-1, 0x1.EBEFD2p-1,
  0x1.EBF33Ep-1, 0x1.EBF6AEp-1, 0x1.EBFA22p-1, 0x1.EBFD98p-1,
  0x1.EC0112p-1, 0x1.EC048Ep-1, 0x1.EC080Ep-1, 0x1.EC0B92p-1,
  0x1.EC0F18p-1, 0x1.EC12A0p-1, 0x1.EC162Cp-1, 0x1.EC19BCp-1,
  0x1.EC1D4Ep-1, 0x1.EC20E2p-1, 0x1.EC247Ap-1, 0x1.EC2816p-1,
  0x1.EC2BB4p-1, 0x1.EC2F56p-1, 0x1.EC32FCp-1, 0x1.EC36A2p-1,
  0x1.EC3A4Ep-1, 0x1.EC3DFCp-1, 0x1.EC41ACp-1, 0x1.EC4560p-1,
  0x1.EC4918p-1, 0x1.EC4CD2p-1, 0x1.EC5090p-1, 0x1.EC5450p-1,
  0x1.EC5814p-1, 0x1.EC5BDAp-1, 0x1.EC5FA4p-1, 0x1.EC6372p-1,
  0x1.EC6742p-1, 0x1.EC6B14p-1, 0x1.EC6EEAp-1, 0x1.EC72C4p-1,
  0x1.EC76A0p-1, 0x1.EC7A80p-1, 0x1.EC7E62p-1, 0x1.EC8248p-1,
  0x1.EC8632p-1, 0x1.EC8A1Ep-1, 0x1.EC8E0Cp-1, 0x1.EC91FEp-1,
  0x1.EC95F4p-1, 0x1.EC99ECp-1, 0x1.EC9DE8p-1, 0x1.ECA1E8p-1,
  0x1.ECA5E8p-1, 0x1.ECA9EEp-1, 0x1.ECADF6p-1, 0x1.ECB200p-1,
  0x1.ECB610p-1, 0x1.ECBA20p-1, 0x1.ECBE36p-1, 0x1.ECC24Cp-1,
  0x1.ECC668p-1, 0x1.ECCA86p-1, 0x1.ECCEA6p-1, 0x1.ECD2CAp-1,
  0x1.ECD6F2p-1, 0x1.ECDB1Cp-1, 0x1.ECDF4Ap-1, 0x1.ECE37Ap-1,
  0x1.ECE7AEp-1, 0x1.ECEBE6p-1, 0x1.ECF020p-1, 0x1.ECF45Ep-1,
  0x1.ECF89Ep-1, 0x1.ECFCE2p-1, 0x1.ED0128p-1, 0x1.ED0572p-1,
  0x1.ED09BEp-1, 0x1.ED0E0Ep-1, 0x1.ED1262p-1, 0x1.ED16B8p-1,
  0x1.ED1B12p-1, 0x1.ED1F6Ep-1, 0x1.ED23CEp-1, 0x1.ED2832p-1,
  0x1.ED2C98p-1, 0x1.ED3102p-1, 0x1.ED356Ep-1, 0x1.ED39DEp-1,
  0x1.ED3E50p-1, 0x1.ED42C6p-1, 0x1.ED4740p-1, 0x1.ED4BBCp-1,
  0x1.ED503Cp-1, 0x1.ED54BEp-1, 0x1.ED5944p-1, 0x1.ED5DCCp-1,
  0x1.ED6258p-1, 0x1.ED66E8p-1, 0x1.ED6B7Ap-1, 0x1.ED7010p-1,
  0x1.ED74A8p-1, 0x1.ED7944p-1, 0x1.ED7DE4p-1, 0x1.ED8286p-1,
  0x1.ED872Cp-1, 0x1.ED8BD4p-1, 0x1.ED9080p-1, 0x1.ED9530p-1,
  0x1.ED99E2p-1, 0x1.ED9E96p-1, 0x1.EDA350p-1, 0x1.EDA80Ap-1,
  0x1.EDACCAp-1, 0x1.EDB18Cp-1, 0x1.EDB652p-1, 0x1.EDBB1Ap-1,
  0x1.EDBFE6p-1, 0x1.EDC4B4p-1, 0x1.EDC986p-1, 0x1.EDCE5Cp-1,
  0x1.EDD334p-1, 0x1.EDD810p-1, 0x1.EDDCEEp-1, 0x1.EDE1D0p-1,
  0x1.EDE6B6p-1, 0x1.EDEB9Ep-1, 0x1.EDF08Ap-1, 0x1.EDF578p-1,
  0x1.EDFA6Ap-1, 0x1.EDFF60p-1, 0x1.EE0458p-1, 0x1.EE0954p-1,
  0x1.EE0E52p-1, 0x1.EE1354p-1, 0x1.EE185Ap-1, 0x1.EE1D62p-1,
  0x1.EE226Ep-1, 0x1.EE277Cp-1, 0x1.EE2C8Ep-1, 0x1.EE31A4p-1,
  0x1.EE36BCp-1, 0x1.EE3BD8p-1, 0x1.EE40F6p-1, 0x1.EE4618p-1,
  0x1.EE4B3Ep-1, 0x1.EE5066p-1, 0x1.EE5592p-1, 0x1.EE5AC2p-1,
  0x1.EE5FF4p-1, 0x1.EE652Ap-1, 0x1.EE6A62p-1, 0x1.EE6F9Ep-1,
  0x1.EE74DCp-1, 0x1.EE7A20p-1, 0x1.EE7F64p-1, 0x1.EE84AEp-1,
  0x1.EE89FAp-1, 0x1.EE8F48p-1, 0x1.EE949Cp-1, 0x1.EE99F2p-1,
  0x1.EE9F4Ap-1, 0x1.EEA4A6p-1, 0x1.EEAA06p-1, 0x1.EEAF68p-1,
  0x1.EEB4CEp-1, 0x1.EEBA38p-1, 0x1.EEBFA4p-1, 0x1.EEC514p-1,
  0x1.EECA86p-1, 0x1.EECFFCp-1, 0x1.EED576p-1, 0x1.EEDAF2p-1,
  0x1.EEE072p-1, 0x1.EEE5F6p-1, 0x1.EEEB7Cp-1, 0x1.EEF106p-1,
  0x1.EEF692p-1, 0x1.EEFC22p-1, 0x1.EF01B6p-1, 0x1.EF074Cp-1,
  0x1.EF0CE6p-1, 0x1.EF1284p-1, 0x1.EF1824p-1, 0x1.EF1DC8p-1,
  0x1.EF2370p-1, 0x1.EF291Ap-1, 0x1.EF2EC6p-1, 0x1.EF3478p-1,
  0x1.EF3A2Cp-1, 0x1.EF3FE2p-1, 0x1.EF459Ep-1, 0x1.EF4B5Cp-1,
  0x1.EF511Cp-1, 0x1.EF56E0p-1, 0x1.EF5CA8p-1, 0x1.EF6274p-1,
  0x1.EF6842p-1, 0x1.EF6E12p-1, 0x1.EF73E8p-1, 0x1.EF79C0p-1,
  0x1.EF7F9Ap-1, 0x1.EF857Ap-1, 0x1.EF8B5Cp-1, 0x1.EF9140p-1,
  0x1.EF9728p-1, 0x1.EF9D14p-1, 0x1.EFA304p-1, 0x1.EFA8F6p-1,
  0x1.EFAEECp-1, 0x1.EFB4E4p-1, 0x1.EFBAE0p-1, 0x1.EFC0E0p-1,
  0x1.EFC6E2p-1, 0x1.EFCCE8p-1, 0x1.EFD2F2p-1, 0x1.EFD8FEp-1,
  0x1.EFDF0Ep-1, 0x1.EFE522p-1, 0x1.EFEB38p-1, 0x1.EFF152p-1,
  0x1.EFF770p-1, 0x1.EFFD90p-1, 0x1.F003B4p-1, 0x1.F009DAp-1,
  0x1.F01004p-1, 0x1.F01632p-1, 0x1.F01C64p-1, 0x1.F02298p-1,
  0x1.F028D0p-1, 0x1.F02F0Ap-1, 0x1.F03548p-1, 0x1.F03B8Ap-1,
  0x1.F041CEp-1, 0x1.F04816p-1, 0x1.F04E62p-1, 0x1.F054B0p-1,
  0x1.F05B04p-1, 0x1.F06158p-1, 0x1.F067B2p-1, 0x1.F06E0Ep-1,
  0x1.F0746Cp-1, 0x1.F07AD0p-1, 0x1.F08136p-1, 0x1.F0879Ep-1,
  0x1.F08E0Cp-1, 0x1.F0947Cp-1, 0x1.F09AEEp-1, 0x1.F0A166p-1,
  0x1.F0A7E0p-1, 0x1.F0AE5Cp-1, 0x1.F0B4DEp-1, 0x1.F0BB62p-1,
  0x1.F0C1EAp-1, 0x1.F0C874p-1, 0x1.F0CF02p-1, 0x1.F0D594p-1,
  0x1.F0DC28p-1, 0x1.F0E2C0p-1, 0x1.F0E95Cp-1, 0x1.F0EFFAp-1,
  0x1.F0F69Cp-1, 0x1.F0FD42p-1, 0x1.F103EAp-1, 0x1.F10A96p-1,
  0x1.F11146p-1, 0x1.F117FAp-1, 0x1.F11EB0p-1, 0x1.F12568p-1,
  0x1.F12C26p-1, 0x1.F132E6p-1, 0x1.F139AAp-1, 0x1.F14070p-1,
  0x1.F1473Cp-1, 0x1.F14E08p-1, 0x1.F154DAp-1, 0x1.F15BAEp-1,
  0x1.F16286p-1, 0x1.F16962p-1, 0x1.F17040p-1, 0x1.F17722p-1,
  0x1.F17E06p-1, 0x1.F184F0p-1, 0x1.F18BDCp-1, 0x1.F192CCp-1,
  0x1.F199BEp-1, 0x1.F1A0B4p-1, 0x1.F1A7AEp-1, 0x1.F1AEAAp-1,
  0x1.F1B5AAp-1, 0x1.F1BCAEp-1, 0x1.F1C3B6p-1, 0x1.F1CAC0p-1,
  0x1.F1D1CEp-1, 0x1.F1D8DEp-1, 0x1.F1DFF4p-1, 0x1.F1E70Cp-1,
  0x1.F1EE26p-1, 0x1.F1F546p-1, 0x1.F1FC68p-1, 0x1.F2038Ep-1,
  0x1.F20AB6p-1, 0x1.F211E2p-1, 0x1.F21912p-1, 0x1.F22046p-1,
  0x1.F2277Cp-1, 0x1.F22EB6p-1, 0x1.F235F2p-1, 0x1.F23D34p-1,
  0x1.F24478p-1, 0x1.F24BC0p-1, 0x1.F2530Ap-1, 0x1.F25A58p-1,
  0x1.F261AAp-1, 0x1.F26900p-1, 0x1.F27058p-1, 0x1.F277B4p-1,
  0x1.F27F12p-1, 0x1.F28676p-1, 0x1.F28DDCp-1, 0x1.F29546p-1,
  0x1.F29CB2p-1, 0x1.F2A422p-1, 0x1.F2AB96p-1, 0x1.F2B30Ep-1,
  0x1.F2BA88p-1, 0x1.F2C206p-1, 0x1.F2C988p-1, 0x1.F2D10Ep-1,
  0x1.F2D896p-1, 0x1.F2E022p-1, 0x1.F2E7B0p-1, 0x1.F2EF44p-1,
  0x1.F2F6DAp-1, 0x1.F2FE72p-1, 0x1.F30610p-1, 0x1.F30DB0p-1,
  0x1.F31554p-1, 0x1.F31CFCp-1, 0x1.F324A6p-1, 0x1.F32C54p-1,
  0x1.F33406p-1, 0x1.F33BBAp-1, 0x1.F34372p-1, 0x1.F34B2Ep-1,
  0x1.F352EEp-1, 0x1.F35AB0p-1, 0x1.F36278p-1, 0x1.F36A40p-1,
  0x1.F3720Ep-1, 0x1.F379DEp-1, 0x1.F381B2p-1, 0x1.F3898Ap-1,
  0x1.F39164p-1, 0x1.F39944p-1, 0x1.F3A124p-1, 0x1.F3A90Ap-1,
  0x1.F3B0F2p-1, 0x1.F3B8E0p-1, 0x1.F3C0CEp-1, 0x1.F3C8C2p-1,
  0x1.F3D0B8p-1, 0x1.F3D8B2p-1, 0x1.F3E0B0p-1, 0x1.F3E8B0p-1,
  0x1.F3F0B6p-1, 0x1.F3F8BEp-1, 0x1.F400C8p-1, 0x1.F408D8p-1,
  0x1.F410EAp-1, 0x1.F41900p-1, 0x1.F42118p-1, 0x1.F42936p-1,
  0x1.F43156p-1, 0x1.F4397Ap-1, 0x1.F441A0p-1, 0x1.F449CCp-1,
  0x1.F451FAp-1, 0x1.F45A2Ap-1, 0x1.F46260p-1, 0x1.F46A98p-1,
  0x1.F472D4p-1, 0x1.F47B14p-1, 0x1.F48358p-1, 0x1.F48B9Ep-1,
  0x1.F493E8p-1, 0x1.F49C36p-1, 0x1.F4A486p-1, 0x1.F4ACDAp-1,
  0x1.F4B532p-1, 0x1.F4BD8Ep-1, 0x1.F4C5EEp-1, 0x1.F4CE50p-1,
  0x1.F4D6B6p-1, 0x1.F4DF20p-1, 0x1.F4E78Cp-1, 0x1.F4EFFCp-1,
  0x1.F4F870p-1, 0x1.F500E8p-1, 0x1.F50962p-1, 0x1.F511E2p-1,
  0x1.F51A64p-1, 0x1.F522EAp-1, 0x1.F52B72p-1, 0x1.F533FEp-1,
  0x1.F53C8Ep-1, 0x1.F54522p-1, 0x1.F54DBAp-1, 0x1.F55654p-1,
  0x1.F55EF2p-1, 0x1.F56794p-1, 0x1.F57038p-1, 0x1.F578E2p-1,
  0x1.F5818Ep-1, 0x1.F58A3Ep-1, 0x1.F592F0p-1, 0x1.F59BA8p-1,
  0x1.F5A462p-1, 0x1.F5AD20p-1, 0x1.F5B5E2p-1, 0x1.F5BEA6p-1,
  0x1.F5C76Ep-1, 0x1.F5D03Ap-1, 0x1.F5D90Ap-1, 0x1.F5E1DEp-1,
  0x1.F5EAB4p-1, 0x1.F5F38Ep-1, 0x1.F5FC6Cp-1, 0x1.F6054Cp-1,
  0x1.F60E32p-1, 0x1.F6171Ap-1, 0x1.F62006p-1, 0x1.F628F4p-1,
  0x1.F631E8p-1, 0x1.F63ADEp-1, 0x1.F643D8p-1, 0x1.F64CD6p-1,
  0x1.F655D8p-1, 0x1.F65EDCp-1, 0x1.F667E4p-1, 0x1.F670F0p-1,
  0x1.F67A00p-1, 0x1.F68312p-1, 0x1.F68C28p-1, 0x1.F69542p-1,
  0x1.F69E60p-1, 0x1.F6A782p-1, 0x1.F6B0A6p-1, 0x1.F6B9CEp-1,
  0x1.F6C2FAp-1, 0x1.F6CC2Ap-1, 0x1.F6D55Cp-1, 0x1.F6DE94p-1,
  0x1.F6E7CEp-1, 0x1.F6F10Cp-1, 0x1.F6FA4Cp-1, 0x1.F70392p-1,
  0x1.F70CDAp-1, 0x1.F71626p-1, 0x1.F71F76p-1, 0x1.F728C8p-1,
  0x1.F73220p-1, 0x1.F73B7Ap-1, 0x1.F744D8p-1, 0x1.F74E38p-1,
  0x1.F7579Ep-1, 0x1.F76106p-1, 0x1.F76A72p-1, 0x1.F773E2p-1,
  0x1.F77D56p-1, 0x1.F786CEp-1, 0x1.F79048p-1, 0x1.F799C6p-1,
  0x1.F7A348p-1, 0x1.F7ACCEp-1, 0x1.F7B656p-1, 0x1.F7BFE4p-1,
  0x1.F7C974p-1, 0x1.F7D308p-1, 0x1.F7DC9Ep-1, 0x1.F7E63Ap-1,
  0x1.F7EFD8p-1, 0x1.F7F97Ap-1, 0x1.F80320p-1, 0x1.F80CCAp-1,
  0x1.F81676p-1, 0x1.F82028p-1, 0x1.F829DCp-1, 0x1.F83394p-1,
  0x1.F83D50p-1, 0x1.F8470Ep-1, 0x1.F850D0p-1, 0x1.F85A98p-1,
  0x1.F86462p-1, 0x1.F86E2Ep-1, 0x1.F87800p-1, 0x1.F881D6p-1,
  0x1.F88BAEp-1, 0x1.F8958Ap-1, 0x1.F89F6Ap-1, 0x1.F8A94Cp-1,
  0x1.F8B334p-1, 0x1.F8BD1Ep-1, 0x1.F8C70Cp-1, 0x1.F8D0FEp-1,
  0x1.F8DAF4p-1, 0x1.F8E4EEp-1, 0x1.F8EEEAp-1, 0x1.F8F8EAp-1,
  0x1.F902EEp-1, 0x1.F90CF6p-1, 0x1.F91702p-1, 0x1.F92110p-1,
  0x1.F92B24p-1, 0x1.F9353Ap-1, 0x1.F93F54p-1, 0x1.F94972p-1,
  0x1.F95392p-1, 0x1.F95DB8p-1, 0x1.F967E0p-1, 0x1.F9720Cp-1,
  0x1.F97C3Cp-1, 0x1.F98670p-1, 0x1.F990A6p-1, 0x1.F99AE2p-1,
  0x1.F9A520p-1, 0x1.F9AF62p-1, 0x1.F9B9A8p-1, 0x1.F9C3F2p-1,
  0x1.F9CE3Ep-1, 0x1.F9D890p-1, 0x1.F9E2E4p-1, 0x1.F9ED3Cp-1,
  0x1.F9F798p-1, 0x1.FA01F6p-1, 0x1.FA0C5Ap-1, 0x1.FA16C0p-1,
  0x1.FA212Cp-1, 0x1.FA2B9Ap-1, 0x1.FA360Cp-1, 0x1.FA4080p-1,
  0x1.FA4AFAp-1, 0x1.FA5578p-1, 0x1.FA5FF8p-1, 0x1.FA6A7Cp-1,
  0x1.FA7504p-1, 0x1.FA7F90p-1, 0x1.FA8A1Ep-1, 0x1.FA94B2p-1,
  0x1.FA9F48p-1, 0x1.FAA9E2p-1, 0x1.FAB480p-1, 0x1.FABF22p-1,
  0x1.FAC9C8p-1, 0x1.FAD472p-1, 0x1.FADF1Ep-1, 0x1.FAE9CEp-1,
  0x1.FAF482p-1, 0x1.FAFF3Ap-1, 0x1.FB09F6p-1, 0x1.FB14B6p-1,
  0x1.FB1F78p-1, 0x1.FB2A40p-1, 0x1.FB350Ap-1, 0x1.FB3FD8p-1,
  0x1.FB4AAAp-1, 0x1.FB5580p-1, 0x1.FB605Ap-1, 0x1.FB6B36p-1,
  0x1.FB7616p-1, 0x1.FB80FCp-1, 0x1.FB8BE4p-1, 0x1.FB96D0p-1,
  0x1.FBA1BEp-1, 0x1.FBACB2p-1, 0x1.FBB7AAp-1, 0x1.FBC2A4p-1,
  0x1.FBCDA2p-1, 0x1.FBD8A4p-1, 0x1.FBE3AAp-1, 0x1.FBEEB4p-1,
  0x1.FBF9C2p-1, 0x1.FC04D2p-1, 0x1.FC0FE8p-1, 0x1.FC1B00p-1,
  0x1.FC261Cp-1, 0x1.FC313Cp-1, 0x1.FC3C60p-1, 0x1.FC4788p-1,
  0x1.FC52B4p-1, 0x1.FC5DE2p-1, 0x1.FC6916p-1, 0x1.FC744Cp-1,
  0x1.FC7F86p-1, 0x1.FC8AC4p-1, 0x1.FC9606p-1, 0x1.FCA14Cp-1,
  0x1.FCAC94p-1, 0x1.FCB7E2p-1, 0x1.FCC332p-1, 0x1.FCCE86p-1,
  0x1.FCD9E0p-1, 0x1.FCE53Cp-1, 0x1.FCF09Ap-1, 0x1.FCFBFEp-1,
  0x1.FD0766p-1, 0x1.FD12D0p-1, 0x1.FD1E40p-1, 0x1.FD29B2p-1,
  0x1.FD3528p-1, 0x1.FD40A2p-1, 0x1.FD4C20p-1, 0x1.FD57A2p-1,
  0x1.FD6328p-1, 0x1.FD6EB0p-1, 0x1.FD7A3Ep-1, 0x1.FD85CEp-1,
  0x1.FD9164p-1, 0x1.FD9CFCp-1, 0x1.FDA898p-1, 0x1.FDB438p-1,
  0x1.FDBFDAp-1, 0x1.FDCB82p-1, 0x1.FDD72Ep-1, 0x1.FDE2DCp-1,
  0x1.FDEE90p-1, 0x1.FDFA46p-1, 0x1.FE0600p-1, 0x1.FE11BEp-1,
  0x1.FE1D80p-1, 0x1.FE2946p-1, 0x1.FE3510p-1, 0x1.FE40DCp-1,
  0x1.FE4CAEp-1, 0x1.FE5882p-1, 0x1.FE645Cp-1, 0x1.FE7038p-1,
  0x1.FE7C18p-1, 0x1.FE87FCp-1, 0x1.FE93E4p-1, 0x1.FE9FD0p-1,
  0x1.FEABC0p-1, 0x1.FEB7B2p-1, 0x1.FEC3AAp-1, 0x1.FECFA4p-1,
  0x1.FEDBA4p-1, 0x1.FEE7A6p-1, 0x1.FEF3ACp-1, 0x1.FEFFB6p-1,
  0x1.FF0BC4p-1, 0x1.FF17D6p-1, 0x1.FF23ECp-1, 0x1.FF3006p-1,
  0x1.FF3C22p-1, 0x1.FF4844p-1, 0x1.FF5468p-1, 0x1.FF6092p-1,
  0x1.FF6CBEp-1, 0x1.FF78EEp-1, 0x1.FF8522p-1, 0x1.FF915Ap-1,
  0x1.FF9D96p-1, 0x1.FFA9D6p-1, 0x1.FFB61Ap-1, 0x1.FFC262p-1,
  0x1.FFCEACp-1, 0x1.FFDAFCp-1, 0x1.FFE74Ep-1, 0x1.FFF3A6p-1,
};
