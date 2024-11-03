#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "circom.hpp"
#include "calcwit.hpp"
void A_0_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void A_0_run(uint ctx_index,Circom_CalcWit* ctx);
void A_1_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void A_1_run(uint ctx_index,Circom_CalcWit* ctx);
void A_2_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void A_2_run(uint ctx_index,Circom_CalcWit* ctx);
void B_3_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void B_3_run(uint ctx_index,Circom_CalcWit* ctx);
Circom_TemplateFunction _functionTable[4] = { 
A_0_run,
A_1_run,
A_2_run,
B_3_run };
Circom_TemplateFunction _functionTableParallel[4] = { 
NULL,
NULL,
NULL,
NULL };
uint get_main_input_signal_start() {return 4;}

uint get_main_input_signal_no() {return 116;}

uint get_total_signal_no() {return 352;}

uint get_number_of_components() {return 4;}

uint get_size_of_input_hashmap() {return 256;}

uint get_size_of_witness() {return 352;}

uint get_size_of_constants() {return 8;}

uint get_size_of_io_map() {return 3;}

uint get_size_of_bus_field_map() {return 9;}

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
void A_0_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 0;
ctx->componentMemory[coffset].templateName = "A";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 22;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void A_0_run(uint ctx_index,Circom_CalcWit* ctx){
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
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
// end load src
Fr_copyn(aux_dest,&signalValues[mySignalStart + 22],4);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 4];
// load src
// end load src
Fr_copyn(aux_dest,&signalValues[mySignalStart + 26],12);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 16];
// load src
// end load src
Fr_copyn(aux_dest,&signalValues[mySignalStart + 41],3);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 19];
// load src
// end load src
Fr_copyn(aux_dest,&signalValues[mySignalStart + 38],3);
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
ctx->componentMemory[coffset].inputCounter = 46;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
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
FrElement expaux[1];
FrElement lvar[2];
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[2]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[3]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
// end load src
Fr_copyn(aux_dest,&signalValues[mySignalStart + 46],6);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 6];
// load src
// end load src
Fr_copyn(aux_dest,&signalValues[mySignalStart + 52],30);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 36];
// load src
// end load src
Fr_copyn(aux_dest,&signalValues[mySignalStart + 87],5);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 41];
// load src
// end load src
Fr_copyn(aux_dest,&signalValues[mySignalStart + 82],5);
}
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void A_2_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 2;
ctx->componentMemory[coffset].templateName = "A";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 48;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void A_2_run(uint ctx_index,Circom_CalcWit* ctx){
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
FrElement lvar[2];
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
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[4]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
// end load src
Fr_copyn(aux_dest,&signalValues[mySignalStart + 48],3);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 3];
// load src
// end load src
Fr_copyn(aux_dest,&signalValues[mySignalStart + 51],27);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 30];
// load src
// end load src
Fr_copyn(aux_dest,&signalValues[mySignalStart + 87],9);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 39];
// load src
// end load src
Fr_copyn(aux_dest,&signalValues[mySignalStart + 78],9);
}
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void B_3_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 3;
ctx->componentMemory[coffset].templateName = "B";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 116;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[3]{0};
}

