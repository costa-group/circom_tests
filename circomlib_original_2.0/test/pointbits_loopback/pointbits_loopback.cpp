#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "circom.hpp"
#include "calcwit.hpp"
void Num2Bits_0_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Num2Bits_0_run(uint ctx_index,Circom_CalcWit* ctx);
void Num2Bits_1_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Num2Bits_1_run(uint ctx_index,Circom_CalcWit* ctx);
void CompConstant_2_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void CompConstant_2_run(uint ctx_index,Circom_CalcWit* ctx);
void AliasCheck_3_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void AliasCheck_3_run(uint ctx_index,Circom_CalcWit* ctx);
void CompConstant_4_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void CompConstant_4_run(uint ctx_index,Circom_CalcWit* ctx);
void Point2Bits_Strict_5_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Point2Bits_Strict_5_run(uint ctx_index,Circom_CalcWit* ctx);
void Bits2Num_6_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Bits2Num_6_run(uint ctx_index,Circom_CalcWit* ctx);
void BabyCheck_7_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void BabyCheck_7_run(uint ctx_index,Circom_CalcWit* ctx);
void Bits2Point_Strict_8_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Bits2Point_Strict_8_run(uint ctx_index,Circom_CalcWit* ctx);
void Main_9_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Main_9_run(uint ctx_index,Circom_CalcWit* ctx);
void sqrt_0(Circom_CalcWit* ctx,FrElement* lvar,uint componentFather,FrElement* destination,int destination_size);
Circom_TemplateFunction _functionTable[10] = { 
Num2Bits_0_run,
Num2Bits_1_run,
CompConstant_2_run,
AliasCheck_3_run,
CompConstant_4_run,
Point2Bits_Strict_5_run,
Bits2Num_6_run,
BabyCheck_7_run,
Bits2Point_Strict_8_run,
Main_9_run };
Circom_TemplateFunction _functionTableParallel[10] = { 
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL };
uint get_main_input_signal_start() {return 1;}

uint get_main_input_signal_no() {return 2;}

uint get_total_signal_no() {return 5673;}

uint get_number_of_components() {return 24;}

uint get_size_of_input_hashmap() {return 256;}

uint get_size_of_witness() {return 5673;}

