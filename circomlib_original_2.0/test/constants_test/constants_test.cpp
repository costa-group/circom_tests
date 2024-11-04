#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "circom.hpp"
#include "calcwit.hpp"
void K_0_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void K_0_run(uint ctx_index,Circom_CalcWit* ctx);
void A_1_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void A_1_run(uint ctx_index,Circom_CalcWit* ctx);
Circom_TemplateFunction _functionTable[2] = { 
K_0_run,
A_1_run };
Circom_TemplateFunction _functionTableParallel[2] = { 
NULL,
NULL };
uint get_main_input_signal_start() {return 1;}

uint get_main_input_signal_no() {return 1;}

uint get_total_signal_no() {return 34;}

uint get_number_of_components() {return 2;}

uint get_size_of_input_hashmap() {return 256;}

uint get_size_of_witness() {return 34;}

uint get_size_of_constants() {return 128;}

uint get_size_of_io_map() {return 0;}

uint get_size_of_bus_field_map() {return 0;}

void release_memory_component(Circom_CalcWit* ctx, uint pos) {{

if (pos != 0){{

if(ctx->componentMemory[pos].subcomponents)
delete []ctx->componentMemory[pos].subcomponents;

if(ctx->componentMemory[pos].subcomponentsParallel)
delete []ctx->componentMemory[pos].subcomponentsParallel;

if(ctx->componentMemory[pos].outputIsSet)
delete []ctx->componentMemory[pos].outputIsSet;

if(ctx->componentMemory[pos].mutexes)
delete []ctx->componentMemory[pos].mutexes;

if(ctx->componentMemory[pos].cvs)
delete []ctx->componentMemory[pos].cvs;

if(ctx->componentMemory[pos].sbct)
delete []ctx->componentMemory[pos].sbct;

}}


}}


// function declarations
// template declarations
void K_0_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 0;
ctx->componentMemory[coffset].templateName = "K";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 0;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
K_0_run(coffset,ctx);
}