void B_3_run(uint ctx_index,Circom_CalcWit* ctx){
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
FrElement lvar[14];
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
Fr_copy(aux_dest,&circuitConstants[2]);
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
Fr_copy(aux_dest,&circuitConstants[3]);
}
{
PFrElement aux_dest = &lvar[5];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[4]);
}
{
uint aux_create = 0;
int aux_cmp_num = 0+ctx_index+1;
uint csoffset = mySignalStart+119;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "aux[0]";
A_0_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 0 ;
aux_cmp_num += 0;
}
}
{
uint aux_create = 1;
int aux_cmp_num = 1+ctx_index+1;
uint csoffset = mySignalStart+163;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "aux[1]";
A_1_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 0 ;
aux_cmp_num += 0;
}
}
{
uint aux_create = 2;
int aux_cmp_num = 2+ctx_index+1;
uint csoffset = mySignalStart+255;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "aux[2]";
A_2_create(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 0 ;
aux_cmp_num += 0;
}
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
Fr_copy(aux_dest,&circuitConstants[5]);
}
{
PFrElement aux_dest = &lvar[8];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[5]);
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
Fr_copy(aux_dest,&circuitConstants[3]);
}
{
PFrElement aux_dest = &lvar[8];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[4]);
}
{
PFrElement aux_dest = &lvar[9];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[5]);
}
{
PFrElement aux_dest = &lvar[10];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[5]);
}
{
PFrElement aux_dest = &lvar[11];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[5]);
}
{
PFrElement aux_dest = &lvar[9];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
{
PFrElement aux_dest = &lvar[10];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[2]);
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
Fr_copy(aux_dest,&circuitConstants[5]);
}
Fr_lt(&expaux[0],&lvar[12],&circuitConstants[1]); // line circom 48
while(Fr_isTrue(&expaux[0])){
{{
Fr_eq(&expaux[0],&lvar[12],&circuitConstants[5]); // line circom 50
}}
if(Fr_isTrue(&expaux[0])){
{
uint cmp_index_ref = 0;
std::map<int,int> size_store {{0,4},{2,3},{1,6}};
{
uint map_accesses_aux[1];
{
IOFieldDef *cur_def = &(ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[1]);
cur_def = &(ctx->busInsId2FieldInfo[cur_def->busId].defs[0]);
map_accesses_aux[0] = cur_def->offset;
}
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[1].offset+map_accesses_aux[0]];
// load src
// end load src
Fr_copyn(aux_dest,&signalValues[mySignalStart + 3],std::min(size_store[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId], 4));
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= std::min(size_store[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId], 4))){
(*_functionTable[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId])(mySubcomponents[cmp_index_ref],ctx);

}
}
}
cmp_index_ref_load = 0;
{{
Fr_eq(&expaux[0],&signalValues[mySignalStart + 3],&ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[0]].templateId].defs[1].offset+ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[0]].templateId].defs[1].busId].defs[0].offset]); // line circom 52
std::map<int,int> size_eq {{0,4},{2,3},{1,6}};
index_multiple_eq = 1;
while(index_multiple_eq < size_eq[ctx->componentMemory[mySubcomponents[cmp_index_ref_load]].templateId] && Fr_isTrue(&expaux[0])) {
Fr_eq(&expaux[0],&signalValues[mySignalStart + 3] + index_multiple_eq,&ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[0]].templateId].defs[1].offset+ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[0]].templateId].defs[1].busId].defs[0].offset] + index_multiple_eq); // line circom 52
index_multiple_eq++;
}
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 52. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
{
PFrElement aux_dest = &lvar[13];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[5]);
}
Fr_lt(&expaux[0],&lvar[13],&circuitConstants[0]); // line circom 53
while(Fr_isTrue(&expaux[0])){
{
uint cmp_index_ref = 0;
std::map<int,int> size_store {{0,3},{2,9},{1,5}};
{
uint map_accesses_aux[3];
{
IOFieldDef *cur_def = &(ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[1]);
cur_def = &(ctx->busInsId2FieldInfo[cur_def->busId].defs[1]);
map_accesses_aux[0] = cur_def->offset;
{
uint map_index_aux[1];
map_index_aux[0]=Fr_toInt(&lvar[13]);
map_accesses_aux[1] = map_index_aux[0]*cur_def->size;
}
cur_def = &(ctx->busInsId2FieldInfo[cur_def->busId].defs[0]);
map_accesses_aux[2] = cur_def->offset;
}
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[1].offset+map_accesses_aux[0]+map_accesses_aux[1]+map_accesses_aux[2]];
// load src
// end load src
Fr_copyn(aux_dest,&signalValues[mySignalStart + ((4 + (3 * Fr_toInt(&lvar[13]))) + 3)],std::min(size_store[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId], 3));
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= std::min(size_store[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId], 3))){
(*_functionTable[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId])(mySubcomponents[cmp_index_ref],ctx);

}
}
}
cmp_index_ref_load = 0;
{{
Fr_eq(&expaux[0],&signalValues[mySignalStart + ((4 + (3 * Fr_toInt(&lvar[13]))) + 3)],&ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[0]].templateId].defs[1].offset+ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[0]].templateId].defs[1].busId].defs[1].offset+(Fr_toInt(&lvar[13]))*ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[0]].templateId].defs[1].busId].defs[1].size+ctx->busInsId2FieldInfo[ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[0]].templateId].defs[1].busId].defs[1].busId].defs[0].offset]); // line circom 55
std::map<int,int> size_eq {{0,3},{2,9},{1,5}};
index_multiple_eq = 1;
while(index_multiple_eq < size_eq[ctx->componentMemory[mySubcomponents[cmp_index_ref_load]].templateId] && Fr_isTrue(&expaux[0])) {
Fr_eq(&expaux[0],&signalValues[mySignalStart + ((4 + (3 * Fr_toInt(&lvar[13]))) + 3)] + index_multiple_eq,&ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[0]].templateId].defs[1].offset+ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[0]].templateId].defs[1].busId].defs[1].offset+(Fr_toInt(&lvar[13]))*ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[0]].templateId].defs[1].busId].defs[1].size+ctx->busInsId2FieldInfo[ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[0]].templateId].defs[1].busId].defs[1].busId].defs[0].offset] + index_multiple_eq); // line circom 55
index_multiple_eq++;
}
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 55. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
{
PFrElement aux_dest = &lvar[13];
// load src
Fr_add(&expaux[0],&lvar[13],&circuitConstants[6]); // line circom 53
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[13],&circuitConstants[0]); // line circom 53
}
}else{
{{
Fr_eq(&expaux[0],&lvar[12],&circuitConstants[6]); // line circom 57
}}
if(Fr_isTrue(&expaux[0])){
{
uint cmp_index_ref = 1;
std::map<int,int> size_store {{0,4},{2,3},{1,6}};
{
uint map_accesses_aux[1];
{
IOFieldDef *cur_def = &(ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[1]);
cur_def = &(ctx->busInsId2FieldInfo[cur_def->busId].defs[0]);
map_accesses_aux[0] = cur_def->offset;
}
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[1].offset+map_accesses_aux[0]];
// load src
// end load src
Fr_copyn(aux_dest,&signalValues[mySignalStart + 25],std::min(size_store[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId], 6));
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= std::min(size_store[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId], 6))){
(*_functionTable[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId])(mySubcomponents[cmp_index_ref],ctx);

}
}
}
{
uint cmp_index_ref = 1;
std::map<int,int> size_store {{0,12},{2,27},{1,30}};
{
uint map_accesses_aux[1];
{
IOFieldDef *cur_def = &(ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[1]);
cur_def = &(ctx->busInsId2FieldInfo[cur_def->busId].defs[1]);
map_accesses_aux[0] = cur_def->offset;
}
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[1].offset+map_accesses_aux[0]];
// load src
// end load src
Fr_copyn(aux_dest,&signalValues[mySignalStart + 31],std::min(size_store[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId], 30));
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= std::min(size_store[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId], 30))){
(*_functionTable[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId])(mySubcomponents[cmp_index_ref],ctx);

}
}
}
cmp_index_ref_load = 1;
{{
Fr_eq(&expaux[0],&signalValues[mySignalStart + 25],&ctx->signalValues[ctx->componentMemory[mySubcomponents[1]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[1]].templateId].defs[1].offset+ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[1]].templateId].defs[1].busId].defs[0].offset]); // line circom 60
std::map<int,int> size_eq {{0,4},{2,3},{1,6}};
index_multiple_eq = 1;
while(index_multiple_eq < size_eq[ctx->componentMemory[mySubcomponents[cmp_index_ref_load]].templateId] && Fr_isTrue(&expaux[0])) {
Fr_eq(&expaux[0],&signalValues[mySignalStart + 25] + index_multiple_eq,&ctx->signalValues[ctx->componentMemory[mySubcomponents[1]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[1]].templateId].defs[1].offset+ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[1]].templateId].defs[1].busId].defs[0].offset] + index_multiple_eq); // line circom 60
index_multiple_eq++;
}
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 60. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
cmp_index_ref_load = 1;
{{
Fr_eq(&expaux[0],&signalValues[mySignalStart + 31],&ctx->signalValues[ctx->componentMemory[mySubcomponents[1]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[1]].templateId].defs[1].offset+ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[1]].templateId].defs[1].busId].defs[1].offset]); // line circom 61
std::map<int,int> size_eq {{0,12},{2,27},{1,30}};
index_multiple_eq = 1;
while(index_multiple_eq < size_eq[ctx->componentMemory[mySubcomponents[cmp_index_ref_load]].templateId] && Fr_isTrue(&expaux[0])) {
Fr_eq(&expaux[0],&signalValues[mySignalStart + 31] + index_multiple_eq,&ctx->signalValues[ctx->componentMemory[mySubcomponents[1]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[1]].templateId].defs[1].offset+ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[1]].templateId].defs[1].busId].defs[1].offset] + index_multiple_eq); // line circom 61
index_multiple_eq++;
}
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 61. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
}else{
{
uint cmp_index_ref = 2;
std::map<int,int> size_store {{0,4},{2,3},{1,6}};
{
uint map_accesses_aux[1];
{
IOFieldDef *cur_def = &(ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[1]);
cur_def = &(ctx->busInsId2FieldInfo[cur_def->busId].defs[0]);
map_accesses_aux[0] = cur_def->offset;
}
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[1].offset+map_accesses_aux[0]];
// load src
// end load src
Fr_copyn(aux_dest,&signalValues[mySignalStart + 71],std::min(size_store[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId], 3));
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= std::min(size_store[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId], 3))){
(*_functionTable[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId])(mySubcomponents[cmp_index_ref],ctx);

}
}
}
{
uint cmp_index_ref = 2;
std::map<int,int> size_store {{0,12},{2,27},{1,30}};
{
uint map_accesses_aux[1];
{
IOFieldDef *cur_def = &(ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[1]);
cur_def = &(ctx->busInsId2FieldInfo[cur_def->busId].defs[1]);
map_accesses_aux[0] = cur_def->offset;
}
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[1].offset+map_accesses_aux[0]];
// load src
// end load src
Fr_copyn(aux_dest,&signalValues[mySignalStart + 74],std::min(size_store[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId], 27));
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= std::min(size_store[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId], 27))){
(*_functionTable[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId])(mySubcomponents[cmp_index_ref],ctx);

}
}
}
cmp_index_ref_load = 2;
{{
Fr_eq(&expaux[0],&signalValues[mySignalStart + 71],&ctx->signalValues[ctx->componentMemory[mySubcomponents[2]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[2]].templateId].defs[1].offset+ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[2]].templateId].defs[1].busId].defs[0].offset]); // line circom 65
std::map<int,int> size_eq {{0,4},{2,3},{1,6}};
index_multiple_eq = 1;
while(index_multiple_eq < size_eq[ctx->componentMemory[mySubcomponents[cmp_index_ref_load]].templateId] && Fr_isTrue(&expaux[0])) {
Fr_eq(&expaux[0],&signalValues[mySignalStart + 71] + index_multiple_eq,&ctx->signalValues[ctx->componentMemory[mySubcomponents[2]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[2]].templateId].defs[1].offset+ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[2]].templateId].defs[1].busId].defs[0].offset] + index_multiple_eq); // line circom 65
index_multiple_eq++;
}
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 65. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
cmp_index_ref_load = 2;
{{
Fr_eq(&expaux[0],&signalValues[mySignalStart + 74],&ctx->signalValues[ctx->componentMemory[mySubcomponents[2]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[2]].templateId].defs[1].offset+ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[2]].templateId].defs[1].busId].defs[1].offset]); // line circom 66
std::map<int,int> size_eq {{0,12},{2,27},{1,30}};
index_multiple_eq = 1;
while(index_multiple_eq < size_eq[ctx->componentMemory[mySubcomponents[cmp_index_ref_load]].templateId] && Fr_isTrue(&expaux[0])) {
Fr_eq(&expaux[0],&signalValues[mySignalStart + 74] + index_multiple_eq,&ctx->signalValues[ctx->componentMemory[mySubcomponents[2]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[2]].templateId].defs[1].offset+ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[2]].templateId].defs[1].busId].defs[1].offset] + index_multiple_eq); // line circom 66
index_multiple_eq++;
}
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 66. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
}
}
{
PFrElement aux_dest = &lvar[13];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[5]);
}
Fr_lt(&expaux[0],&lvar[13],&lvar[((1 * Fr_toInt(&lvar[12])) + 6)]); // line circom 69
while(Fr_isTrue(&expaux[0])){
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[12])) + 0);
{
uint map_accesses_aux[3];
{
IOFieldDef *cur_def = &(ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[1]);
cur_def = &(ctx->busInsId2FieldInfo[cur_def->busId].defs[2]);
map_accesses_aux[0] = cur_def->offset;
cur_def = &(ctx->busInsId2FieldInfo[cur_def->busId].defs[0]);
map_accesses_aux[1] = cur_def->offset;
{
uint map_index_aux[1];
map_index_aux[0]=Fr_toInt(&lvar[13]);
map_accesses_aux[2] = map_index_aux[0]*cur_def->size;
}
}
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[1].offset+map_accesses_aux[0]+map_accesses_aux[1]+map_accesses_aux[2]];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + ((30 + (1 * Fr_toInt(&lvar[13]))) + 71)]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
(*_functionTable[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId])(mySubcomponents[cmp_index_ref],ctx);

}
}
}
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[12])) + 0);
{
uint map_accesses_aux[3];
{
IOFieldDef *cur_def = &(ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[1]);
cur_def = &(ctx->busInsId2FieldInfo[cur_def->busId].defs[2]);
map_accesses_aux[0] = cur_def->offset;
cur_def = &(ctx->busInsId2FieldInfo[cur_def->busId].defs[1]);
map_accesses_aux[1] = cur_def->offset;
{
uint map_index_aux[1];
map_index_aux[0]=Fr_toInt(&lvar[13]);
map_accesses_aux[2] = map_index_aux[0]*cur_def->size;
}
}
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[1].offset+map_accesses_aux[0]+map_accesses_aux[1]+map_accesses_aux[2]];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + ((39 + (1 * Fr_toInt(&lvar[13]))) + 71)]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
(*_functionTable[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId])(mySubcomponents[cmp_index_ref],ctx);

}
}
}
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[12])) + 0);
{{
Fr_eq(&expaux[0],&signalValues[mySignalStart + ((30 + (1 * Fr_toInt(&lvar[13]))) + 71)],&ctx->signalValues[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[12])) + 0)]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[12])) + 0)]].templateId].defs[1].offset+ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[12])) + 0)]].templateId].defs[1].busId].defs[2].offset+ctx->busInsId2FieldInfo[ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[12])) + 0)]].templateId].defs[1].busId].defs[2].busId].defs[0].offset+(Fr_toInt(&lvar[13]))*ctx->busInsId2FieldInfo[ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[12])) + 0)]].templateId].defs[1].busId].defs[2].busId].defs[0].size]); // line circom 72
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 72. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[12])) + 0);
{{
Fr_eq(&expaux[0],&signalValues[mySignalStart + ((39 + (1 * Fr_toInt(&lvar[13]))) + 71)],&ctx->signalValues[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[12])) + 0)]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[12])) + 0)]].templateId].defs[1].offset+ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[12])) + 0)]].templateId].defs[1].busId].defs[2].offset+ctx->busInsId2FieldInfo[ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[12])) + 0)]].templateId].defs[1].busId].defs[2].busId].defs[1].offset+(Fr_toInt(&lvar[13]))*ctx->busInsId2FieldInfo[ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[12])) + 0)]].templateId].defs[1].busId].defs[2].busId].defs[1].size]); // line circom 73
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 73. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
{
PFrElement aux_dest = &lvar[13];
// load src
Fr_add(&expaux[0],&lvar[13],&circuitConstants[6]); // line circom 69
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[13],&lvar[((1 * Fr_toInt(&lvar[12])) + 6)]); // line circom 69
}
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[12])) + 0)];
// load src
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[12])) + 0);
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[12])) + 0)]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[12])) + 0)]].templateId].defs[0].offset+ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[12])) + 0)]].templateId].defs[0].busId].defs[2].offset+ctx->busInsId2FieldInfo[ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[12])) + 0)]].templateId].defs[0].busId].defs[2].busId].defs[1].offset+(0)*ctx->busInsId2FieldInfo[ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[12])) + 0)]].templateId].defs[0].busId].defs[2].busId].defs[1].size]);
}
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[12])) + 0);
{{
Fr_eq(&expaux[0],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[12])) + 0)],&ctx->signalValues[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[12])) + 0)]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[12])) + 0)]].templateId].defs[0].offset+ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[12])) + 0)]].templateId].defs[0].busId].defs[2].offset+ctx->busInsId2FieldInfo[ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[12])) + 0)]].templateId].defs[0].busId].defs[2].busId].defs[1].offset+(0)*ctx->busInsId2FieldInfo[ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[12])) + 0)]].templateId].defs[0].busId].defs[2].busId].defs[1].size]); // line circom 76
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 76. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
{
PFrElement aux_dest = &lvar[12];
// load src
Fr_add(&expaux[0],&lvar[12],&circuitConstants[6]); // line circom 48
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[12],&circuitConstants[1]); // line circom 48
}
for (uint i = 0; i < 3; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void run(Circom_CalcWit* ctx){
B_3_create(1,0,ctx,"main",0);
B_3_run(0,ctx);
}