uint get_size_of_constants() {return 16;}

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
void sqrt_0(Circom_CalcWit* ctx,FrElement* lvar,uint componentFather,FrElement* destination,int destination_size){
FrElement* circuitConstants = ctx->circuitConstants;
FrElement expaux[5];
std::string myTemplateName = "sqrt";
u64 myId = componentFather;
{{
Fr_eq(&expaux[0],&lvar[0],&circuitConstants[1]); // line circom 29
}}
if(Fr_isTrue(&expaux[0])){
// return bucket
Fr_copy(destination,&circuitConstants[1]);
return;
}
{
PFrElement aux_dest = &lvar[1];
// load src
Fr_neg(&expaux[2],&circuitConstants[2]); // line circom 34
Fr_shr(&expaux[1],&expaux[2],&circuitConstants[2]); // line circom 34
Fr_pow(&expaux[0],&lvar[0],&expaux[1]); // line circom 34
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_neq(&expaux[0],&lvar[1],&circuitConstants[2]); // line circom 36
if(Fr_isTrue(&expaux[0])){
// return bucket
Fr_copy(destination,&circuitConstants[1]);
return;
}
{
PFrElement aux_dest = &lvar[2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[13]);
}
{
PFrElement aux_dest = &lvar[3];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[14]);
}
{
PFrElement aux_dest = &lvar[4];
// load src
Fr_pow(&expaux[0],&lvar[0],&circuitConstants[15]); // line circom 40
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[5];
// load src
Fr_add(&expaux[2],&circuitConstants[15],&circuitConstants[2]); // line circom 41
Fr_shr(&expaux[1],&expaux[2],&circuitConstants[2]); // line circom 41
Fr_pow(&expaux[0],&lvar[0],&expaux[1]); // line circom 41
// end load src
Fr_copy(aux_dest,&expaux[0]);
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
Fr_neq(&expaux[1],&lvar[5],&circuitConstants[1]); // line circom 47
Fr_neq(&expaux[2],&lvar[4],&circuitConstants[2]); // line circom 47
Fr_land(&expaux[0],&expaux[1],&expaux[2]); // line circom 47
while(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &lvar[6];
// load src
Fr_mul(&expaux[0],&lvar[4],&lvar[4]); // line circom 48
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[7];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[2]);
}
Fr_neq(&expaux[0],&lvar[6],&circuitConstants[2]); // line circom 50
while(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &lvar[7];
// load src
Fr_add(&expaux[0],&lvar[7],&circuitConstants[2]); // line circom 51
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[6];
// load src
Fr_mul(&expaux[0],&lvar[6],&lvar[6]); // line circom 52
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_neq(&expaux[0],&lvar[6],&circuitConstants[2]); // line circom 50
}
{
PFrElement aux_dest = &lvar[8];
// load src
// end load src
Fr_copy(aux_dest,&lvar[3]);
}
{
PFrElement aux_dest = &lvar[9];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_sub(&expaux[2],&lvar[2],&lvar[7]); // line circom 57
Fr_sub(&expaux[1],&expaux[2],&circuitConstants[2]); // line circom 57
Fr_lt(&expaux[0],&lvar[9],&expaux[1]); // line circom 57
while(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &lvar[8];
// load src
Fr_mul(&expaux[0],&lvar[8],&lvar[8]); // line circom 57
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[9];
// load src
Fr_add(&expaux[0],&lvar[9],&circuitConstants[2]); // line circom 57
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_sub(&expaux[2],&lvar[2],&lvar[7]); // line circom 57
Fr_sub(&expaux[1],&expaux[2],&circuitConstants[2]); // line circom 57
Fr_lt(&expaux[0],&lvar[9],&expaux[1]); // line circom 57
}
{
PFrElement aux_dest = &lvar[2];
// load src
// end load src
Fr_copy(aux_dest,&lvar[7]);
}
{
PFrElement aux_dest = &lvar[3];
// load src
Fr_mul(&expaux[0],&lvar[8],&lvar[8]); // line circom 60
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[4];
// load src
Fr_mul(&expaux[0],&lvar[4],&lvar[3]); // line circom 61
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[5];
// load src
Fr_mul(&expaux[0],&lvar[5],&lvar[8]); // line circom 62
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_neq(&expaux[1],&lvar[5],&circuitConstants[1]); // line circom 47
Fr_neq(&expaux[2],&lvar[4],&circuitConstants[2]); // line circom 47
Fr_land(&expaux[0],&expaux[1],&expaux[2]); // line circom 47
}
Fr_lt(&expaux[0],&lvar[5],&circuitConstants[1]); // line circom 65
if(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &lvar[5];
// load src
Fr_neg(&expaux[0],&lvar[5]); // line circom 66
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
}
// return bucket
Fr_copy(destination,&lvar[5]);
return;
}

// template declarations
void Num2Bits_0_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 0;
ctx->componentMemory[coffset].templateName = "Num2Bits";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void Num2Bits_0_run(uint ctx_index,Circom_CalcWit* ctx){
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
Fr_copy(aux_dest,&circuitConstants[2]);
}
{
PFrElement aux_dest = &lvar[3];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[3],&circuitConstants[0]); // line circom 31
while(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[3])) + 0)];
// load src
Fr_shr(&expaux[1],&signalValues[mySignalStart + 254],&lvar[3]); // line circom 32
Fr_band(&expaux[0],&expaux[1],&circuitConstants[2]); // line circom 32
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_sub(&expaux[2],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[3])) + 0)],&circuitConstants[2]); // line circom 33
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
Fr_add(&expaux[0],&lvar[3],&circuitConstants[2]); // line circom 31
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[3],&circuitConstants[0]); // line circom 31
}
{{
Fr_eq(&expaux[0],&lvar[1],&signalValues[mySignalStart + 254]); // line circom 38
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 38. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void Num2Bits_1_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 1;
ctx->componentMemory[coffset].templateName = "Num2Bits";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void Num2Bits_1_run(uint ctx_index,Circom_CalcWit* ctx){
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
Fr_copy(aux_dest,&circuitConstants[3]);
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
Fr_copy(aux_dest,&circuitConstants[2]);
}
{
PFrElement aux_dest = &lvar[3];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[3],&circuitConstants[3]); // line circom 31
while(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[3])) + 0)];
// load src
Fr_shr(&expaux[1],&signalValues[mySignalStart + 135],&lvar[3]); // line circom 32
Fr_band(&expaux[0],&expaux[1],&circuitConstants[2]); // line circom 32
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_sub(&expaux[2],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[3])) + 0)],&circuitConstants[2]); // line circom 33
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
Fr_add(&expaux[0],&lvar[3],&circuitConstants[2]); // line circom 31
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[3],&circuitConstants[3]); // line circom 31
}
{{
Fr_eq(&expaux[0],&lvar[1],&signalValues[mySignalStart + 135]); // line circom 38
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 38. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void CompConstant_2_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 2;
ctx->componentMemory[coffset].templateName = "CompConstant";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 254;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void CompConstant_2_run(uint ctx_index,Circom_CalcWit* ctx){
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
FrElement expaux[6];
FrElement lvar[10];
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[4]);
}
{
uint aux_create = 0;
int aux_cmp_num = 0+ctx_index+1;
uint csoffset = mySignalStart+383;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "num2bits";
Num2Bits_1_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 136 ;
aux_cmp_num += 1;
}
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
Fr_copy(aux_dest,&circuitConstants[5]);
}
{
PFrElement aux_dest = &lvar[7];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[2]);
}
{
PFrElement aux_dest = &lvar[8];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[2]);
}
{
PFrElement aux_dest = &lvar[9];
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
Fr_lt(&expaux[0],&lvar[9],&circuitConstants[6]); // line circom 44
while(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &lvar[1];
// load src
Fr_mul(&expaux[3],&lvar[9],&circuitConstants[7]); // line circom 45
Fr_shr(&expaux[1],&circuitConstants[4],&expaux[3]); // line circom 45
Fr_band(&expaux[0],&expaux[1],&circuitConstants[2]); // line circom 45
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[2];
// load src
Fr_mul(&expaux[4],&lvar[9],&circuitConstants[7]); // line circom 46
Fr_add(&expaux[3],&expaux[4],&circuitConstants[2]); // line circom 46
Fr_shr(&expaux[1],&circuitConstants[4],&expaux[3]); // line circom 46
Fr_band(&expaux[0],&expaux[1],&circuitConstants[2]); // line circom 46
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[3];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + ((1 * (Fr_toInt(&lvar[9]) * 2)) + 1)]);
}
{
PFrElement aux_dest = &lvar[4];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + ((1 * ((Fr_toInt(&lvar[9]) * 2) + 1)) + 1)]);
}
{{
Fr_eq(&expaux[1],&lvar[2],&circuitConstants[1]); // line circom 50
}}
{{
Fr_eq(&expaux[2],&lvar[1],&circuitConstants[1]); // line circom 50
}}
Fr_land(&expaux[0],&expaux[1],&expaux[2]); // line circom 50
if(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[9])) + 255)];
// load src
Fr_neg(&expaux[4],&lvar[6]); // line circom 51
Fr_mul(&expaux[3],&expaux[4],&lvar[4]); // line circom 51
Fr_mul(&expaux[2],&expaux[3],&lvar[3]); // line circom 51
Fr_mul(&expaux[3],&lvar[6],&lvar[4]); // line circom 51
Fr_add(&expaux[1],&expaux[2],&expaux[3]); // line circom 51
Fr_mul(&expaux[2],&lvar[6],&lvar[3]); // line circom 51
Fr_add(&expaux[0],&expaux[1],&expaux[2]); // line circom 51
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
}else{
{{
Fr_eq(&expaux[1],&lvar[2],&circuitConstants[1]); // line circom 52
}}
{{
Fr_eq(&expaux[2],&lvar[1],&circuitConstants[2]); // line circom 52
}}
Fr_land(&expaux[0],&expaux[1],&expaux[2]); // line circom 52
if(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[9])) + 255)];
// load src
Fr_mul(&expaux[5],&lvar[7],&lvar[4]); // line circom 53
Fr_mul(&expaux[4],&expaux[5],&lvar[3]); // line circom 53
Fr_mul(&expaux[5],&lvar[7],&lvar[3]); // line circom 53
Fr_sub(&expaux[3],&expaux[4],&expaux[5]); // line circom 53
Fr_mul(&expaux[4],&lvar[6],&lvar[4]); // line circom 53
Fr_add(&expaux[2],&expaux[3],&expaux[4]); // line circom 53
Fr_mul(&expaux[3],&lvar[7],&lvar[4]); // line circom 53
Fr_sub(&expaux[1],&expaux[2],&expaux[3]); // line circom 53
Fr_add(&expaux[0],&expaux[1],&lvar[7]); // line circom 53
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
}else{
{{
Fr_eq(&expaux[2],&lvar[1],&circuitConstants[1]); // line circom 54
}}
Fr_land(&expaux[0],&circuitConstants[2],&expaux[2]); // line circom 54
if(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[9])) + 255)];
// load src
Fr_mul(&expaux[3],&lvar[6],&lvar[4]); // line circom 55
Fr_mul(&expaux[2],&expaux[3],&lvar[3]); // line circom 55
Fr_mul(&expaux[3],&lvar[7],&lvar[4]); // line circom 55
Fr_sub(&expaux[1],&expaux[2],&expaux[3]); // line circom 55
Fr_add(&expaux[0],&expaux[1],&lvar[7]); // line circom 55
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
}else{
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[9])) + 255)];
// load src
Fr_neg(&expaux[3],&lvar[7]); // line circom 57
Fr_mul(&expaux[2],&expaux[3],&lvar[4]); // line circom 57
Fr_mul(&expaux[1],&expaux[2],&lvar[3]); // line circom 57
Fr_add(&expaux[0],&expaux[1],&lvar[7]); // line circom 57
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
}
}
}
{
PFrElement aux_dest = &lvar[5];
// load src
Fr_add(&expaux[0],&lvar[5],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[9])) + 255)]); // line circom 60
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[6];
// load src
Fr_sub(&expaux[0],&lvar[6],&lvar[8]); // line circom 62
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[7];
// load src
Fr_add(&expaux[0],&lvar[7],&lvar[8]); // line circom 63
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[8];
// load src
Fr_mul(&expaux[0],&lvar[8],&circuitConstants[7]); // line circom 64
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[9];
// load src
Fr_add(&expaux[0],&lvar[9],&circuitConstants[2]); // line circom 44
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[9],&circuitConstants[6]); // line circom 44
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 382];
// load src
// end load src
Fr_copy(aux_dest,&lvar[5]);
}
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 135];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 382]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Num2Bits_1_run(mySubcomponents[cmp_index_ref],ctx);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
cmp_index_ref_load = 0;
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 127]);
}
for (uint i = 0; i < 1; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void AliasCheck_3_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 3;
ctx->componentMemory[coffset].templateName = "AliasCheck";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 254;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void AliasCheck_3_run(uint ctx_index,Circom_CalcWit* ctx){
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
uint csoffset = mySignalStart+254;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "compConstant";
CompConstant_2_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 519 ;
aux_cmp_num += 2;
}
}
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[0]); // line circom 30
while(Fr_isTrue(&expaux[0])){
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ((1 * Fr_toInt(&lvar[0])) + 1)];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[0])) + 0)]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
CompConstant_2_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
PFrElement aux_dest = &lvar[0];
// load src
Fr_add(&expaux[0],&lvar[0],&circuitConstants[2]); // line circom 30
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[0]); // line circom 30
}
cmp_index_ref_load = 0;
{{
Fr_eq(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 0],&circuitConstants[1]); // line circom 32
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 32. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
for (uint i = 0; i < 1; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void CompConstant_4_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 4;
ctx->componentMemory[coffset].templateName = "CompConstant";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 254;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void CompConstant_4_run(uint ctx_index,Circom_CalcWit* ctx){
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
FrElement expaux[6];
FrElement lvar[10];
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[8]);
}
{
uint aux_create = 0;
int aux_cmp_num = 0+ctx_index+1;
uint csoffset = mySignalStart+383;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "num2bits";
Num2Bits_1_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 136 ;
aux_cmp_num += 1;
}
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
Fr_copy(aux_dest,&circuitConstants[5]);
}
{
PFrElement aux_dest = &lvar[7];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[2]);
}
{
PFrElement aux_dest = &lvar[8];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[2]);
}
{
PFrElement aux_dest = &lvar[9];
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
Fr_lt(&expaux[0],&lvar[9],&circuitConstants[6]); // line circom 44
while(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &lvar[1];
// load src
Fr_mul(&expaux[3],&lvar[9],&circuitConstants[7]); // line circom 45
Fr_shr(&expaux[1],&circuitConstants[8],&expaux[3]); // line circom 45
Fr_band(&expaux[0],&expaux[1],&circuitConstants[2]); // line circom 45
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[2];
// load src
Fr_mul(&expaux[4],&lvar[9],&circuitConstants[7]); // line circom 46
Fr_add(&expaux[3],&expaux[4],&circuitConstants[2]); // line circom 46
Fr_shr(&expaux[1],&circuitConstants[8],&expaux[3]); // line circom 46
Fr_band(&expaux[0],&expaux[1],&circuitConstants[2]); // line circom 46
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[3];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + ((1 * (Fr_toInt(&lvar[9]) * 2)) + 1)]);
}
{
PFrElement aux_dest = &lvar[4];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + ((1 * ((Fr_toInt(&lvar[9]) * 2) + 1)) + 1)]);
}
{{
Fr_eq(&expaux[1],&lvar[2],&circuitConstants[1]); // line circom 50
}}
{{
Fr_eq(&expaux[2],&lvar[1],&circuitConstants[1]); // line circom 50
}}
Fr_land(&expaux[0],&expaux[1],&expaux[2]); // line circom 50
if(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[9])) + 255)];
// load src
Fr_neg(&expaux[4],&lvar[6]); // line circom 51
Fr_mul(&expaux[3],&expaux[4],&lvar[4]); // line circom 51
Fr_mul(&expaux[2],&expaux[3],&lvar[3]); // line circom 51
Fr_mul(&expaux[3],&lvar[6],&lvar[4]); // line circom 51
Fr_add(&expaux[1],&expaux[2],&expaux[3]); // line circom 51
Fr_mul(&expaux[2],&lvar[6],&lvar[3]); // line circom 51
Fr_add(&expaux[0],&expaux[1],&expaux[2]); // line circom 51
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
}else{
{{
Fr_eq(&expaux[1],&lvar[2],&circuitConstants[1]); // line circom 52
}}
{{
Fr_eq(&expaux[2],&lvar[1],&circuitConstants[2]); // line circom 52
}}
Fr_land(&expaux[0],&expaux[1],&expaux[2]); // line circom 52
if(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[9])) + 255)];
// load src
Fr_mul(&expaux[5],&lvar[7],&lvar[4]); // line circom 53
Fr_mul(&expaux[4],&expaux[5],&lvar[3]); // line circom 53
Fr_mul(&expaux[5],&lvar[7],&lvar[3]); // line circom 53
Fr_sub(&expaux[3],&expaux[4],&expaux[5]); // line circom 53
Fr_mul(&expaux[4],&lvar[6],&lvar[4]); // line circom 53
Fr_add(&expaux[2],&expaux[3],&expaux[4]); // line circom 53
Fr_mul(&expaux[3],&lvar[7],&lvar[4]); // line circom 53
Fr_sub(&expaux[1],&expaux[2],&expaux[3]); // line circom 53
Fr_add(&expaux[0],&expaux[1],&lvar[7]); // line circom 53
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
}else{
{{
Fr_eq(&expaux[2],&lvar[1],&circuitConstants[1]); // line circom 54
}}
Fr_land(&expaux[0],&circuitConstants[2],&expaux[2]); // line circom 54
if(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[9])) + 255)];
// load src
Fr_mul(&expaux[3],&lvar[6],&lvar[4]); // line circom 55
Fr_mul(&expaux[2],&expaux[3],&lvar[3]); // line circom 55
Fr_mul(&expaux[3],&lvar[7],&lvar[4]); // line circom 55
Fr_sub(&expaux[1],&expaux[2],&expaux[3]); // line circom 55
Fr_add(&expaux[0],&expaux[1],&lvar[7]); // line circom 55
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
}else{
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[9])) + 255)];
// load src
Fr_neg(&expaux[3],&lvar[7]); // line circom 57
Fr_mul(&expaux[2],&expaux[3],&lvar[4]); // line circom 57
Fr_mul(&expaux[1],&expaux[2],&lvar[3]); // line circom 57
Fr_add(&expaux[0],&expaux[1],&lvar[7]); // line circom 57
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
}
}
}
{
PFrElement aux_dest = &lvar[5];
// load src
Fr_add(&expaux[0],&lvar[5],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[9])) + 255)]); // line circom 60
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[6];
// load src
Fr_sub(&expaux[0],&lvar[6],&lvar[8]); // line circom 62
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[7];
// load src
Fr_add(&expaux[0],&lvar[7],&lvar[8]); // line circom 63
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[8];
// load src
Fr_mul(&expaux[0],&lvar[8],&circuitConstants[7]); // line circom 64
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[9];
// load src
Fr_add(&expaux[0],&lvar[9],&circuitConstants[2]); // line circom 44
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[9],&circuitConstants[6]); // line circom 44
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 382];
// load src
// end load src
Fr_copy(aux_dest,&lvar[5]);
}
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 135];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 382]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Num2Bits_1_run(mySubcomponents[cmp_index_ref],ctx);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
cmp_index_ref_load = 0;
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 127]);
}
for (uint i = 0; i < 1; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void Point2Bits_Strict_5_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 5;
ctx->componentMemory[coffset].templateName = "Point2Bits_Strict";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 2;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[5]{0};
}

