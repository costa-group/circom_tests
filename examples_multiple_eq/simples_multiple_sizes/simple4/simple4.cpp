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

uint get_main_input_signal_no() {return 104;}

uint get_total_signal_no() {return 316;}

uint get_number_of_components() {return 4;}

uint get_size_of_input_hashmap() {return 256;}

uint get_size_of_witness() {return 316;}

uint get_size_of_constants() {return 7;}

uint get_size_of_io_map() {return 3;}

uint get_size_of_bus_field_map() {return 3;}

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
ctx->componentMemory[coffset].inputCounter = 20;
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
Fr_copyn(aux_dest,&signalValues[mySignalStart + 20],20);
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
ctx->componentMemory[coffset].inputCounter = 36;
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
Fr_copyn(aux_dest,&signalValues[mySignalStart + 36],36);
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
Fr_copy(aux_dest,&circuitConstants[2]);
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
Fr_copyn(aux_dest,&signalValues[mySignalStart + 48],48);
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
ctx->componentMemory[coffset].inputCounter = 104;
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
Fr_copy(aux_dest,&circuitConstants[2]);
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
uint csoffset = mySignalStart+107;
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
uint csoffset = mySignalStart+147;
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
uint csoffset = mySignalStart+219;
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
Fr_copy(aux_dest,&circuitConstants[2]);
}
{
PFrElement aux_dest = &lvar[12];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[5]);
}
Fr_lt(&expaux[0],&lvar[12],&circuitConstants[2]); // line circom 38
while(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &lvar[13];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[5]);
}
Fr_lt(&expaux[0],&lvar[13],&lvar[((1 * Fr_toInt(&lvar[12])) + 9)]); // line circom 40
while(Fr_isTrue(&expaux[0])){
{{
Fr_eq(&expaux[0],&lvar[12],&circuitConstants[5]); // line circom 41
}}
if(Fr_isTrue(&expaux[0])){
{
uint cmp_index_ref = 0;
std::map<int,int> size_store {{2,8},{0,2},{1,6}};
{
uint map_accesses_aux[2];
{
IOFieldDef *cur_def = &(ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[1]);
{
uint map_index_aux[1];
map_index_aux[0]=Fr_toInt(&lvar[13]);
map_accesses_aux[0] = map_index_aux[0]*cur_def->size;
}
cur_def = &(ctx->busInsId2FieldInfo[cur_def->busId].defs[0]);
map_accesses_aux[1] = cur_def->offset;
}
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[1].offset+map_accesses_aux[0]+map_accesses_aux[1]];
// load src
// end load src
Fr_copyn(aux_dest,&signalValues[mySignalStart + ((4 * Fr_toInt(&lvar[13])) + 3)],std::min(size_store[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId], 2));
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= std::min(size_store[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId], 2))){
(*_functionTable[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId])(mySubcomponents[cmp_index_ref],ctx);

}
}
}
{
uint cmp_index_ref = 0;
std::map<int,int> size_store {{2,8},{0,2},{1,6}};
{
uint map_accesses_aux[2];
{
IOFieldDef *cur_def = &(ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[1]);
{
uint map_index_aux[1];
map_index_aux[0]=Fr_toInt(&lvar[13]);
map_accesses_aux[0] = map_index_aux[0]*cur_def->size;
}
cur_def = &(ctx->busInsId2FieldInfo[cur_def->busId].defs[1]);
map_accesses_aux[1] = cur_def->offset;
}
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[1].offset+map_accesses_aux[0]+map_accesses_aux[1]];
// load src
// end load src
Fr_copyn(aux_dest,&signalValues[mySignalStart + (((4 * Fr_toInt(&lvar[13])) + 2) + 3)],std::min(size_store[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId], 2));
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= std::min(size_store[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId], 2))){
(*_functionTable[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId])(mySubcomponents[cmp_index_ref],ctx);

}
}
}
cmp_index_ref_load = 0;
{{
Fr_eq(&expaux[0],&signalValues[mySignalStart + ((4 * Fr_toInt(&lvar[13])) + 3)],&ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[0]].templateId].defs[1].offset+(Fr_toInt(&lvar[13]))*ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[0]].templateId].defs[1].size+ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[0]].templateId].defs[1].busId].defs[0].offset]); // line circom 44
std::map<int,int> size_eq {{2,8},{0,2},{1,6}};
index_multiple_eq = 1;
while(index_multiple_eq < size_eq[ctx->componentMemory[mySubcomponents[cmp_index_ref_load]].templateId] && Fr_isTrue(&expaux[0])) {
Fr_eq(&expaux[0],&signalValues[mySignalStart + ((4 * Fr_toInt(&lvar[13])) + 3)] + index_multiple_eq,&ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[0]].templateId].defs[1].offset+(Fr_toInt(&lvar[13]))*ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[0]].templateId].defs[1].size+ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[0]].templateId].defs[1].busId].defs[0].offset] + index_multiple_eq); // line circom 44
index_multiple_eq++;
}
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 44. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
cmp_index_ref_load = 0;
{{
Fr_eq(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[0]].templateId].defs[1].offset+(Fr_toInt(&lvar[13]))*ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[0]].templateId].defs[1].size+ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[0]].templateId].defs[1].busId].defs[1].offset],&signalValues[mySignalStart + (((4 * Fr_toInt(&lvar[13])) + 2) + 3)]); // line circom 45
index_multiple_eq = 1;
while(index_multiple_eq < 2 && Fr_isTrue(&expaux[0])) {
Fr_eq(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[0]].templateId].defs[1].offset+(Fr_toInt(&lvar[13]))*ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[0]].templateId].defs[1].size+ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[0]].templateId].defs[1].busId].defs[1].offset] + index_multiple_eq,&signalValues[mySignalStart + (((4 * Fr_toInt(&lvar[13])) + 2) + 3)] + index_multiple_eq); // line circom 45
index_multiple_eq++;
}
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 45. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
}else{
{{
Fr_eq(&expaux[0],&lvar[12],&circuitConstants[6]); // line circom 46
}}
if(Fr_isTrue(&expaux[0])){
{
uint cmp_index_ref = 1;
std::map<int,int> size_store {{2,8},{0,2},{1,6}};
{
uint map_accesses_aux[2];
{
IOFieldDef *cur_def = &(ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[1]);
{
uint map_index_aux[1];
map_index_aux[0]=Fr_toInt(&lvar[13]);
map_accesses_aux[0] = map_index_aux[0]*cur_def->size;
}
cur_def = &(ctx->busInsId2FieldInfo[cur_def->busId].defs[0]);
map_accesses_aux[1] = cur_def->offset;
}
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[1].offset+map_accesses_aux[0]+map_accesses_aux[1]];
// load src
// end load src
Fr_copyn(aux_dest,&signalValues[mySignalStart + ((12 * Fr_toInt(&lvar[13])) + 23)],std::min(size_store[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId], 6));
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= std::min(size_store[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId], 6))){
(*_functionTable[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId])(mySubcomponents[cmp_index_ref],ctx);

}
}
}
{
uint cmp_index_ref = 1;
std::map<int,int> size_store {{2,8},{0,2},{1,6}};
{
uint map_accesses_aux[2];
{
IOFieldDef *cur_def = &(ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[1]);
{
uint map_index_aux[1];
map_index_aux[0]=Fr_toInt(&lvar[13]);
map_accesses_aux[0] = map_index_aux[0]*cur_def->size;
}
cur_def = &(ctx->busInsId2FieldInfo[cur_def->busId].defs[1]);
map_accesses_aux[1] = cur_def->offset;
}
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[1].offset+map_accesses_aux[0]+map_accesses_aux[1]];
// load src
// end load src
Fr_copyn(aux_dest,&signalValues[mySignalStart + (((12 * Fr_toInt(&lvar[13])) + 6) + 23)],std::min(size_store[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId], 6));
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= std::min(size_store[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId], 6))){
(*_functionTable[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId])(mySubcomponents[cmp_index_ref],ctx);

}
}
}
cmp_index_ref_load = 1;
{{
Fr_eq(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[1]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[1]].templateId].defs[1].offset+(Fr_toInt(&lvar[13]))*ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[1]].templateId].defs[1].size+ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[1]].templateId].defs[1].busId].defs[0].offset],&signalValues[mySignalStart + ((12 * Fr_toInt(&lvar[13])) + 23)]); // line circom 49
index_multiple_eq = 1;
while(index_multiple_eq < 6 && Fr_isTrue(&expaux[0])) {
Fr_eq(&expaux[0],&ctx->signalValues[ctx->componentMemory[mySubcomponents[1]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[1]].templateId].defs[1].offset+(Fr_toInt(&lvar[13]))*ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[1]].templateId].defs[1].size+ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[1]].templateId].defs[1].busId].defs[0].offset] + index_multiple_eq,&signalValues[mySignalStart + ((12 * Fr_toInt(&lvar[13])) + 23)] + index_multiple_eq); // line circom 49
index_multiple_eq++;
}
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 49. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
cmp_index_ref_load = 1;
{{
Fr_eq(&expaux[0],&signalValues[mySignalStart + (((12 * Fr_toInt(&lvar[13])) + 6) + 23)],&ctx->signalValues[ctx->componentMemory[mySubcomponents[1]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[1]].templateId].defs[1].offset+(Fr_toInt(&lvar[13]))*ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[1]].templateId].defs[1].size+ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[1]].templateId].defs[1].busId].defs[1].offset]); // line circom 50
std::map<int,int> size_eq {{2,8},{0,2},{1,6}};
index_multiple_eq = 1;
while(index_multiple_eq < size_eq[ctx->componentMemory[mySubcomponents[cmp_index_ref_load]].templateId] && Fr_isTrue(&expaux[0])) {
Fr_eq(&expaux[0],&signalValues[mySignalStart + (((12 * Fr_toInt(&lvar[13])) + 6) + 23)] + index_multiple_eq,&ctx->signalValues[ctx->componentMemory[mySubcomponents[1]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[1]].templateId].defs[1].offset+(Fr_toInt(&lvar[13]))*ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[1]].templateId].defs[1].size+ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[1]].templateId].defs[1].busId].defs[1].offset] + index_multiple_eq); // line circom 50
index_multiple_eq++;
}
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 50. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
}else{
{
uint cmp_index_ref = 2;
std::map<int,int> size_store {{2,8},{0,2},{1,6}};
{
uint map_accesses_aux[2];
{
IOFieldDef *cur_def = &(ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[1]);
{
uint map_index_aux[1];
map_index_aux[0]=Fr_toInt(&lvar[13]);
map_accesses_aux[0] = map_index_aux[0]*cur_def->size;
}
cur_def = &(ctx->busInsId2FieldInfo[cur_def->busId].defs[0]);
map_accesses_aux[1] = cur_def->offset;
}
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[1].offset+map_accesses_aux[0]+map_accesses_aux[1]];
// load src
// end load src
Fr_copyn(aux_dest,&signalValues[mySignalStart + ((16 * Fr_toInt(&lvar[13])) + 59)],std::min(size_store[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId], 8));
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= std::min(size_store[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId], 8))){
(*_functionTable[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId])(mySubcomponents[cmp_index_ref],ctx);

}
}
}
{
uint cmp_index_ref = 2;
std::map<int,int> size_store {{2,8},{0,2},{1,6}};
{
uint map_accesses_aux[2];
{
IOFieldDef *cur_def = &(ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[1]);
{
uint map_index_aux[1];
map_index_aux[0]=Fr_toInt(&lvar[13]);
map_accesses_aux[0] = map_index_aux[0]*cur_def->size;
}
cur_def = &(ctx->busInsId2FieldInfo[cur_def->busId].defs[1]);
map_accesses_aux[1] = cur_def->offset;
}
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[1].offset+map_accesses_aux[0]+map_accesses_aux[1]];
// load src
// end load src
Fr_copyn(aux_dest,&signalValues[mySignalStart + (((16 * Fr_toInt(&lvar[13])) + 8) + 59)],std::min(size_store[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId], 8));
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= std::min(size_store[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId], 8))){
(*_functionTable[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId])(mySubcomponents[cmp_index_ref],ctx);

}
}
}
cmp_index_ref_load = 2;
{{
Fr_eq(&expaux[0],&signalValues[mySignalStart + ((16 * Fr_toInt(&lvar[13])) + 59)],&ctx->signalValues[ctx->componentMemory[mySubcomponents[2]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[2]].templateId].defs[1].offset+(Fr_toInt(&lvar[13]))*ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[2]].templateId].defs[1].size+ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[2]].templateId].defs[1].busId].defs[0].offset]); // line circom 54
std::map<int,int> size_eq {{2,8},{0,2},{1,6}};
index_multiple_eq = 1;
while(index_multiple_eq < size_eq[ctx->componentMemory[mySubcomponents[cmp_index_ref_load]].templateId] && Fr_isTrue(&expaux[0])) {
Fr_eq(&expaux[0],&signalValues[mySignalStart + ((16 * Fr_toInt(&lvar[13])) + 59)] + index_multiple_eq,&ctx->signalValues[ctx->componentMemory[mySubcomponents[2]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[2]].templateId].defs[1].offset+(Fr_toInt(&lvar[13]))*ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[2]].templateId].defs[1].size+ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[2]].templateId].defs[1].busId].defs[0].offset] + index_multiple_eq); // line circom 54
index_multiple_eq++;
}
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 54. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
cmp_index_ref_load = 2;
{{
Fr_eq(&expaux[0],&signalValues[mySignalStart + (((16 * Fr_toInt(&lvar[13])) + 8) + 59)],&ctx->signalValues[ctx->componentMemory[mySubcomponents[2]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[2]].templateId].defs[1].offset+(Fr_toInt(&lvar[13]))*ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[2]].templateId].defs[1].size+ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[2]].templateId].defs[1].busId].defs[1].offset]); // line circom 55
std::map<int,int> size_eq {{2,8},{0,2},{1,6}};
index_multiple_eq = 1;
while(index_multiple_eq < size_eq[ctx->componentMemory[mySubcomponents[cmp_index_ref_load]].templateId] && Fr_isTrue(&expaux[0])) {
Fr_eq(&expaux[0],&signalValues[mySignalStart + (((16 * Fr_toInt(&lvar[13])) + 8) + 59)] + index_multiple_eq,&ctx->signalValues[ctx->componentMemory[mySubcomponents[2]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[2]].templateId].defs[1].offset+(Fr_toInt(&lvar[13]))*ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[2]].templateId].defs[1].size+ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[2]].templateId].defs[1].busId].defs[1].offset] + index_multiple_eq); // line circom 55
index_multiple_eq++;
}
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 55. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
}
}
{
PFrElement aux_dest = &lvar[13];
// load src
Fr_add(&expaux[0],&lvar[13],&circuitConstants[6]); // line circom 40
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[13],&lvar[((1 * Fr_toInt(&lvar[12])) + 9)]); // line circom 40
}
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[12])) + 0)];
// load src
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[12])) + 0);
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[12])) + 0)]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[12])) + 0)]].templateId].defs[0].offset+(0)*ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[12])) + 0)]].templateId].defs[0].size+ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[12])) + 0)]].templateId].defs[0].busId].defs[1].offset+(0)*ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[12])) + 0)]].templateId].defs[0].busId].defs[1].size]);
}
cmp_index_ref_load = ((1 * Fr_toInt(&lvar[12])) + 0);
{{
Fr_eq(&expaux[0],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[12])) + 0)],&ctx->signalValues[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[12])) + 0)]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[12])) + 0)]].templateId].defs[0].offset+(0)*ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[12])) + 0)]].templateId].defs[0].size+ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[12])) + 0)]].templateId].defs[0].busId].defs[1].offset+(0)*ctx->busInsId2FieldInfo[ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[((1 * Fr_toInt(&lvar[12])) + 0)]].templateId].defs[0].busId].defs[1].size]); // line circom 60
}}
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 60. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
{
PFrElement aux_dest = &lvar[12];
// load src
Fr_add(&expaux[0],&lvar[12],&circuitConstants[6]); // line circom 38
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[12],&circuitConstants[2]); // line circom 38
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

