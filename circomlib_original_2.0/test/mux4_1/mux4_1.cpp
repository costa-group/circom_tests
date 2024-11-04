#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "circom.hpp"
#include "calcwit.hpp"
void MultiMux4_0_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void MultiMux4_0_run(uint ctx_index,Circom_CalcWit* ctx);
void Mux4_1_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Mux4_1_run(uint ctx_index,Circom_CalcWit* ctx);
void Num2Bits_2_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Num2Bits_2_run(uint ctx_index,Circom_CalcWit* ctx);
void Constants_3_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Constants_3_run(uint ctx_index,Circom_CalcWit* ctx);
void Main_4_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Main_4_run(uint ctx_index,Circom_CalcWit* ctx);
Circom_TemplateFunction _functionTable[5] = { 
MultiMux4_0_run,
Mux4_1_run,
Num2Bits_2_run,
Constants_3_run,
Main_4_run };
Circom_TemplateFunction _functionTableParallel[5] = { 
NULL,
NULL,
NULL,
NULL,
NULL };
uint get_main_input_signal_start() {return 2;}

uint get_main_input_signal_no() {return 1;}

uint get_total_signal_no() {return 86;}

uint get_number_of_components() {return 5;}

uint get_size_of_input_hashmap() {return 256;}

uint get_size_of_witness() {return 86;}

