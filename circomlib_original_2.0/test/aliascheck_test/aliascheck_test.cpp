#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "circom.hpp"
#include "calcwit.hpp"
void Num2Bits_0_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Num2Bits_0_run(uint ctx_index,Circom_CalcWit* ctx);
void CompConstant_1_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void CompConstant_1_run(uint ctx_index,Circom_CalcWit* ctx);
void AliasCheck_2_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void AliasCheck_2_run(uint ctx_index,Circom_CalcWit* ctx);
Circom_TemplateFunction _functionTable[3] = { 
Num2Bits_0_run,
CompConstant_1_run,
AliasCheck_2_run };
Circom_TemplateFunction _functionTableParallel[3] = { 
NULL,
NULL,
NULL };
uint get_main_input_signal_start() {return 1;}

uint get_main_input_signal_no() {return 254;}

uint get_total_signal_no() {return 774;}

uint get_number_of_components() {return 3;}

uint get_size_of_input_hashmap() {return 256;}

uint get_size_of_witness() {return 774;}

uint get_size_of_constants() {return 8;}

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
Fr_lt(&expaux[0],&lvar[3],&circuitConstants[0]); // line circom 31
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

void CompConstant_1_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 1;
ctx->componentMemory[coffset].templateName = "CompConstant";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 254;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void CompConstant_1_run(uint ctx_index,Circom_CalcWit* ctx){
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
Fr_copy(aux_dest,&circuitConstants[3]);
}
{
uint aux_create = 0;
int aux_cmp_num = 0+ctx_index+1;
uint csoffset = mySignalStart+383;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "num2bits";
Num2Bits_0_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
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
Fr_copy(aux_dest,&circuitConstants[4]);
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
Fr_lt(&expaux[0],&lvar[9],&circuitConstants[5]); // line circom 44
while(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &lvar[1];
// load src
Fr_mul(&expaux[3],&lvar[9],&circuitConstants[6]); // line circom 45
Fr_shr(&expaux[1],&circuitConstants[3],&expaux[3]); // line circom 45
Fr_band(&expaux[0],&expaux[1],&circuitConstants[2]); // line circom 45
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[2];
// load src
Fr_mul(&expaux[4],&lvar[9],&circuitConstants[6]); // line circom 46
Fr_add(&expaux[3],&expaux[4],&circuitConstants[2]); // line circom 46
Fr_shr(&expaux[1],&circuitConstants[3],&expaux[3]); // line circom 46
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
Fr_mul(&expaux[0],&lvar[8],&circuitConstants[6]); // line circom 64
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
Fr_lt(&expaux[0],&lvar[9],&circuitConstants[5]); // line circom 44
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
Num2Bits_0_run(mySubcomponents[cmp_index_ref],ctx);
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

void AliasCheck_2_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 2;
ctx->componentMemory[coffset].templateName = "AliasCheck";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 254;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void AliasCheck_2_run(uint ctx_index,Circom_CalcWit* ctx){
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
CompConstant_1_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
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
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[7]); // line circom 30
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
CompConstant_1_run(mySubcomponents[cmp_index_ref],ctx);

}
}
{
PFrElement aux_dest = &lvar[0];
// load src
Fr_add(&expaux[0],&lvar[0],&circuitConstants[2]); // line circom 30
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[7]); // line circom 30
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

void run(Circom_CalcWit* ctx){
AliasCheck_2_create(1,0,ctx,"main",0);
AliasCheck_2_run(0,ctx);
}