void Point2Bits_Strict_5_run(uint ctx_index,Circom_CalcWit* ctx){
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
int aux_cmp_num = 6+ctx_index+1;
uint csoffset = mySignalStart+1804;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "n2bX";
Num2Bits_0_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 255 ;
aux_cmp_num += 1;
}
}
{
uint aux_create = 1;
int aux_cmp_num = 7+ctx_index+1;
uint csoffset = mySignalStart+2059;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "n2bY";
Num2Bits_0_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 255 ;
aux_cmp_num += 1;
}
}
{
uint aux_create = 2;
int aux_cmp_num = 0+ctx_index+1;
uint csoffset = mySignalStart+258;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "aliasCheckX";
AliasCheck_3_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 773 ;
aux_cmp_num += 3;
}
}
{
uint aux_create = 3;
int aux_cmp_num = 3+ctx_index+1;
uint csoffset = mySignalStart+1031;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "aliasCheckY";
AliasCheck_3_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 773 ;
aux_cmp_num += 3;
}
}
{
uint aux_create = 4;
int aux_cmp_num = 8+ctx_index+1;
uint csoffset = mySignalStart+2314;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "signCalc";
CompConstant_4_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 519 ;
aux_cmp_num += 2;
}
}
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 254];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 256]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Num2Bits_0_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 1;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 254];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 257]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Num2Bits_0_run(mySubcomponents[cmp_index_ref],ctx);
}
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[0]); // line circom 149
while(Fr_isTrue(&expaux[0])){
{
uint cmp_index_ref = 2;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ((1 * Fr_toInt(&lvar[0])) + 0)];
// load src
cmp_index_ref_load = 0;
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + ((1 * Fr_toInt(&lvar[0])) + 0)]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
AliasCheck_3_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
uint cmp_index_ref = 3;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ((1 * Fr_toInt(&lvar[0])) + 0)];
// load src
cmp_index_ref_load = 1;
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[1]].signalStart + ((1 * Fr_toInt(&lvar[0])) + 0)]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
AliasCheck_3_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
PFrElement aux_dest = &lvar[0];
// load src
Fr_add(&expaux[0],&lvar[0],&circuitConstants[2]); // line circom 149
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[0]); // line circom 149
}
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[0]); // line circom 155
while(Fr_isTrue(&expaux[0])){
{
uint cmp_index_ref = 4;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ((1 * Fr_toInt(&lvar[0])) + 1)];
// load src
cmp_index_ref_load = 0;
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + ((1 * Fr_toInt(&lvar[0])) + 0)]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
CompConstant_4_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
PFrElement aux_dest = &lvar[0];
// load src
Fr_add(&expaux[0],&lvar[0],&circuitConstants[2]); // line circom 155
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[0]); // line circom 155
}
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[0]); // line circom 159
while(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[0])) + 0)];
// load src
cmp_index_ref_load = 1;
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[1]].signalStart + ((1 * Fr_toInt(&lvar[0])) + 0)]);
}
{
PFrElement aux_dest = &lvar[0];
// load src
Fr_add(&expaux[0],&lvar[0],&circuitConstants[2]); // line circom 159
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[0]); // line circom 159
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 254];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 255];
// load src
cmp_index_ref_load = 4;
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[4]].signalStart + 0]);
}
for (uint i = 0; i < 5; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void Bits2Num_6_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 6;
ctx->componentMemory[coffset].templateName = "Bits2Num";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 254;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void Bits2Num_6_run(uint ctx_index,Circom_CalcWit* ctx){
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
FrElement lvar[4];
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
Fr_copy(aux_dest,&circuitConstants[2]);
}
{
PFrElement aux_dest = &lvar[3];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[3],&circuitConstants[0]); // line circom 61
while(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &lvar[1];
// load src
Fr_mul(&expaux[1],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[3])) + 1)],&lvar[2]); // line circom 62
Fr_add(&expaux[0],&lvar[1],&expaux[1]); // line circom 62
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[2];
// load src
Fr_add(&expaux[0],&lvar[2],&lvar[2]); // line circom 63
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[3];
// load src
Fr_add(&expaux[0],&lvar[3],&circuitConstants[2]); // line circom 61
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[3],&circuitConstants[0]); // line circom 61
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
// end load src
Fr_copy(aux_dest,&lvar[1]);
}
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void BabyCheck_7_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 7;
ctx->componentMemory[coffset].templateName = "BabyCheck";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 2;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void BabyCheck_7_run(uint ctx_index,Circom_CalcWit* ctx){
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
FrElement expaux[7];
FrElement lvar[2];
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[10]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[11]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 2];
// load src
Fr_mul(&expaux[0],&signalValues[mySignalStart + 0],&signalValues[mySignalStart + 0]); // line circom 79
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 3];
// load src
Fr_mul(&expaux[0],&signalValues[mySignalStart + 1],&signalValues[mySignalStart + 1]); // line circom 80
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_mul(&expaux[2],&circuitConstants[10],&signalValues[mySignalStart + 2]); // line circom 82
Fr_add(&expaux[1],&expaux[2],&signalValues[mySignalStart + 3]); // line circom 82
Fr_mul(&expaux[5],&circuitConstants[11],&signalValues[mySignalStart + 2]); // line circom 82
Fr_mul(&expaux[4],&expaux[5],&signalValues[mySignalStart + 3]); // line circom 82
Fr_add(&expaux[2],&circuitConstants[2],&expaux[4]); // line circom 82
{{
Fr_eq(&expaux[0],&expaux[1],&expaux[2]); // line circom 82
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 82. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void Bits2Point_Strict_8_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 8;
ctx->componentMemory[coffset].templateName = "Bits2Point_Strict";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 256;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[6]{0};
}

void Bits2Point_Strict_8_run(uint ctx_index,Circom_CalcWit* ctx){
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
FrElement expaux[7];
FrElement lvar[5];
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
uint aux_create = 0;
int aux_cmp_num = 3+ctx_index+1;
uint csoffset = mySignalStart+1031;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "aliasCheckY";
AliasCheck_3_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 773 ;
aux_cmp_num += 3;
}
}
{
uint aux_create = 1;
int aux_cmp_num = 6+ctx_index+1;
uint csoffset = mySignalStart+1804;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "b2nY";
Bits2Num_6_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 255 ;
aux_cmp_num += 1;
}
}
{
uint aux_create = 2;
int aux_cmp_num = 7+ctx_index+1;
uint csoffset = mySignalStart+2059;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "babyCheck";
BabyCheck_7_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 4 ;
aux_cmp_num += 1;
}
}
{
uint aux_create = 3;
int aux_cmp_num = 8+ctx_index+1;
uint csoffset = mySignalStart+2063;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "n2bX";
Num2Bits_0_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 255 ;
aux_cmp_num += 1;
}
}
{
uint aux_create = 4;
int aux_cmp_num = 0+ctx_index+1;
uint csoffset = mySignalStart+258;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "aliasCheckX";
AliasCheck_3_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 773 ;
aux_cmp_num += 3;
}
}
{
uint aux_create = 5;
int aux_cmp_num = 9+ctx_index+1;
uint csoffset = mySignalStart+2318;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "signCalc";
CompConstant_4_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 519 ;
aux_cmp_num += 2;
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
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[0]); // line circom 86
while(Fr_isTrue(&expaux[0])){
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ((1 * Fr_toInt(&lvar[0])) + 0)];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[0])) + 2)]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
AliasCheck_3_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
PFrElement aux_dest = &lvar[0];
// load src
Fr_add(&expaux[0],&lvar[0],&circuitConstants[2]); // line circom 86
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[0]); // line circom 86
}
{{
Fr_eq(&expaux[0],&signalValues[mySignalStart + 256],&circuitConstants[1]); // line circom 89
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 89. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[0]); // line circom 92
while(Fr_isTrue(&expaux[0])){
{
uint cmp_index_ref = 1;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ((1 * Fr_toInt(&lvar[0])) + 1)];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[0])) + 2)]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
Bits2Num_6_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
PFrElement aux_dest = &lvar[0];
// load src
Fr_add(&expaux[0],&lvar[0],&circuitConstants[2]); // line circom 92
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[0]); // line circom 92
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 1];
// load src
cmp_index_ref_load = 1;
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[1]].signalStart + 0]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[10]);
}
{
PFrElement aux_dest = &lvar[2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[11]);
}
{
PFrElement aux_dest = &lvar[3];
// load src
Fr_mul(&expaux[0],&signalValues[mySignalStart + 1],&signalValues[mySignalStart + 1]); // line circom 101
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{

// start of call bucket
FrElement lvarcall[10];
// copying argument 0
Fr_sub(&expaux[2],&circuitConstants[2],&lvar[3]); // line circom 103
Fr_mul(&expaux[5],&circuitConstants[11],&lvar[3]); // line circom 103
Fr_sub(&expaux[3],&circuitConstants[10],&expaux[5]); // line circom 103
Fr_div(&expaux[1],&expaux[2],&expaux[3]); // line circom 103
Fr_copy(&lvarcall[0],&expaux[1]);
// end copying argument 0
sqrt_0(ctx,lvarcall,myId,&lvar[4],1);
// end call bucket
}

{{
Fr_eq(&expaux[0],&signalValues[mySignalStart + 257],&circuitConstants[2]); // line circom 105
}}
if(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &lvar[4];
// load src
Fr_neg(&expaux[0],&lvar[4]); // line circom 105
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
// end load src
Fr_copy(aux_dest,&lvar[4]);
}
{
uint cmp_index_ref = 2;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 0];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 0]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 2;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 1]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
BabyCheck_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 3;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 254];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 0]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Num2Bits_0_run(mySubcomponents[cmp_index_ref],ctx);
}
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[0]); // line circom 116
while(Fr_isTrue(&expaux[0])){
{
uint cmp_index_ref = 4;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ((1 * Fr_toInt(&lvar[0])) + 0)];
// load src
cmp_index_ref_load = 3;
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[3]].signalStart + ((1 * Fr_toInt(&lvar[0])) + 0)]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
AliasCheck_3_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
PFrElement aux_dest = &lvar[0];
// load src
Fr_add(&expaux[0],&lvar[0],&circuitConstants[2]); // line circom 116
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[0]); // line circom 116
}
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[0]); // line circom 121
while(Fr_isTrue(&expaux[0])){
{
uint cmp_index_ref = 5;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ((1 * Fr_toInt(&lvar[0])) + 1)];
// load src
cmp_index_ref_load = 3;
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[3]].signalStart + ((1 * Fr_toInt(&lvar[0])) + 0)]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
CompConstant_4_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
PFrElement aux_dest = &lvar[0];
// load src
Fr_add(&expaux[0],&lvar[0],&circuitConstants[2]); // line circom 121
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[0]); // line circom 121
}
cmp_index_ref_load = 5;
{{
Fr_eq(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[5]].signalStart + 0],&signalValues[mySignalStart + 257]); // line circom 125
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 125. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
for (uint i = 0; i < 6; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void Main_9_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 9;
ctx->componentMemory[coffset].templateName = "Main";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 2;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[2]{0};
}