uint get_size_of_constants() {return 31;}

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
void MultiMux4_0_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 0;
ctx->componentMemory[coffset].templateName = "MultiMux4";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 20;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void MultiMux4_0_run(uint ctx_index,Circom_CalcWit* ctx){
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
FrElement expaux[16];
FrElement lvar[2];
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
PFrElement aux_dest = &signalValues[mySignalStart + 37];
// load src
Fr_mul(&expaux[0],&signalValues[mySignalStart + 18],&signalValues[mySignalStart + 17]); // line circom 46
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 38];
// load src
Fr_mul(&expaux[0],&signalValues[mySignalStart + 19],&signalValues[mySignalStart + 17]); // line circom 48
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 39];
// load src
Fr_mul(&expaux[0],&signalValues[mySignalStart + 19],&signalValues[mySignalStart + 18]); // line circom 50
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 40];
// load src
Fr_mul(&expaux[0],&signalValues[mySignalStart + 39],&signalValues[mySignalStart + 17]); // line circom 52
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[0]); // line circom 55
while(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &signalValues[mySignalStart + 21];
// load src
Fr_sub(&expaux[15],&signalValues[mySignalStart + 16],&signalValues[mySignalStart + 15]); // line circom 57
Fr_sub(&expaux[14],&expaux[15],&signalValues[mySignalStart + 14]); // line circom 57
Fr_add(&expaux[13],&expaux[14],&signalValues[mySignalStart + 13]); // line circom 57
Fr_sub(&expaux[12],&expaux[13],&signalValues[mySignalStart + 12]); // line circom 57
Fr_add(&expaux[11],&expaux[12],&signalValues[mySignalStart + 11]); // line circom 57
Fr_add(&expaux[10],&expaux[11],&signalValues[mySignalStart + 10]); // line circom 57
Fr_sub(&expaux[9],&expaux[10],&signalValues[mySignalStart + 9]); // line circom 57
Fr_sub(&expaux[8],&expaux[9],&signalValues[mySignalStart + 8]); // line circom 57
Fr_add(&expaux[7],&expaux[8],&signalValues[mySignalStart + 7]); // line circom 57
Fr_add(&expaux[6],&expaux[7],&signalValues[mySignalStart + 6]); // line circom 57
Fr_sub(&expaux[5],&expaux[6],&signalValues[mySignalStart + 5]); // line circom 57
Fr_add(&expaux[4],&expaux[5],&signalValues[mySignalStart + 4]); // line circom 57
Fr_sub(&expaux[3],&expaux[4],&signalValues[mySignalStart + 3]); // line circom 57
Fr_sub(&expaux[2],&expaux[3],&signalValues[mySignalStart + 2]); // line circom 57
Fr_add(&expaux[1],&expaux[2],&signalValues[mySignalStart + 1]); // line circom 57
Fr_mul(&expaux[0],&expaux[1],&signalValues[mySignalStart + 40]); // line circom 57
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 22];
// load src
Fr_sub(&expaux[7],&signalValues[mySignalStart + 15],&signalValues[mySignalStart + 13]); // line circom 59
Fr_sub(&expaux[6],&expaux[7],&signalValues[mySignalStart + 11]); // line circom 59
Fr_add(&expaux[5],&expaux[6],&signalValues[mySignalStart + 9]); // line circom 59
Fr_sub(&expaux[4],&expaux[5],&signalValues[mySignalStart + 7]); // line circom 59
Fr_add(&expaux[3],&expaux[4],&signalValues[mySignalStart + 5]); // line circom 59
Fr_add(&expaux[2],&expaux[3],&signalValues[mySignalStart + 3]); // line circom 59
Fr_sub(&expaux[1],&expaux[2],&signalValues[mySignalStart + 1]); // line circom 59
Fr_mul(&expaux[0],&expaux[1],&signalValues[mySignalStart + 39]); // line circom 59
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 23];
// load src
Fr_sub(&expaux[7],&signalValues[mySignalStart + 14],&signalValues[mySignalStart + 13]); // line circom 60
Fr_sub(&expaux[6],&expaux[7],&signalValues[mySignalStart + 10]); // line circom 60
Fr_add(&expaux[5],&expaux[6],&signalValues[mySignalStart + 9]); // line circom 60
Fr_sub(&expaux[4],&expaux[5],&signalValues[mySignalStart + 6]); // line circom 60
Fr_add(&expaux[3],&expaux[4],&signalValues[mySignalStart + 5]); // line circom 60
Fr_add(&expaux[2],&expaux[3],&signalValues[mySignalStart + 2]); // line circom 60
Fr_sub(&expaux[1],&expaux[2],&signalValues[mySignalStart + 1]); // line circom 60
Fr_mul(&expaux[0],&expaux[1],&signalValues[mySignalStart + 38]); // line circom 60
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 24];
// load src
Fr_sub(&expaux[7],&signalValues[mySignalStart + 12],&signalValues[mySignalStart + 11]); // line circom 61
Fr_sub(&expaux[6],&expaux[7],&signalValues[mySignalStart + 10]); // line circom 61
Fr_add(&expaux[5],&expaux[6],&signalValues[mySignalStart + 9]); // line circom 61
Fr_sub(&expaux[4],&expaux[5],&signalValues[mySignalStart + 4]); // line circom 61
Fr_add(&expaux[3],&expaux[4],&signalValues[mySignalStart + 3]); // line circom 61
Fr_add(&expaux[2],&expaux[3],&signalValues[mySignalStart + 2]); // line circom 61
Fr_sub(&expaux[1],&expaux[2],&signalValues[mySignalStart + 1]); // line circom 61
Fr_mul(&expaux[0],&expaux[1],&signalValues[mySignalStart + 37]); // line circom 61
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 25];
// load src
Fr_sub(&expaux[3],&signalValues[mySignalStart + 13],&signalValues[mySignalStart + 9]); // line circom 62
Fr_sub(&expaux[2],&expaux[3],&signalValues[mySignalStart + 5]); // line circom 62
Fr_add(&expaux[1],&expaux[2],&signalValues[mySignalStart + 1]); // line circom 62
Fr_mul(&expaux[0],&expaux[1],&signalValues[mySignalStart + 19]); // line circom 62
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 26];
// load src
Fr_sub(&expaux[3],&signalValues[mySignalStart + 11],&signalValues[mySignalStart + 9]); // line circom 63
Fr_sub(&expaux[2],&expaux[3],&signalValues[mySignalStart + 3]); // line circom 63
Fr_add(&expaux[1],&expaux[2],&signalValues[mySignalStart + 1]); // line circom 63
Fr_mul(&expaux[0],&expaux[1],&signalValues[mySignalStart + 18]); // line circom 63
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 27];
// load src
Fr_sub(&expaux[3],&signalValues[mySignalStart + 10],&signalValues[mySignalStart + 9]); // line circom 64
Fr_sub(&expaux[2],&expaux[3],&signalValues[mySignalStart + 2]); // line circom 64
Fr_add(&expaux[1],&expaux[2],&signalValues[mySignalStart + 1]); // line circom 64
Fr_mul(&expaux[0],&expaux[1],&signalValues[mySignalStart + 17]); // line circom 64
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 28];
// load src
Fr_sub(&expaux[0],&signalValues[mySignalStart + 9],&signalValues[mySignalStart + 1]); // line circom 65
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 29];
// load src
Fr_sub(&expaux[7],&signalValues[mySignalStart + 8],&signalValues[mySignalStart + 7]); // line circom 67
Fr_sub(&expaux[6],&expaux[7],&signalValues[mySignalStart + 6]); // line circom 67
Fr_add(&expaux[5],&expaux[6],&signalValues[mySignalStart + 5]); // line circom 67
Fr_sub(&expaux[4],&expaux[5],&signalValues[mySignalStart + 4]); // line circom 67
Fr_add(&expaux[3],&expaux[4],&signalValues[mySignalStart + 3]); // line circom 67
Fr_add(&expaux[2],&expaux[3],&signalValues[mySignalStart + 2]); // line circom 67
Fr_sub(&expaux[1],&expaux[2],&signalValues[mySignalStart + 1]); // line circom 67
Fr_mul(&expaux[0],&expaux[1],&signalValues[mySignalStart + 40]); // line circom 67
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 30];
// load src
Fr_sub(&expaux[3],&signalValues[mySignalStart + 7],&signalValues[mySignalStart + 5]); // line circom 68
Fr_sub(&expaux[2],&expaux[3],&signalValues[mySignalStart + 3]); // line circom 68
Fr_add(&expaux[1],&expaux[2],&signalValues[mySignalStart + 1]); // line circom 68
Fr_mul(&expaux[0],&expaux[1],&signalValues[mySignalStart + 39]); // line circom 68
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 31];
// load src
Fr_sub(&expaux[3],&signalValues[mySignalStart + 6],&signalValues[mySignalStart + 5]); // line circom 69
Fr_sub(&expaux[2],&expaux[3],&signalValues[mySignalStart + 2]); // line circom 69
Fr_add(&expaux[1],&expaux[2],&signalValues[mySignalStart + 1]); // line circom 69
Fr_mul(&expaux[0],&expaux[1],&signalValues[mySignalStart + 38]); // line circom 69
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 32];
// load src
Fr_sub(&expaux[3],&signalValues[mySignalStart + 4],&signalValues[mySignalStart + 3]); // line circom 70
Fr_sub(&expaux[2],&expaux[3],&signalValues[mySignalStart + 2]); // line circom 70
Fr_add(&expaux[1],&expaux[2],&signalValues[mySignalStart + 1]); // line circom 70
Fr_mul(&expaux[0],&expaux[1],&signalValues[mySignalStart + 37]); // line circom 70
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 33];
// load src
Fr_sub(&expaux[1],&signalValues[mySignalStart + 5],&signalValues[mySignalStart + 1]); // line circom 71
Fr_mul(&expaux[0],&expaux[1],&signalValues[mySignalStart + 19]); // line circom 71
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 34];
// load src
Fr_sub(&expaux[1],&signalValues[mySignalStart + 3],&signalValues[mySignalStart + 1]); // line circom 72
Fr_mul(&expaux[0],&expaux[1],&signalValues[mySignalStart + 18]); // line circom 72
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 35];
// load src
Fr_sub(&expaux[1],&signalValues[mySignalStart + 2],&signalValues[mySignalStart + 1]); // line circom 73
Fr_mul(&expaux[0],&expaux[1],&signalValues[mySignalStart + 17]); // line circom 73
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 36];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 1]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
Fr_add(&expaux[8],&signalValues[mySignalStart + 21],&signalValues[mySignalStart + 22]); // line circom 76
Fr_add(&expaux[7],&expaux[8],&signalValues[mySignalStart + 23]); // line circom 76
Fr_add(&expaux[6],&expaux[7],&signalValues[mySignalStart + 24]); // line circom 76
Fr_add(&expaux[5],&expaux[6],&signalValues[mySignalStart + 25]); // line circom 76
Fr_add(&expaux[4],&expaux[5],&signalValues[mySignalStart + 26]); // line circom 76
Fr_add(&expaux[3],&expaux[4],&signalValues[mySignalStart + 27]); // line circom 76
Fr_add(&expaux[2],&expaux[3],&signalValues[mySignalStart + 28]); // line circom 76
Fr_mul(&expaux[1],&expaux[2],&signalValues[mySignalStart + 20]); // line circom 76
Fr_add(&expaux[8],&signalValues[mySignalStart + 29],&signalValues[mySignalStart + 30]); // line circom 77
Fr_add(&expaux[7],&expaux[8],&signalValues[mySignalStart + 31]); // line circom 77
Fr_add(&expaux[6],&expaux[7],&signalValues[mySignalStart + 32]); // line circom 77
Fr_add(&expaux[5],&expaux[6],&signalValues[mySignalStart + 33]); // line circom 77
Fr_add(&expaux[4],&expaux[5],&signalValues[mySignalStart + 34]); // line circom 77
Fr_add(&expaux[3],&expaux[4],&signalValues[mySignalStart + 35]); // line circom 77
Fr_add(&expaux[2],&expaux[3],&signalValues[mySignalStart + 36]); // line circom 77
Fr_add(&expaux[0],&expaux[1],&expaux[2]); // line circom 76
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[0]); // line circom 55
}
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void Mux4_1_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 1;
ctx->componentMemory[coffset].templateName = "Mux4";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 20;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void Mux4_1_run(uint ctx_index,Circom_CalcWit* ctx){
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
FrElement lvar[1];
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
uint aux_create = 0;
int aux_cmp_num = 0+ctx_index+1;
uint csoffset = mySignalStart+21;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "mux";
MultiMux4_0_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 41 ;
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
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[16]); // line circom 110
while(Fr_isTrue(&expaux[0])){
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ((0 + (1 * Fr_toInt(&lvar[0]))) + 1)];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[0])) + 1)]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
MultiMux4_0_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
PFrElement aux_dest = &lvar[0];
// load src
Fr_add(&expaux[0],&lvar[0],&circuitConstants[0]); // line circom 110
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[16]); // line circom 110
}
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[14]); // line circom 114
while(Fr_isTrue(&expaux[0])){
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ((1 * Fr_toInt(&lvar[0])) + 17)];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[0])) + 17)]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
MultiMux4_0_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
PFrElement aux_dest = &lvar[0];
// load src
Fr_add(&expaux[0],&lvar[0],&circuitConstants[0]); // line circom 114
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[14]); // line circom 114
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
cmp_index_ref_load = 0;
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 0]);
}
for (uint i = 0; i < 1; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void Num2Bits_2_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 2;
ctx->componentMemory[coffset].templateName = "Num2Bits";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void Num2Bits_2_run(uint ctx_index,Circom_CalcWit* ctx){
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
FrElement expaux[4];
FrElement lvar[4];
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[14]);
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
Fr_copy(aux_dest,&circuitConstants[0]);
}
{
PFrElement aux_dest = &lvar[3];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[3],&circuitConstants[14]); // line circom 31
while(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[3])) + 0)];
// load src
Fr_shr(&expaux[1],&signalValues[mySignalStart + 4],&lvar[3]); // line circom 32
Fr_band(&expaux[0],&expaux[1],&circuitConstants[0]); // line circom 32
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_sub(&expaux[2],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[3])) + 0)],&circuitConstants[0]); // line circom 33
Fr_mul(&expaux[1],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[3])) + 0)],&expaux[2]); // line circom 33
{{
Fr_eq(&expaux[0],&expaux[1],&circuitConstants[1]); // line circom 33
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 33. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
{
PFrElement aux_dest = &lvar[1];
// load src
Fr_mul(&expaux[1],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[3])) + 0)],&lvar[2]); // line circom 34
Fr_add(&expaux[0],&lvar[1],&expaux[1]); // line circom 34
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[2];
// load src
Fr_add(&expaux[0],&lvar[2],&lvar[2]); // line circom 35
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[3];
// load src
Fr_add(&expaux[0],&lvar[3],&circuitConstants[0]); // line circom 31
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[3],&circuitConstants[14]); // line circom 31
}
{{
Fr_eq(&expaux[0],&lvar[1],&signalValues[mySignalStart + 4]); // line circom 38
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 38. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void Constants_3_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 3;
ctx->componentMemory[coffset].templateName = "Constants";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 0;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
Constants_3_run(coffset,ctx);
}

void Constants_3_run(uint ctx_index,Circom_CalcWit* ctx){
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
FrElement expaux[1];
FrElement lvar[1];
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[17]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[18]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[19]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 3];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[6]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 4];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[20]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 5];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[21]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 6];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[22]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 7];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[23]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 8];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[24]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 9];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[25]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 10];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[26]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 11];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[27]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 12];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[28]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 13];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[23]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 14];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[29]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 15];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[30]);
}
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void Main_4_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 4;
ctx->componentMemory[coffset].templateName = "Main";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[3]{0};
}