void K_0_run(uint ctx_index,Circom_CalcWit* ctx){
FrElement* signalValues = ctx->signalValues;
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
FrElement* circuitConstants = ctx->circuitConstants;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
FrElement expaux[3];
FrElement lvar[66];
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[3];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[4];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[5];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[6];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[7];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[8];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[9];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[10];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[11];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[12];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[13];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[14];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[15];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[16];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[17];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[18];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[19];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[20];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[21];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[22];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[23];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[24];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[25];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[26];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[27];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[28];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[29];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[30];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[31];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[32];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[33];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[34];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[35];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[36];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[37];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[38];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[39];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[40];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[41];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[42];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[43];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[44];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[45];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[46];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[47];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[48];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[49];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[50];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[51];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[52];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[53];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[54];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[55];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[56];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[57];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[58];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[59];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[60];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[61];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[62];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[63];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[64];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[64]);
}
{
PFrElement aux_dest = &lvar[2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[65]);
}
{
PFrElement aux_dest = &lvar[3];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[66]);
}
{
PFrElement aux_dest = &lvar[4];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[67]);
}
{
PFrElement aux_dest = &lvar[5];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[68]);
}
{
PFrElement aux_dest = &lvar[6];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[69]);
}
{
PFrElement aux_dest = &lvar[7];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[70]);
}
{
PFrElement aux_dest = &lvar[8];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[71]);
}
{
PFrElement aux_dest = &lvar[9];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[72]);
}
{
PFrElement aux_dest = &lvar[10];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[73]);
}
{
PFrElement aux_dest = &lvar[11];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[74]);
}
{
PFrElement aux_dest = &lvar[12];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[75]);
}
{
PFrElement aux_dest = &lvar[13];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[76]);
}
{
PFrElement aux_dest = &lvar[14];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[77]);
}
{
PFrElement aux_dest = &lvar[15];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[78]);
}
{
PFrElement aux_dest = &lvar[16];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[79]);
}
{
PFrElement aux_dest = &lvar[17];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[80]);
}
{
PFrElement aux_dest = &lvar[18];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[81]);
}
{
PFrElement aux_dest = &lvar[19];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[82]);
}
{
PFrElement aux_dest = &lvar[20];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[83]);
}
{
PFrElement aux_dest = &lvar[21];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[84]);
}
{
PFrElement aux_dest = &lvar[22];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[85]);
}
{
PFrElement aux_dest = &lvar[23];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[86]);
}
{
PFrElement aux_dest = &lvar[24];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[87]);
}
{
PFrElement aux_dest = &lvar[25];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[88]);
}
{
PFrElement aux_dest = &lvar[26];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[89]);
}
{
PFrElement aux_dest = &lvar[27];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[90]);
}
{
PFrElement aux_dest = &lvar[28];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[91]);
}
{
PFrElement aux_dest = &lvar[29];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[92]);
}
{
PFrElement aux_dest = &lvar[30];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[93]);
}
{
PFrElement aux_dest = &lvar[31];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[94]);
}
{
PFrElement aux_dest = &lvar[32];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[95]);
}
{
PFrElement aux_dest = &lvar[33];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[96]);
}
{
PFrElement aux_dest = &lvar[34];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[97]);
}
{
PFrElement aux_dest = &lvar[35];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[98]);
}
{
PFrElement aux_dest = &lvar[36];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[99]);
}
{
PFrElement aux_dest = &lvar[37];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[100]);
}
{
PFrElement aux_dest = &lvar[38];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[101]);
}
{
PFrElement aux_dest = &lvar[39];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[102]);
}
{
PFrElement aux_dest = &lvar[40];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[103]);
}
{
PFrElement aux_dest = &lvar[41];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[104]);
}
{
PFrElement aux_dest = &lvar[42];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[105]);
}
{
PFrElement aux_dest = &lvar[43];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[106]);
}
{
PFrElement aux_dest = &lvar[44];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[107]);
}
{
PFrElement aux_dest = &lvar[45];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[108]);
}
{
PFrElement aux_dest = &lvar[46];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[109]);
}
{
PFrElement aux_dest = &lvar[47];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[110]);
}
{
PFrElement aux_dest = &lvar[48];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[111]);
}
{
PFrElement aux_dest = &lvar[49];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[112]);
}
{
PFrElement aux_dest = &lvar[50];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[113]);
}
{
PFrElement aux_dest = &lvar[51];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[114]);
}
{
PFrElement aux_dest = &lvar[52];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[115]);
}
{
PFrElement aux_dest = &lvar[53];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[116]);
}
{
PFrElement aux_dest = &lvar[54];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[117]);
}
{
PFrElement aux_dest = &lvar[55];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[118]);
}
{
PFrElement aux_dest = &lvar[56];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[119]);
}
{
PFrElement aux_dest = &lvar[57];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[120]);
}
{
PFrElement aux_dest = &lvar[58];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[121]);
}
{
PFrElement aux_dest = &lvar[59];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[122]);
}
{
PFrElement aux_dest = &lvar[60];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[123]);
}
{
PFrElement aux_dest = &lvar[61];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[124]);
}
{
PFrElement aux_dest = &lvar[62];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[125]);
}
{
PFrElement aux_dest = &lvar[63];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[126]);
}
{
PFrElement aux_dest = &lvar[64];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[127]);
}
{
PFrElement aux_dest = &lvar[65];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[65],&circuitConstants[32]); // line circom 50
while(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[65])) + 0)];
// load src
Fr_shr(&expaux[1],&circuitConstants[72],&lvar[65]); // line circom 51
Fr_band(&expaux[0],&expaux[1],&circuitConstants[2]); // line circom 51
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[65];
// load src
Fr_add(&expaux[0],&lvar[65],&circuitConstants[2]); // line circom 50
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[65],&circuitConstants[32]); // line circom 50
}
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void A_1_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 1;
ctx->componentMemory[coffset].templateName = "A";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void A_1_run(uint ctx_index,Circom_CalcWit* ctx){
FrElement* signalValues = ctx->signalValues;
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
FrElement* circuitConstants = ctx->circuitConstants;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
FrElement expaux[2];
FrElement lvar[3];
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
uint aux_create = 0;
int aux_cmp_num = 0+ctx_index+1;
uint csoffset = mySignalStart+1;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "h0";
K_0_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 32 ;
aux_cmp_num += 1;
}
}
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[2]);
}
{
PFrElement aux_dest = &lvar[2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[2],&circuitConstants[32]); // line circom 12
while(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &lvar[0];
// load src
cmp_index_ref_load = 0;
Fr_mul(&expaux[1],&lvar[1],&ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + ((1 * Fr_toInt(&lvar[2])) + 0)]); // line circom 13
Fr_add(&expaux[0],&lvar[0],&expaux[1]); // line circom 13
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
Fr_mul(&expaux[0],&lvar[1],&circuitConstants[3]); // line circom 14
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[2];
// load src
Fr_add(&expaux[0],&lvar[2],&circuitConstants[2]); // line circom 12
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[2],&circuitConstants[32]); // line circom 12
}
{{
Fr_eq(&expaux[0],&lvar[0],&signalValues[mySignalStart + 0]); // line circom 17
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 17. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
for (uint i = 0; i < 1; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void run(Circom_CalcWit* ctx){
A_1_create(1,0,ctx,"main",0);
A_1_run(0,ctx);
}

