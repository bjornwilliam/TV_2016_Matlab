function CodeDefine() { 
this.def = new Array();
this.def["rt_OneStep"] = {file: "ert_main_c.html",line:37,type:"fcn"};
this.def["main"] = {file: "ert_main_c.html",line:74,type:"fcn"};
this.def["Estimations_B"] = {file: "Estimations_c.html",line:24,type:"var"};
this.def["Estimations_DW"] = {file: "Estimations_c.html",line:27,type:"var"};
this.def["Estimations_U"] = {file: "Estimations_c.html",line:30,type:"var"};
this.def["Estimations_Y"] = {file: "Estimations_c.html",line:33,type:"var"};
this.def["Estimations_M_"] = {file: "Estimations_c.html",line:36,type:"var"};
this.def["Estimations_M"] = {file: "Estimations_c.html",line:37,type:"var"};
this.def["look1_iflf_binlxpw"] = {file: "Estimations_c.html",line:38,type:"fcn"};
this.def["Estimations_step"] = {file: "Estimations_c.html",line:94,type:"fcn"};
this.def["Estimations_initialize"] = {file: "Estimations_c.html",line:658,type:"fcn"};
this.def["B_Estimations_T"] = {file: "Estimations_h.html",line:59,type:"type"};
this.def["DW_Estimations_T"] = {file: "Estimations_h.html",line:68,type:"type"};
this.def["ExtU_Estimations_T"] = {file: "Estimations_h.html",line:75,type:"type"};
this.def["ExtY_Estimations_T"] = {file: "Estimations_h.html",line:85,type:"type"};
this.def["normalForces"] = {file: "Estimations_types_h.html",line:31,type:"type"};
this.def["SensorInputs"] = {file: "Estimations_types_h.html",line:81,type:"type"};
this.def["T_meas"] = {file: "Estimations_types_h.html",line:93,type:"type"};
this.def["normLongTireForce"] = {file: "Estimations_types_h.html",line:105,type:"type"};
this.def["SR"] = {file: "Estimations_types_h.html",line:117,type:"type"};
this.def["OutputTelemetri_est"] = {file: "Estimations_types_h.html",line:129,type:"type"};
this.def["CarParams"] = {file: "Estimations_types_h.html",line:158,type:"type"};
this.def["Fx"] = {file: "Estimations_types_h.html",line:170,type:"type"};
this.def["Settings"] = {file: "Estimations_types_h.html",line:198,type:"type"};
this.def["Whl_speed"] = {file: "Estimations_types_h.html",line:210,type:"type"};
this.def["States"] = {file: "Estimations_types_h.html",line:253,type:"type"};
this.def["P_Estimations_T"] = {file: "Estimations_types_h.html",line:258,type:"type"};
this.def["RT_MODEL_Estimations_T"] = {file: "Estimations_types_h.html",line:261,type:"type"};
this.def["Estimations_P"] = {file: "Estimations_data_c.html",line:24,type:"var"};
this.def["int8_T"] = {file: "rtwtypes_h.html",line:51,type:"type"};
this.def["uint8_T"] = {file: "rtwtypes_h.html",line:52,type:"type"};
this.def["int16_T"] = {file: "rtwtypes_h.html",line:53,type:"type"};
this.def["uint16_T"] = {file: "rtwtypes_h.html",line:54,type:"type"};
this.def["int32_T"] = {file: "rtwtypes_h.html",line:55,type:"type"};
this.def["uint32_T"] = {file: "rtwtypes_h.html",line:56,type:"type"};
this.def["real32_T"] = {file: "rtwtypes_h.html",line:57,type:"type"};
this.def["real64_T"] = {file: "rtwtypes_h.html",line:58,type:"type"};
this.def["real_T"] = {file: "rtwtypes_h.html",line:64,type:"type"};
this.def["time_T"] = {file: "rtwtypes_h.html",line:65,type:"type"};
this.def["boolean_T"] = {file: "rtwtypes_h.html",line:66,type:"type"};
this.def["int_T"] = {file: "rtwtypes_h.html",line:67,type:"type"};
this.def["uint_T"] = {file: "rtwtypes_h.html",line:68,type:"type"};
this.def["ulong_T"] = {file: "rtwtypes_h.html",line:69,type:"type"};
this.def["char_T"] = {file: "rtwtypes_h.html",line:70,type:"type"};
this.def["uchar_T"] = {file: "rtwtypes_h.html",line:71,type:"type"};
this.def["byte_T"] = {file: "rtwtypes_h.html",line:72,type:"type"};
this.def["pointer_T"] = {file: "rtwtypes_h.html",line:90,type:"type"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["ert_main_c.html"] = "../ert_main.c";
	this.html2Root["ert_main_c.html"] = "ert_main_c.html";
	this.html2SrcPath["Estimations_c.html"] = "../Estimations.c";
	this.html2Root["Estimations_c.html"] = "Estimations_c.html";
	this.html2SrcPath["Estimations_h.html"] = "../Estimations.h";
	this.html2Root["Estimations_h.html"] = "Estimations_h.html";
	this.html2SrcPath["Estimations_private_h.html"] = "../Estimations_private.h";
	this.html2Root["Estimations_private_h.html"] = "Estimations_private_h.html";
	this.html2SrcPath["Estimations_types_h.html"] = "../Estimations_types.h";
	this.html2Root["Estimations_types_h.html"] = "Estimations_types_h.html";
	this.html2SrcPath["Estimations_data_c.html"] = "../Estimations_data.c";
	this.html2Root["Estimations_data_c.html"] = "Estimations_data_c.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.html2SrcPath["mw_cmsis_h.html"] = "../mw_cmsis.h";
	this.html2Root["mw_cmsis_h.html"] = "mw_cmsis_h.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"ert_main_c.html","Estimations_c.html","Estimations_h.html","Estimations_private_h.html","Estimations_types_h.html","Estimations_data_c.html","rtwtypes_h.html","mw_cmsis_h.html"];