void Main_4_run(uint ctx_index,Circom_CalcWit* ctx){
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
FrElement lvar[1];
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
uint aux_create = 0;
int aux_cmp_num = 1+ctx_index+1;
uint csoffset = mySignalStart+18;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "mux";
Mux4_1_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 62 ;
aux_cmp_num += 2;
}
}
{
uint aux_create = 1;
int aux_cmp_num = 3+ctx_index+1;
uint csoffset = mySignalStart+80;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "n2b";
Num2Bits_2_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 5 ;
aux_cmp_num += 1;
}
}
{
uint aux_create = 2;
int aux_cmp_num = 0+ctx_index+1;
uint csoffset = mySignalStart+2;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "cst";
Constants_3_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 16 ;
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
uint cmp_index_ref = 1;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 4];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 1]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Num2Bits_2_run(mySubcomponents[cmp_index_ref],ctx);
}
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[14]); // line circom 46
while(Fr_isTrue(&expaux[0])){
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ((1 * Fr_toInt(&lvar[0])) + 17)];
// load src
cmp_index_ref_load = 1;
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[1]].signalStart + ((1 * Fr_toInt(&lvar[0])) + 0)]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
Mux4_1_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
PFrElement aux_dest = &lvar[0];
// load src
Fr_add(&expaux[0],&lvar[0],&circuitConstants[0]); // line circom 46
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[14]); // line circom 46
}
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[16]); // line circom 49
while(Fr_isTrue(&expaux[0])){
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ((1 * Fr_toInt(&lvar[0])) + 1)];
// load src
cmp_index_ref_load = 2;
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[2]].signalStart + ((1 * Fr_toInt(&lvar[0])) + 0)]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
Mux4_1_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
PFrElement aux_dest = &lvar[0];
// load src
Fr_add(&expaux[0],&lvar[0],&circuitConstants[0]); // line circom 49
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[16]); // line circom 49
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
cmp_index_ref_load = 0;
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 0]);
}
for (uint i = 0; i < 3; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void run(Circom_CalcWit* ctx){
Main_4_create(1,0,ctx,"main",0);
Main_4_run(0,ctx);
}