void Main_9_run(uint ctx_index,Circom_CalcWit* ctx){
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
int aux_cmp_num = 12+ctx_index+1;
uint csoffset = mySignalStart+2839;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "p2b";
Point2Bits_Strict_5_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 2833 ;
aux_cmp_num += 11;
}
}
{
uint aux_create = 1;
int aux_cmp_num = 0+ctx_index+1;
uint csoffset = mySignalStart+2;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "b2p";
Bits2Point_Strict_8_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 2837 ;
aux_cmp_num += 12;
}
}
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 256];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 0]);
}
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 257];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 1]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Point2Bits_Strict_5_run(mySubcomponents[cmp_index_ref],ctx);
}
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[12]); // line circom 17
while(Fr_isTrue(&expaux[0])){
{
uint cmp_index_ref = 1;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ((1 * Fr_toInt(&lvar[0])) + 2)];
// load src
cmp_index_ref_load = 0;
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + ((1 * Fr_toInt(&lvar[0])) + 0)]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
Bits2Point_Strict_8_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
PFrElement aux_dest = &lvar[0];
// load src
Fr_add(&expaux[0],&lvar[0],&circuitConstants[2]); // line circom 17
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[12]); // line circom 17
}
cmp_index_ref_load = 1;
{{
Fr_eq(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[1]].signalStart + 0],&signalValues[mySignalStart + 0]); // line circom 21
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 21. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
cmp_index_ref_load = 1;
{{
Fr_eq(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[1]].signalStart + 1],&signalValues[mySignalStart + 1]); // line circom 22
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 22. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
for (uint i = 0; i < 2; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void run(Circom_CalcWit* ctx){
Main_9_create(1,0,ctx,"main",0);
Main_9_run(0,ctx);
}

