#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "circom.hpp"
#include "calcwit.hpp"
void Aux_0_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Aux_0_run_parallel(uint ctx_index,Circom_CalcWit* ctx);
void MultiAux_1_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void MultiAux_1_run_parallel(uint ctx_index,Circom_CalcWit* ctx);
void Aux_2_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Aux_2_run_parallel(uint ctx_index,Circom_CalcWit* ctx);
void MultiAux_3_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void MultiAux_3_run_parallel(uint ctx_index,Circom_CalcWit* ctx);
void Aux_4_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Aux_4_run_parallel(uint ctx_index,Circom_CalcWit* ctx);
void MultiAux_5_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void MultiAux_5_run_parallel(uint ctx_index,Circom_CalcWit* ctx);
void Aux_6_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Aux_6_run_parallel(uint ctx_index,Circom_CalcWit* ctx);
void MultiAux_7_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void MultiAux_7_run_parallel(uint ctx_index,Circom_CalcWit* ctx);
void Aux_8_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Aux_8_run_parallel(uint ctx_index,Circom_CalcWit* ctx);
void MultiAux_9_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void MultiAux_9_run_parallel(uint ctx_index,Circom_CalcWit* ctx);
void Aux_10_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Aux_10_run_parallel(uint ctx_index,Circom_CalcWit* ctx);
void MultiAux_11_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void MultiAux_11_run_parallel(uint ctx_index,Circom_CalcWit* ctx);
void Aux_12_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Aux_12_run_parallel(uint ctx_index,Circom_CalcWit* ctx);
void MultiAux_13_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void MultiAux_13_run_parallel(uint ctx_index,Circom_CalcWit* ctx);
void Aux_14_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Aux_14_run_parallel(uint ctx_index,Circom_CalcWit* ctx);
void MultiAux_15_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void MultiAux_15_run_parallel(uint ctx_index,Circom_CalcWit* ctx);
void Aux_16_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Aux_16_run_parallel(uint ctx_index,Circom_CalcWit* ctx);
void MultiAux_17_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void MultiAux_17_run_parallel(uint ctx_index,Circom_CalcWit* ctx);
void Main_18_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Main_18_run(uint ctx_index,Circom_CalcWit* ctx);
Circom_TemplateFunction _functionTable[19] = { 
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
Main_18_run };
Circom_TemplateFunction _functionTableParallel[19] = { 
Aux_0_run_parallel,
MultiAux_1_run_parallel,
Aux_2_run_parallel,
MultiAux_3_run_parallel,
Aux_4_run_parallel,
MultiAux_5_run_parallel,
Aux_6_run_parallel,
MultiAux_7_run_parallel,
Aux_8_run_parallel,
MultiAux_9_run_parallel,
Aux_10_run_parallel,
MultiAux_11_run_parallel,
Aux_12_run_parallel,
MultiAux_13_run_parallel,
Aux_14_run_parallel,
MultiAux_15_run_parallel,
Aux_16_run_parallel,
MultiAux_17_run_parallel,
NULL };
uint get_main_input_signal_start() {return 11;}

uint get_main_input_signal_no() {return 1;}

uint get_total_signal_no() {return 636;}

uint get_number_of_components() {return 55;}

uint get_size_of_input_hashmap() {return 256;}

uint get_size_of_witness() {return 636;}

uint get_size_of_constants() {return 11;}

uint get_size_of_io_map() {return 9;}

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
void Aux_0_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 0;
ctx->componentMemory[coffset].templateName = "Aux";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
ctx->componentMemory[coffset].outputIsSet = new bool[1]();
ctx->componentMemory[coffset].mutexes = new std::mutex[1];
ctx->componentMemory[coffset].cvs = new std::condition_variable[1];
}

void Aux_0_run_parallel(uint ctx_index,Circom_CalcWit* ctx){
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
uint aux_dest_index = 0;
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 1]);
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].lock();
ctx->componentMemory[ctx_index].outputIsSet[aux_dest_index]=true;
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].unlock();
ctx->componentMemory[ctx_index].cvs[aux_dest_index].notify_all();
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
for (uint i = 0; i < 1; i++) {
ctx->componentMemory[ctx_index].mutexes[i].lock();
ctx->componentMemory[ctx_index].outputIsSet[i]=true;
ctx->componentMemory[ctx_index].mutexes[i].unlock();
ctx->componentMemory[ctx_index].cvs[i].notify_all();
}
ctx->numThreadMutex.lock();
ctx->numThread--;
ctx->numThreadMutex.unlock();
ctx->ntcvs.notify_one();
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void MultiAux_1_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 1;
ctx->componentMemory[coffset].templateName = "MultiAux";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
ctx->componentMemory[coffset].sbct = new std::thread[1];
ctx->componentMemory[coffset].subcomponentsParallel = new bool[1];
ctx->componentMemory[coffset].outputIsSet = new bool[1]();
ctx->componentMemory[coffset].mutexes = new std::mutex[1];
ctx->componentMemory[coffset].cvs = new std::condition_variable[1];
}

void MultiAux_1_run_parallel(uint ctx_index,Circom_CalcWit* ctx){
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
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
{
uint aux_create = 0;
int aux_cmp_num = 0+ctx_index+1;
uint csoffset = mySignalStart+2;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "c_aux";
Aux_0_create_parallel(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 2 ;
aux_cmp_num += 1;
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[0]); // line circom 21
while(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &lvar[2];
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
Fr_lt(&expaux[0],&lvar[2],&circuitConstants[0]); // line circom 30
while(Fr_isTrue(&expaux[0])){
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 1]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
ctx->componentMemory[ctx_index].sbct[cmp_index_ref] = std::thread(Aux_0_run_parallel,mySubcomponents[cmp_index_ref],ctx);
std::unique_lock<std::mutex> lkt(ctx->numThreadMutex);
ctx->ntcvs.wait(lkt, [ctx]() {return ctx->numThread <  ctx->maxThread; });
ctx->numThread++;

}
}
{
PFrElement aux_dest = &lvar[2];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
Fr_lt(&expaux[0],&lvar[2],&circuitConstants[0]); // line circom 30
}
{
uint aux_dest_index = 0;
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
uint cmp_index_ref = 0;
{
int aux1 = cmp_index_ref;
int aux2 = 0;
for (int i = 0; i < 1; i++) {
ctx->numThreadMutex.lock();
ctx->numThread--;
ctx->numThreadMutex.unlock();
ctx->ntcvs.notify_one();
std::unique_lock<std::mutex> lk(ctx->componentMemory[mySubcomponents[aux1]].mutexes[aux2 + i]);
ctx->componentMemory[mySubcomponents[aux1]].cvs[aux2 + i].wait(lk, [ctx,mySubcomponents,aux1,aux2, i]() {return ctx->componentMemory[mySubcomponents[aux1]].outputIsSet[aux2 + i];});
std::unique_lock<std::mutex> lkt(ctx->numThreadMutex);
ctx->ntcvs.wait(lkt, [ctx]() {return ctx->numThread <  ctx->maxThread; });
ctx->numThread++;
}
}
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 0]);
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].lock();
ctx->componentMemory[ctx_index].outputIsSet[aux_dest_index]=true;
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].unlock();
ctx->componentMemory[ctx_index].cvs[aux_dest_index].notify_all();
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[0]); // line circom 21
}
{
for (uint i = 0; i < 1; i++) {
if (ctx->componentMemory[ctx_index].sbct[i].joinable()) {
ctx->componentMemory[ctx_index].sbct[i].join();
}
}
}
for (uint i = 0; i < 1; i++) {
ctx->componentMemory[ctx_index].mutexes[i].lock();
ctx->componentMemory[ctx_index].outputIsSet[i]=true;
ctx->componentMemory[ctx_index].mutexes[i].unlock();
ctx->componentMemory[ctx_index].cvs[i].notify_all();
}
ctx->numThreadMutex.lock();
ctx->numThread--;
ctx->numThreadMutex.unlock();
ctx->ntcvs.notify_one();
for (uint i = 0; i < 1; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void Aux_2_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 2;
ctx->componentMemory[coffset].templateName = "Aux";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 2;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
ctx->componentMemory[coffset].outputIsSet = new bool[2]();
ctx->componentMemory[coffset].mutexes = new std::mutex[2];
ctx->componentMemory[coffset].cvs = new std::condition_variable[2];
}

void Aux_2_run_parallel(uint ctx_index,Circom_CalcWit* ctx){
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
FrElement lvar[2];
uint sub_component_aux;
uint index_multiple_eq;
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
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
uint aux_dest_index = 0;
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 2]);
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].lock();
ctx->componentMemory[ctx_index].outputIsSet[aux_dest_index]=true;
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].unlock();
ctx->componentMemory[ctx_index].cvs[aux_dest_index].notify_all();
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[2]); // line circom 7
while(Fr_isTrue(&expaux[0])){
{
uint aux_dest_index = 1;
{
PFrElement aux_dest = &signalValues[mySignalStart + 1];
// load src
Fr_mul(&expaux[0],&signalValues[mySignalStart + 0],&signalValues[mySignalStart + 3]); // line circom 8
// end load src
Fr_copy(aux_dest,&expaux[0]);
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].lock();
ctx->componentMemory[ctx_index].outputIsSet[aux_dest_index]=true;
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].unlock();
ctx->componentMemory[ctx_index].cvs[aux_dest_index].notify_all();
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[2]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[2]); // line circom 7
}
for (uint i = 0; i < 2; i++) {
ctx->componentMemory[ctx_index].mutexes[i].lock();
ctx->componentMemory[ctx_index].outputIsSet[i]=true;
ctx->componentMemory[ctx_index].mutexes[i].unlock();
ctx->componentMemory[ctx_index].cvs[i].notify_all();
}
ctx->numThreadMutex.lock();
ctx->numThread--;
ctx->numThreadMutex.unlock();
ctx->ntcvs.notify_one();
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void MultiAux_3_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 3;
ctx->componentMemory[coffset].templateName = "MultiAux";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[2]{0};
ctx->componentMemory[coffset].sbct = new std::thread[2];
ctx->componentMemory[coffset].subcomponentsParallel = new bool[2];
ctx->componentMemory[coffset].outputIsSet = new bool[2]();
ctx->componentMemory[coffset].mutexes = new std::mutex[2];
ctx->componentMemory[coffset].cvs = new std::condition_variable[2];
}

void MultiAux_3_run_parallel(uint ctx_index,Circom_CalcWit* ctx){
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
FrElement lvar[3];
uint sub_component_aux;
uint index_multiple_eq;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[2]);
}
{
uint aux_create = 0;
int aux_cmp_num = 0+ctx_index+1;
uint csoffset = mySignalStart+3;
uint aux_dimensions[1] = {2};
for (uint i = 0; i < 2; i++) {
std::string new_cmp_name = "c_aux"+ctx->generate_position_array(aux_dimensions, 1, i);
Aux_2_create_parallel(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 4 ;
aux_cmp_num += 1;
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[2]); // line circom 21
while(Fr_isTrue(&expaux[0])){
Fr_mod(&expaux[1],&lvar[1],&circuitConstants[2]); // line circom 22
Fr_eq(&expaux[0],&expaux[1],&circuitConstants[1]); // line circom 22
if(Fr_isTrue(&expaux[0])){

}
{
PFrElement aux_dest = &lvar[2];
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
Fr_lt(&expaux[0],&lvar[2],&circuitConstants[2]); // line circom 30
while(Fr_isTrue(&expaux[0])){
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 0);
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ((1 * Fr_toInt(&lvar[2])) + 2)];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 2]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
ctx->componentMemory[ctx_index].sbct[cmp_index_ref] = std::thread(Aux_2_run_parallel,mySubcomponents[cmp_index_ref],ctx);
std::unique_lock<std::mutex> lkt(ctx->numThreadMutex);
ctx->ntcvs.wait(lkt, [ctx]() {return ctx->numThread <  ctx->maxThread; });
ctx->numThread++;

}
}
{
PFrElement aux_dest = &lvar[2];
// load src
Fr_add(&expaux[0],&lvar[2],&circuitConstants[0]); // line circom 30
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[2],&circuitConstants[2]); // line circom 30
}
{
uint aux_dest_index = ((1 * Fr_toInt(&lvar[1])) + 0);
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[1])) + 0)];
// load src
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 0);
{
int aux1 = cmp_index_ref;
int aux2 = 1;
for (int i = 0; i < 1; i++) {
ctx->numThreadMutex.lock();
ctx->numThread--;
ctx->numThreadMutex.unlock();
ctx->ntcvs.notify_one();
std::unique_lock<std::mutex> lk(ctx->componentMemory[mySubcomponents[aux1]].mutexes[aux2 + i]);
ctx->componentMemory[mySubcomponents[aux1]].cvs[aux2 + i].wait(lk, [ctx,mySubcomponents,aux1,aux2, i]() {return ctx->componentMemory[mySubcomponents[aux1]].outputIsSet[aux2 + i];});
std::unique_lock<std::mutex> lkt(ctx->numThreadMutex);
ctx->ntcvs.wait(lkt, [ctx]() {return ctx->numThread <  ctx->maxThread; });
ctx->numThread++;
}
}
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1]);
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].lock();
ctx->componentMemory[ctx_index].outputIsSet[aux_dest_index]=true;
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].unlock();
ctx->componentMemory[ctx_index].cvs[aux_dest_index].notify_all();
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
Fr_add(&expaux[0],&lvar[1],&circuitConstants[0]); // line circom 21
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[2]); // line circom 21
}
{
for (uint i = 0; i < 2; i++) {
if (ctx->componentMemory[ctx_index].sbct[i].joinable()) {
ctx->componentMemory[ctx_index].sbct[i].join();
}
}
}
for (uint i = 0; i < 2; i++) {
ctx->componentMemory[ctx_index].mutexes[i].lock();
ctx->componentMemory[ctx_index].outputIsSet[i]=true;
ctx->componentMemory[ctx_index].mutexes[i].unlock();
ctx->componentMemory[ctx_index].cvs[i].notify_all();
}
ctx->numThreadMutex.lock();
ctx->numThread--;
ctx->numThreadMutex.unlock();
ctx->ntcvs.notify_one();
for (uint i = 0; i < 2; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void Aux_4_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 4;
ctx->componentMemory[coffset].templateName = "Aux";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 3;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
ctx->componentMemory[coffset].outputIsSet = new bool[3]();
ctx->componentMemory[coffset].mutexes = new std::mutex[3];
ctx->componentMemory[coffset].cvs = new std::condition_variable[3];
}

void Aux_4_run_parallel(uint ctx_index,Circom_CalcWit* ctx){
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
FrElement lvar[2];
uint sub_component_aux;
uint index_multiple_eq;
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
uint aux_dest_index = 0;
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 3]);
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].lock();
ctx->componentMemory[ctx_index].outputIsSet[aux_dest_index]=true;
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].unlock();
ctx->componentMemory[ctx_index].cvs[aux_dest_index].notify_all();
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[3]); // line circom 7
while(Fr_isTrue(&expaux[0])){
{
uint aux_dest_index = ((1 * Fr_toInt(&lvar[1])) + 0);
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[1])) + 0)];
// load src
Fr_sub(&expaux[1],&lvar[1],&circuitConstants[0]); // line circom 8
Fr_mul(&expaux[0],&signalValues[mySignalStart + ((1 * Fr_toInt(&expaux[1])) + 0)],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[1])) + 3)]); // line circom 8
// end load src
Fr_copy(aux_dest,&expaux[0]);
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].lock();
ctx->componentMemory[ctx_index].outputIsSet[aux_dest_index]=true;
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].unlock();
ctx->componentMemory[ctx_index].cvs[aux_dest_index].notify_all();
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
Fr_add(&expaux[0],&lvar[1],&circuitConstants[0]); // line circom 7
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[3]); // line circom 7
}
for (uint i = 0; i < 3; i++) {
ctx->componentMemory[ctx_index].mutexes[i].lock();
ctx->componentMemory[ctx_index].outputIsSet[i]=true;
ctx->componentMemory[ctx_index].mutexes[i].unlock();
ctx->componentMemory[ctx_index].cvs[i].notify_all();
}
ctx->numThreadMutex.lock();
ctx->numThread--;
ctx->numThreadMutex.unlock();
ctx->ntcvs.notify_one();
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void MultiAux_5_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 5;
ctx->componentMemory[coffset].templateName = "MultiAux";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[3]{0};
ctx->componentMemory[coffset].sbct = new std::thread[3];
ctx->componentMemory[coffset].subcomponentsParallel = new bool[3];
ctx->componentMemory[coffset].outputIsSet = new bool[3]();
ctx->componentMemory[coffset].mutexes = new std::mutex[3];
ctx->componentMemory[coffset].cvs = new std::condition_variable[3];
}

void MultiAux_5_run_parallel(uint ctx_index,Circom_CalcWit* ctx){
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
FrElement lvar[3];
uint sub_component_aux;
uint index_multiple_eq;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[3]);
}
{
uint aux_create = 0;
int aux_cmp_num = 0+ctx_index+1;
uint csoffset = mySignalStart+4;
uint aux_dimensions[1] = {3};
for (uint i = 0; i < 3; i++) {
std::string new_cmp_name = "c_aux"+ctx->generate_position_array(aux_dimensions, 1, i);
Aux_4_create_parallel(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 6 ;
aux_cmp_num += 1;
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[3]); // line circom 21
while(Fr_isTrue(&expaux[0])){
Fr_mod(&expaux[1],&lvar[1],&circuitConstants[2]); // line circom 22
Fr_eq(&expaux[0],&expaux[1],&circuitConstants[1]); // line circom 22
if(Fr_isTrue(&expaux[0])){

}
{
PFrElement aux_dest = &lvar[2];
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
Fr_lt(&expaux[0],&lvar[2],&circuitConstants[3]); // line circom 30
while(Fr_isTrue(&expaux[0])){
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 0);
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ((1 * Fr_toInt(&lvar[2])) + 3)];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 3]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
ctx->componentMemory[ctx_index].sbct[cmp_index_ref] = std::thread(Aux_4_run_parallel,mySubcomponents[cmp_index_ref],ctx);
std::unique_lock<std::mutex> lkt(ctx->numThreadMutex);
ctx->ntcvs.wait(lkt, [ctx]() {return ctx->numThread <  ctx->maxThread; });
ctx->numThread++;

}
}
{
PFrElement aux_dest = &lvar[2];
// load src
Fr_add(&expaux[0],&lvar[2],&circuitConstants[0]); // line circom 30
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[2],&circuitConstants[3]); // line circom 30
}
{
uint aux_dest_index = ((1 * Fr_toInt(&lvar[1])) + 0);
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[1])) + 0)];
// load src
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 0);
{
int aux1 = cmp_index_ref;
int aux2 = 2;
for (int i = 0; i < 1; i++) {
ctx->numThreadMutex.lock();
ctx->numThread--;
ctx->numThreadMutex.unlock();
ctx->ntcvs.notify_one();
std::unique_lock<std::mutex> lk(ctx->componentMemory[mySubcomponents[aux1]].mutexes[aux2 + i]);
ctx->componentMemory[mySubcomponents[aux1]].cvs[aux2 + i].wait(lk, [ctx,mySubcomponents,aux1,aux2, i]() {return ctx->componentMemory[mySubcomponents[aux1]].outputIsSet[aux2 + i];});
std::unique_lock<std::mutex> lkt(ctx->numThreadMutex);
ctx->ntcvs.wait(lkt, [ctx]() {return ctx->numThread <  ctx->maxThread; });
ctx->numThread++;
}
}
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2]);
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].lock();
ctx->componentMemory[ctx_index].outputIsSet[aux_dest_index]=true;
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].unlock();
ctx->componentMemory[ctx_index].cvs[aux_dest_index].notify_all();
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
Fr_add(&expaux[0],&lvar[1],&circuitConstants[0]); // line circom 21
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[3]); // line circom 21
}
{
for (uint i = 0; i < 3; i++) {
if (ctx->componentMemory[ctx_index].sbct[i].joinable()) {
ctx->componentMemory[ctx_index].sbct[i].join();
}
}
}
for (uint i = 0; i < 3; i++) {
ctx->componentMemory[ctx_index].mutexes[i].lock();
ctx->componentMemory[ctx_index].outputIsSet[i]=true;
ctx->componentMemory[ctx_index].mutexes[i].unlock();
ctx->componentMemory[ctx_index].cvs[i].notify_all();
}
ctx->numThreadMutex.lock();
ctx->numThread--;
ctx->numThreadMutex.unlock();
ctx->ntcvs.notify_one();
for (uint i = 0; i < 3; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void Aux_6_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 6;
ctx->componentMemory[coffset].templateName = "Aux";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 4;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
ctx->componentMemory[coffset].outputIsSet = new bool[4]();
ctx->componentMemory[coffset].mutexes = new std::mutex[4];
ctx->componentMemory[coffset].cvs = new std::condition_variable[4];
}

void Aux_6_run_parallel(uint ctx_index,Circom_CalcWit* ctx){
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
FrElement lvar[2];
uint sub_component_aux;
uint index_multiple_eq;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[4]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
uint aux_dest_index = 0;
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 4]);
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].lock();
ctx->componentMemory[ctx_index].outputIsSet[aux_dest_index]=true;
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].unlock();
ctx->componentMemory[ctx_index].cvs[aux_dest_index].notify_all();
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[4]); // line circom 7
while(Fr_isTrue(&expaux[0])){
{
uint aux_dest_index = ((1 * Fr_toInt(&lvar[1])) + 0);
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[1])) + 0)];
// load src
Fr_sub(&expaux[1],&lvar[1],&circuitConstants[0]); // line circom 8
Fr_mul(&expaux[0],&signalValues[mySignalStart + ((1 * Fr_toInt(&expaux[1])) + 0)],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[1])) + 4)]); // line circom 8
// end load src
Fr_copy(aux_dest,&expaux[0]);
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].lock();
ctx->componentMemory[ctx_index].outputIsSet[aux_dest_index]=true;
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].unlock();
ctx->componentMemory[ctx_index].cvs[aux_dest_index].notify_all();
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
Fr_add(&expaux[0],&lvar[1],&circuitConstants[0]); // line circom 7
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[4]); // line circom 7
}
for (uint i = 0; i < 4; i++) {
ctx->componentMemory[ctx_index].mutexes[i].lock();
ctx->componentMemory[ctx_index].outputIsSet[i]=true;
ctx->componentMemory[ctx_index].mutexes[i].unlock();
ctx->componentMemory[ctx_index].cvs[i].notify_all();
}
ctx->numThreadMutex.lock();
ctx->numThread--;
ctx->numThreadMutex.unlock();
ctx->ntcvs.notify_one();
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void MultiAux_7_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 7;
ctx->componentMemory[coffset].templateName = "MultiAux";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[4]{0};
ctx->componentMemory[coffset].sbct = new std::thread[4];
ctx->componentMemory[coffset].subcomponentsParallel = new bool[4];
ctx->componentMemory[coffset].outputIsSet = new bool[4]();
ctx->componentMemory[coffset].mutexes = new std::mutex[4];
ctx->componentMemory[coffset].cvs = new std::condition_variable[4];
}

void MultiAux_7_run_parallel(uint ctx_index,Circom_CalcWit* ctx){
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
FrElement lvar[3];
uint sub_component_aux;
uint index_multiple_eq;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[4]);
}
{
uint aux_create = 0;
int aux_cmp_num = 0+ctx_index+1;
uint csoffset = mySignalStart+5;
uint aux_dimensions[1] = {4};
for (uint i = 0; i < 4; i++) {
std::string new_cmp_name = "c_aux"+ctx->generate_position_array(aux_dimensions, 1, i);
Aux_6_create_parallel(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 8 ;
aux_cmp_num += 1;
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[4]); // line circom 21
while(Fr_isTrue(&expaux[0])){
Fr_mod(&expaux[1],&lvar[1],&circuitConstants[2]); // line circom 22
Fr_eq(&expaux[0],&expaux[1],&circuitConstants[1]); // line circom 22
if(Fr_isTrue(&expaux[0])){

}
{
PFrElement aux_dest = &lvar[2];
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
Fr_lt(&expaux[0],&lvar[2],&circuitConstants[4]); // line circom 30
while(Fr_isTrue(&expaux[0])){
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 0);
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ((1 * Fr_toInt(&lvar[2])) + 4)];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 4]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
ctx->componentMemory[ctx_index].sbct[cmp_index_ref] = std::thread(Aux_6_run_parallel,mySubcomponents[cmp_index_ref],ctx);
std::unique_lock<std::mutex> lkt(ctx->numThreadMutex);
ctx->ntcvs.wait(lkt, [ctx]() {return ctx->numThread <  ctx->maxThread; });
ctx->numThread++;

}
}
{
PFrElement aux_dest = &lvar[2];
// load src
Fr_add(&expaux[0],&lvar[2],&circuitConstants[0]); // line circom 30
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[2],&circuitConstants[4]); // line circom 30
}
{
uint aux_dest_index = ((1 * Fr_toInt(&lvar[1])) + 0);
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[1])) + 0)];
// load src
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 0);
{
int aux1 = cmp_index_ref;
int aux2 = 3;
for (int i = 0; i < 1; i++) {
ctx->numThreadMutex.lock();
ctx->numThread--;
ctx->numThreadMutex.unlock();
ctx->ntcvs.notify_one();
std::unique_lock<std::mutex> lk(ctx->componentMemory[mySubcomponents[aux1]].mutexes[aux2 + i]);
ctx->componentMemory[mySubcomponents[aux1]].cvs[aux2 + i].wait(lk, [ctx,mySubcomponents,aux1,aux2, i]() {return ctx->componentMemory[mySubcomponents[aux1]].outputIsSet[aux2 + i];});
std::unique_lock<std::mutex> lkt(ctx->numThreadMutex);
ctx->ntcvs.wait(lkt, [ctx]() {return ctx->numThread <  ctx->maxThread; });
ctx->numThread++;
}
}
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3]);
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].lock();
ctx->componentMemory[ctx_index].outputIsSet[aux_dest_index]=true;
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].unlock();
ctx->componentMemory[ctx_index].cvs[aux_dest_index].notify_all();
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
Fr_add(&expaux[0],&lvar[1],&circuitConstants[0]); // line circom 21
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[4]); // line circom 21
}
{
for (uint i = 0; i < 4; i++) {
if (ctx->componentMemory[ctx_index].sbct[i].joinable()) {
ctx->componentMemory[ctx_index].sbct[i].join();
}
}
}
for (uint i = 0; i < 4; i++) {
ctx->componentMemory[ctx_index].mutexes[i].lock();
ctx->componentMemory[ctx_index].outputIsSet[i]=true;
ctx->componentMemory[ctx_index].mutexes[i].unlock();
ctx->componentMemory[ctx_index].cvs[i].notify_all();
}
ctx->numThreadMutex.lock();
ctx->numThread--;
ctx->numThreadMutex.unlock();
ctx->ntcvs.notify_one();
for (uint i = 0; i < 4; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void Aux_8_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 8;
ctx->componentMemory[coffset].templateName = "Aux";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 5;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
ctx->componentMemory[coffset].outputIsSet = new bool[5]();
ctx->componentMemory[coffset].mutexes = new std::mutex[5];
ctx->componentMemory[coffset].cvs = new std::condition_variable[5];
}

void Aux_8_run_parallel(uint ctx_index,Circom_CalcWit* ctx){
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
FrElement lvar[2];
uint sub_component_aux;
uint index_multiple_eq;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[5]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
uint aux_dest_index = 0;
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 5]);
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].lock();
ctx->componentMemory[ctx_index].outputIsSet[aux_dest_index]=true;
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].unlock();
ctx->componentMemory[ctx_index].cvs[aux_dest_index].notify_all();
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[5]); // line circom 7
while(Fr_isTrue(&expaux[0])){
{
uint aux_dest_index = ((1 * Fr_toInt(&lvar[1])) + 0);
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[1])) + 0)];
// load src
Fr_sub(&expaux[1],&lvar[1],&circuitConstants[0]); // line circom 8
Fr_mul(&expaux[0],&signalValues[mySignalStart + ((1 * Fr_toInt(&expaux[1])) + 0)],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[1])) + 5)]); // line circom 8
// end load src
Fr_copy(aux_dest,&expaux[0]);
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].lock();
ctx->componentMemory[ctx_index].outputIsSet[aux_dest_index]=true;
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].unlock();
ctx->componentMemory[ctx_index].cvs[aux_dest_index].notify_all();
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
Fr_add(&expaux[0],&lvar[1],&circuitConstants[0]); // line circom 7
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[5]); // line circom 7
}
for (uint i = 0; i < 5; i++) {
ctx->componentMemory[ctx_index].mutexes[i].lock();
ctx->componentMemory[ctx_index].outputIsSet[i]=true;
ctx->componentMemory[ctx_index].mutexes[i].unlock();
ctx->componentMemory[ctx_index].cvs[i].notify_all();
}
ctx->numThreadMutex.lock();
ctx->numThread--;
ctx->numThreadMutex.unlock();
ctx->ntcvs.notify_one();
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void MultiAux_9_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 9;
ctx->componentMemory[coffset].templateName = "MultiAux";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[5]{0};
ctx->componentMemory[coffset].sbct = new std::thread[5];
ctx->componentMemory[coffset].subcomponentsParallel = new bool[5];
ctx->componentMemory[coffset].outputIsSet = new bool[5]();
ctx->componentMemory[coffset].mutexes = new std::mutex[5];
ctx->componentMemory[coffset].cvs = new std::condition_variable[5];
}

void MultiAux_9_run_parallel(uint ctx_index,Circom_CalcWit* ctx){
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
FrElement lvar[3];
uint sub_component_aux;
uint index_multiple_eq;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[5]);
}
{
uint aux_create = 0;
int aux_cmp_num = 0+ctx_index+1;
uint csoffset = mySignalStart+6;
uint aux_dimensions[1] = {5};
for (uint i = 0; i < 5; i++) {
std::string new_cmp_name = "c_aux"+ctx->generate_position_array(aux_dimensions, 1, i);
Aux_8_create_parallel(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 10 ;
aux_cmp_num += 1;
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[5]); // line circom 21
while(Fr_isTrue(&expaux[0])){
Fr_mod(&expaux[1],&lvar[1],&circuitConstants[2]); // line circom 22
Fr_eq(&expaux[0],&expaux[1],&circuitConstants[1]); // line circom 22
if(Fr_isTrue(&expaux[0])){

}
{
PFrElement aux_dest = &lvar[2];
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
Fr_lt(&expaux[0],&lvar[2],&circuitConstants[5]); // line circom 30
while(Fr_isTrue(&expaux[0])){
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 0);
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ((1 * Fr_toInt(&lvar[2])) + 5)];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 5]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
ctx->componentMemory[ctx_index].sbct[cmp_index_ref] = std::thread(Aux_8_run_parallel,mySubcomponents[cmp_index_ref],ctx);
std::unique_lock<std::mutex> lkt(ctx->numThreadMutex);
ctx->ntcvs.wait(lkt, [ctx]() {return ctx->numThread <  ctx->maxThread; });
ctx->numThread++;

}
}
{
PFrElement aux_dest = &lvar[2];
// load src
Fr_add(&expaux[0],&lvar[2],&circuitConstants[0]); // line circom 30
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[2],&circuitConstants[5]); // line circom 30
}
{
uint aux_dest_index = ((1 * Fr_toInt(&lvar[1])) + 0);
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[1])) + 0)];
// load src
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 0);
{
int aux1 = cmp_index_ref;
int aux2 = 4;
for (int i = 0; i < 1; i++) {
ctx->numThreadMutex.lock();
ctx->numThread--;
ctx->numThreadMutex.unlock();
ctx->ntcvs.notify_one();
std::unique_lock<std::mutex> lk(ctx->componentMemory[mySubcomponents[aux1]].mutexes[aux2 + i]);
ctx->componentMemory[mySubcomponents[aux1]].cvs[aux2 + i].wait(lk, [ctx,mySubcomponents,aux1,aux2, i]() {return ctx->componentMemory[mySubcomponents[aux1]].outputIsSet[aux2 + i];});
std::unique_lock<std::mutex> lkt(ctx->numThreadMutex);
ctx->ntcvs.wait(lkt, [ctx]() {return ctx->numThread <  ctx->maxThread; });
ctx->numThread++;
}
}
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 4]);
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].lock();
ctx->componentMemory[ctx_index].outputIsSet[aux_dest_index]=true;
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].unlock();
ctx->componentMemory[ctx_index].cvs[aux_dest_index].notify_all();
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
Fr_add(&expaux[0],&lvar[1],&circuitConstants[0]); // line circom 21
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[5]); // line circom 21
}
{
for (uint i = 0; i < 5; i++) {
if (ctx->componentMemory[ctx_index].sbct[i].joinable()) {
ctx->componentMemory[ctx_index].sbct[i].join();
}
}
}
for (uint i = 0; i < 5; i++) {
ctx->componentMemory[ctx_index].mutexes[i].lock();
ctx->componentMemory[ctx_index].outputIsSet[i]=true;
ctx->componentMemory[ctx_index].mutexes[i].unlock();
ctx->componentMemory[ctx_index].cvs[i].notify_all();
}
ctx->numThreadMutex.lock();
ctx->numThread--;
ctx->numThreadMutex.unlock();
ctx->ntcvs.notify_one();
for (uint i = 0; i < 5; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void Aux_10_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 10;
ctx->componentMemory[coffset].templateName = "Aux";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 6;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
ctx->componentMemory[coffset].outputIsSet = new bool[6]();
ctx->componentMemory[coffset].mutexes = new std::mutex[6];
ctx->componentMemory[coffset].cvs = new std::condition_variable[6];
}

void Aux_10_run_parallel(uint ctx_index,Circom_CalcWit* ctx){
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
FrElement lvar[2];
uint sub_component_aux;
uint index_multiple_eq;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[6]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
uint aux_dest_index = 0;
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 6]);
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].lock();
ctx->componentMemory[ctx_index].outputIsSet[aux_dest_index]=true;
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].unlock();
ctx->componentMemory[ctx_index].cvs[aux_dest_index].notify_all();
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[6]); // line circom 7
while(Fr_isTrue(&expaux[0])){
{
uint aux_dest_index = ((1 * Fr_toInt(&lvar[1])) + 0);
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[1])) + 0)];
// load src
Fr_sub(&expaux[1],&lvar[1],&circuitConstants[0]); // line circom 8
Fr_mul(&expaux[0],&signalValues[mySignalStart + ((1 * Fr_toInt(&expaux[1])) + 0)],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[1])) + 6)]); // line circom 8
// end load src
Fr_copy(aux_dest,&expaux[0]);
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].lock();
ctx->componentMemory[ctx_index].outputIsSet[aux_dest_index]=true;
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].unlock();
ctx->componentMemory[ctx_index].cvs[aux_dest_index].notify_all();
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
Fr_add(&expaux[0],&lvar[1],&circuitConstants[0]); // line circom 7
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[6]); // line circom 7
}
for (uint i = 0; i < 6; i++) {
ctx->componentMemory[ctx_index].mutexes[i].lock();
ctx->componentMemory[ctx_index].outputIsSet[i]=true;
ctx->componentMemory[ctx_index].mutexes[i].unlock();
ctx->componentMemory[ctx_index].cvs[i].notify_all();
}
ctx->numThreadMutex.lock();
ctx->numThread--;
ctx->numThreadMutex.unlock();
ctx->ntcvs.notify_one();
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void MultiAux_11_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 11;
ctx->componentMemory[coffset].templateName = "MultiAux";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[6]{0};
ctx->componentMemory[coffset].sbct = new std::thread[6];
ctx->componentMemory[coffset].subcomponentsParallel = new bool[6];
ctx->componentMemory[coffset].outputIsSet = new bool[6]();
ctx->componentMemory[coffset].mutexes = new std::mutex[6];
ctx->componentMemory[coffset].cvs = new std::condition_variable[6];
}

void MultiAux_11_run_parallel(uint ctx_index,Circom_CalcWit* ctx){
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
FrElement lvar[3];
uint sub_component_aux;
uint index_multiple_eq;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[6]);
}
{
uint aux_create = 0;
int aux_cmp_num = 0+ctx_index+1;
uint csoffset = mySignalStart+7;
uint aux_dimensions[1] = {6};
for (uint i = 0; i < 6; i++) {
std::string new_cmp_name = "c_aux"+ctx->generate_position_array(aux_dimensions, 1, i);
Aux_10_create_parallel(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 12 ;
aux_cmp_num += 1;
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[6]); // line circom 21
while(Fr_isTrue(&expaux[0])){
Fr_mod(&expaux[1],&lvar[1],&circuitConstants[2]); // line circom 22
Fr_eq(&expaux[0],&expaux[1],&circuitConstants[1]); // line circom 22
if(Fr_isTrue(&expaux[0])){

}
{
PFrElement aux_dest = &lvar[2];
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
Fr_lt(&expaux[0],&lvar[2],&circuitConstants[6]); // line circom 30
while(Fr_isTrue(&expaux[0])){
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 0);
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ((1 * Fr_toInt(&lvar[2])) + 6)];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 6]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
ctx->componentMemory[ctx_index].sbct[cmp_index_ref] = std::thread(Aux_10_run_parallel,mySubcomponents[cmp_index_ref],ctx);
std::unique_lock<std::mutex> lkt(ctx->numThreadMutex);
ctx->ntcvs.wait(lkt, [ctx]() {return ctx->numThread <  ctx->maxThread; });
ctx->numThread++;

}
}
{
PFrElement aux_dest = &lvar[2];
// load src
Fr_add(&expaux[0],&lvar[2],&circuitConstants[0]); // line circom 30
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[2],&circuitConstants[6]); // line circom 30
}
{
uint aux_dest_index = ((1 * Fr_toInt(&lvar[1])) + 0);
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[1])) + 0)];
// load src
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 0);
{
int aux1 = cmp_index_ref;
int aux2 = 5;
for (int i = 0; i < 1; i++) {
ctx->numThreadMutex.lock();
ctx->numThread--;
ctx->numThreadMutex.unlock();
ctx->ntcvs.notify_one();
std::unique_lock<std::mutex> lk(ctx->componentMemory[mySubcomponents[aux1]].mutexes[aux2 + i]);
ctx->componentMemory[mySubcomponents[aux1]].cvs[aux2 + i].wait(lk, [ctx,mySubcomponents,aux1,aux2, i]() {return ctx->componentMemory[mySubcomponents[aux1]].outputIsSet[aux2 + i];});
std::unique_lock<std::mutex> lkt(ctx->numThreadMutex);
ctx->ntcvs.wait(lkt, [ctx]() {return ctx->numThread <  ctx->maxThread; });
ctx->numThread++;
}
}
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 5]);
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].lock();
ctx->componentMemory[ctx_index].outputIsSet[aux_dest_index]=true;
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].unlock();
ctx->componentMemory[ctx_index].cvs[aux_dest_index].notify_all();
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
Fr_add(&expaux[0],&lvar[1],&circuitConstants[0]); // line circom 21
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[6]); // line circom 21
}
{
for (uint i = 0; i < 6; i++) {
if (ctx->componentMemory[ctx_index].sbct[i].joinable()) {
ctx->componentMemory[ctx_index].sbct[i].join();
}
}
}
for (uint i = 0; i < 6; i++) {
ctx->componentMemory[ctx_index].mutexes[i].lock();
ctx->componentMemory[ctx_index].outputIsSet[i]=true;
ctx->componentMemory[ctx_index].mutexes[i].unlock();
ctx->componentMemory[ctx_index].cvs[i].notify_all();
}
ctx->numThreadMutex.lock();
ctx->numThread--;
ctx->numThreadMutex.unlock();
ctx->ntcvs.notify_one();
for (uint i = 0; i < 6; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void Aux_12_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 12;
ctx->componentMemory[coffset].templateName = "Aux";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 7;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
ctx->componentMemory[coffset].outputIsSet = new bool[7]();
ctx->componentMemory[coffset].mutexes = new std::mutex[7];
ctx->componentMemory[coffset].cvs = new std::condition_variable[7];
}

void Aux_12_run_parallel(uint ctx_index,Circom_CalcWit* ctx){
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
FrElement lvar[2];
uint sub_component_aux;
uint index_multiple_eq;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[7]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
uint aux_dest_index = 0;
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 7]);
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].lock();
ctx->componentMemory[ctx_index].outputIsSet[aux_dest_index]=true;
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].unlock();
ctx->componentMemory[ctx_index].cvs[aux_dest_index].notify_all();
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[7]); // line circom 7
while(Fr_isTrue(&expaux[0])){
{
uint aux_dest_index = ((1 * Fr_toInt(&lvar[1])) + 0);
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[1])) + 0)];
// load src
Fr_sub(&expaux[1],&lvar[1],&circuitConstants[0]); // line circom 8
Fr_mul(&expaux[0],&signalValues[mySignalStart + ((1 * Fr_toInt(&expaux[1])) + 0)],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[1])) + 7)]); // line circom 8
// end load src
Fr_copy(aux_dest,&expaux[0]);
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].lock();
ctx->componentMemory[ctx_index].outputIsSet[aux_dest_index]=true;
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].unlock();
ctx->componentMemory[ctx_index].cvs[aux_dest_index].notify_all();
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
Fr_add(&expaux[0],&lvar[1],&circuitConstants[0]); // line circom 7
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[7]); // line circom 7
}
for (uint i = 0; i < 7; i++) {
ctx->componentMemory[ctx_index].mutexes[i].lock();
ctx->componentMemory[ctx_index].outputIsSet[i]=true;
ctx->componentMemory[ctx_index].mutexes[i].unlock();
ctx->componentMemory[ctx_index].cvs[i].notify_all();
}
ctx->numThreadMutex.lock();
ctx->numThread--;
ctx->numThreadMutex.unlock();
ctx->ntcvs.notify_one();
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void MultiAux_13_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 13;
ctx->componentMemory[coffset].templateName = "MultiAux";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[7]{0};
ctx->componentMemory[coffset].sbct = new std::thread[7];
ctx->componentMemory[coffset].subcomponentsParallel = new bool[7];
ctx->componentMemory[coffset].outputIsSet = new bool[7]();
ctx->componentMemory[coffset].mutexes = new std::mutex[7];
ctx->componentMemory[coffset].cvs = new std::condition_variable[7];
}

void MultiAux_13_run_parallel(uint ctx_index,Circom_CalcWit* ctx){
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
FrElement lvar[3];
uint sub_component_aux;
uint index_multiple_eq;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[7]);
}
{
uint aux_create = 0;
int aux_cmp_num = 0+ctx_index+1;
uint csoffset = mySignalStart+8;
uint aux_dimensions[1] = {7};
for (uint i = 0; i < 7; i++) {
std::string new_cmp_name = "c_aux"+ctx->generate_position_array(aux_dimensions, 1, i);
Aux_12_create_parallel(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 14 ;
aux_cmp_num += 1;
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[7]); // line circom 21
while(Fr_isTrue(&expaux[0])){
Fr_mod(&expaux[1],&lvar[1],&circuitConstants[2]); // line circom 22
Fr_eq(&expaux[0],&expaux[1],&circuitConstants[1]); // line circom 22
if(Fr_isTrue(&expaux[0])){

}
{
PFrElement aux_dest = &lvar[2];
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
Fr_lt(&expaux[0],&lvar[2],&circuitConstants[7]); // line circom 30
while(Fr_isTrue(&expaux[0])){
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 0);
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ((1 * Fr_toInt(&lvar[2])) + 7)];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 7]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
ctx->componentMemory[ctx_index].sbct[cmp_index_ref] = std::thread(Aux_12_run_parallel,mySubcomponents[cmp_index_ref],ctx);
std::unique_lock<std::mutex> lkt(ctx->numThreadMutex);
ctx->ntcvs.wait(lkt, [ctx]() {return ctx->numThread <  ctx->maxThread; });
ctx->numThread++;

}
}
{
PFrElement aux_dest = &lvar[2];
// load src
Fr_add(&expaux[0],&lvar[2],&circuitConstants[0]); // line circom 30
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[2],&circuitConstants[7]); // line circom 30
}
{
uint aux_dest_index = ((1 * Fr_toInt(&lvar[1])) + 0);
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[1])) + 0)];
// load src
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 0);
{
int aux1 = cmp_index_ref;
int aux2 = 6;
for (int i = 0; i < 1; i++) {
ctx->numThreadMutex.lock();
ctx->numThread--;
ctx->numThreadMutex.unlock();
ctx->ntcvs.notify_one();
std::unique_lock<std::mutex> lk(ctx->componentMemory[mySubcomponents[aux1]].mutexes[aux2 + i]);
ctx->componentMemory[mySubcomponents[aux1]].cvs[aux2 + i].wait(lk, [ctx,mySubcomponents,aux1,aux2, i]() {return ctx->componentMemory[mySubcomponents[aux1]].outputIsSet[aux2 + i];});
std::unique_lock<std::mutex> lkt(ctx->numThreadMutex);
ctx->ntcvs.wait(lkt, [ctx]() {return ctx->numThread <  ctx->maxThread; });
ctx->numThread++;
}
}
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 6]);
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].lock();
ctx->componentMemory[ctx_index].outputIsSet[aux_dest_index]=true;
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].unlock();
ctx->componentMemory[ctx_index].cvs[aux_dest_index].notify_all();
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
Fr_add(&expaux[0],&lvar[1],&circuitConstants[0]); // line circom 21
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[7]); // line circom 21
}
{
for (uint i = 0; i < 7; i++) {
if (ctx->componentMemory[ctx_index].sbct[i].joinable()) {
ctx->componentMemory[ctx_index].sbct[i].join();
}
}
}
for (uint i = 0; i < 7; i++) {
ctx->componentMemory[ctx_index].mutexes[i].lock();
ctx->componentMemory[ctx_index].outputIsSet[i]=true;
ctx->componentMemory[ctx_index].mutexes[i].unlock();
ctx->componentMemory[ctx_index].cvs[i].notify_all();
}
ctx->numThreadMutex.lock();
ctx->numThread--;
ctx->numThreadMutex.unlock();
ctx->ntcvs.notify_one();
for (uint i = 0; i < 7; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void Aux_14_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 14;
ctx->componentMemory[coffset].templateName = "Aux";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 8;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
ctx->componentMemory[coffset].outputIsSet = new bool[8]();
ctx->componentMemory[coffset].mutexes = new std::mutex[8];
ctx->componentMemory[coffset].cvs = new std::condition_variable[8];
}

void Aux_14_run_parallel(uint ctx_index,Circom_CalcWit* ctx){
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
FrElement lvar[2];
uint sub_component_aux;
uint index_multiple_eq;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[8]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
uint aux_dest_index = 0;
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 8]);
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].lock();
ctx->componentMemory[ctx_index].outputIsSet[aux_dest_index]=true;
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].unlock();
ctx->componentMemory[ctx_index].cvs[aux_dest_index].notify_all();
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[8]); // line circom 7
while(Fr_isTrue(&expaux[0])){
{
uint aux_dest_index = ((1 * Fr_toInt(&lvar[1])) + 0);
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[1])) + 0)];
// load src
Fr_sub(&expaux[1],&lvar[1],&circuitConstants[0]); // line circom 8
Fr_mul(&expaux[0],&signalValues[mySignalStart + ((1 * Fr_toInt(&expaux[1])) + 0)],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[1])) + 8)]); // line circom 8
// end load src
Fr_copy(aux_dest,&expaux[0]);
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].lock();
ctx->componentMemory[ctx_index].outputIsSet[aux_dest_index]=true;
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].unlock();
ctx->componentMemory[ctx_index].cvs[aux_dest_index].notify_all();
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
Fr_add(&expaux[0],&lvar[1],&circuitConstants[0]); // line circom 7
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[8]); // line circom 7
}
for (uint i = 0; i < 8; i++) {
ctx->componentMemory[ctx_index].mutexes[i].lock();
ctx->componentMemory[ctx_index].outputIsSet[i]=true;
ctx->componentMemory[ctx_index].mutexes[i].unlock();
ctx->componentMemory[ctx_index].cvs[i].notify_all();
}
ctx->numThreadMutex.lock();
ctx->numThread--;
ctx->numThreadMutex.unlock();
ctx->ntcvs.notify_one();
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void MultiAux_15_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 15;
ctx->componentMemory[coffset].templateName = "MultiAux";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[8]{0};
ctx->componentMemory[coffset].sbct = new std::thread[8];
ctx->componentMemory[coffset].subcomponentsParallel = new bool[8];
ctx->componentMemory[coffset].outputIsSet = new bool[8]();
ctx->componentMemory[coffset].mutexes = new std::mutex[8];
ctx->componentMemory[coffset].cvs = new std::condition_variable[8];
}

void MultiAux_15_run_parallel(uint ctx_index,Circom_CalcWit* ctx){
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
FrElement lvar[3];
uint sub_component_aux;
uint index_multiple_eq;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[8]);
}
{
uint aux_create = 0;
int aux_cmp_num = 0+ctx_index+1;
uint csoffset = mySignalStart+9;
uint aux_dimensions[1] = {8};
for (uint i = 0; i < 8; i++) {
std::string new_cmp_name = "c_aux"+ctx->generate_position_array(aux_dimensions, 1, i);
Aux_14_create_parallel(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 16 ;
aux_cmp_num += 1;
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[8]); // line circom 21
while(Fr_isTrue(&expaux[0])){
Fr_mod(&expaux[1],&lvar[1],&circuitConstants[2]); // line circom 22
Fr_eq(&expaux[0],&expaux[1],&circuitConstants[1]); // line circom 22
if(Fr_isTrue(&expaux[0])){

}
{
PFrElement aux_dest = &lvar[2];
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
Fr_lt(&expaux[0],&lvar[2],&circuitConstants[8]); // line circom 30
while(Fr_isTrue(&expaux[0])){
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 0);
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ((1 * Fr_toInt(&lvar[2])) + 8)];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 8]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
ctx->componentMemory[ctx_index].sbct[cmp_index_ref] = std::thread(Aux_14_run_parallel,mySubcomponents[cmp_index_ref],ctx);
std::unique_lock<std::mutex> lkt(ctx->numThreadMutex);
ctx->ntcvs.wait(lkt, [ctx]() {return ctx->numThread <  ctx->maxThread; });
ctx->numThread++;

}
}
{
PFrElement aux_dest = &lvar[2];
// load src
Fr_add(&expaux[0],&lvar[2],&circuitConstants[0]); // line circom 30
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[2],&circuitConstants[8]); // line circom 30
}
{
uint aux_dest_index = ((1 * Fr_toInt(&lvar[1])) + 0);
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[1])) + 0)];
// load src
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 0);
{
int aux1 = cmp_index_ref;
int aux2 = 7;
for (int i = 0; i < 1; i++) {
ctx->numThreadMutex.lock();
ctx->numThread--;
ctx->numThreadMutex.unlock();
ctx->ntcvs.notify_one();
std::unique_lock<std::mutex> lk(ctx->componentMemory[mySubcomponents[aux1]].mutexes[aux2 + i]);
ctx->componentMemory[mySubcomponents[aux1]].cvs[aux2 + i].wait(lk, [ctx,mySubcomponents,aux1,aux2, i]() {return ctx->componentMemory[mySubcomponents[aux1]].outputIsSet[aux2 + i];});
std::unique_lock<std::mutex> lkt(ctx->numThreadMutex);
ctx->ntcvs.wait(lkt, [ctx]() {return ctx->numThread <  ctx->maxThread; });
ctx->numThread++;
}
}
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 7]);
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].lock();
ctx->componentMemory[ctx_index].outputIsSet[aux_dest_index]=true;
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].unlock();
ctx->componentMemory[ctx_index].cvs[aux_dest_index].notify_all();
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
Fr_add(&expaux[0],&lvar[1],&circuitConstants[0]); // line circom 21
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[8]); // line circom 21
}
{
for (uint i = 0; i < 8; i++) {
if (ctx->componentMemory[ctx_index].sbct[i].joinable()) {
ctx->componentMemory[ctx_index].sbct[i].join();
}
}
}
for (uint i = 0; i < 8; i++) {
ctx->componentMemory[ctx_index].mutexes[i].lock();
ctx->componentMemory[ctx_index].outputIsSet[i]=true;
ctx->componentMemory[ctx_index].mutexes[i].unlock();
ctx->componentMemory[ctx_index].cvs[i].notify_all();
}
ctx->numThreadMutex.lock();
ctx->numThread--;
ctx->numThreadMutex.unlock();
ctx->ntcvs.notify_one();
for (uint i = 0; i < 8; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void Aux_16_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 16;
ctx->componentMemory[coffset].templateName = "Aux";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 9;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
ctx->componentMemory[coffset].outputIsSet = new bool[9]();
ctx->componentMemory[coffset].mutexes = new std::mutex[9];
ctx->componentMemory[coffset].cvs = new std::condition_variable[9];
}

void Aux_16_run_parallel(uint ctx_index,Circom_CalcWit* ctx){
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
FrElement lvar[2];
uint sub_component_aux;
uint index_multiple_eq;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[9]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
uint aux_dest_index = 0;
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 9]);
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].lock();
ctx->componentMemory[ctx_index].outputIsSet[aux_dest_index]=true;
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].unlock();
ctx->componentMemory[ctx_index].cvs[aux_dest_index].notify_all();
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[9]); // line circom 7
while(Fr_isTrue(&expaux[0])){
{
uint aux_dest_index = ((1 * Fr_toInt(&lvar[1])) + 0);
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[1])) + 0)];
// load src
Fr_sub(&expaux[1],&lvar[1],&circuitConstants[0]); // line circom 8
Fr_mul(&expaux[0],&signalValues[mySignalStart + ((1 * Fr_toInt(&expaux[1])) + 0)],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[1])) + 9)]); // line circom 8
// end load src
Fr_copy(aux_dest,&expaux[0]);
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].lock();
ctx->componentMemory[ctx_index].outputIsSet[aux_dest_index]=true;
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].unlock();
ctx->componentMemory[ctx_index].cvs[aux_dest_index].notify_all();
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
Fr_add(&expaux[0],&lvar[1],&circuitConstants[0]); // line circom 7
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[9]); // line circom 7
}
for (uint i = 0; i < 9; i++) {
ctx->componentMemory[ctx_index].mutexes[i].lock();
ctx->componentMemory[ctx_index].outputIsSet[i]=true;
ctx->componentMemory[ctx_index].mutexes[i].unlock();
ctx->componentMemory[ctx_index].cvs[i].notify_all();
}
ctx->numThreadMutex.lock();
ctx->numThread--;
ctx->numThreadMutex.unlock();
ctx->ntcvs.notify_one();
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void MultiAux_17_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 17;
ctx->componentMemory[coffset].templateName = "MultiAux";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[9]{0};
ctx->componentMemory[coffset].sbct = new std::thread[9];
ctx->componentMemory[coffset].subcomponentsParallel = new bool[9];
ctx->componentMemory[coffset].outputIsSet = new bool[9]();
ctx->componentMemory[coffset].mutexes = new std::mutex[9];
ctx->componentMemory[coffset].cvs = new std::condition_variable[9];
}

void MultiAux_17_run_parallel(uint ctx_index,Circom_CalcWit* ctx){
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
FrElement lvar[3];
uint sub_component_aux;
uint index_multiple_eq;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[9]);
}
{
uint aux_create = 0;
int aux_cmp_num = 0+ctx_index+1;
uint csoffset = mySignalStart+10;
uint aux_dimensions[1] = {9};
for (uint i = 0; i < 9; i++) {
std::string new_cmp_name = "c_aux"+ctx->generate_position_array(aux_dimensions, 1, i);
Aux_16_create_parallel(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 18 ;
aux_cmp_num += 1;
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[9]); // line circom 21
while(Fr_isTrue(&expaux[0])){
Fr_mod(&expaux[1],&lvar[1],&circuitConstants[2]); // line circom 22
Fr_eq(&expaux[0],&expaux[1],&circuitConstants[1]); // line circom 22
if(Fr_isTrue(&expaux[0])){

}
{
PFrElement aux_dest = &lvar[2];
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
Fr_lt(&expaux[0],&lvar[2],&circuitConstants[9]); // line circom 30
while(Fr_isTrue(&expaux[0])){
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 0);
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ((1 * Fr_toInt(&lvar[2])) + 9)];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 9]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
ctx->componentMemory[ctx_index].sbct[cmp_index_ref] = std::thread(Aux_16_run_parallel,mySubcomponents[cmp_index_ref],ctx);
std::unique_lock<std::mutex> lkt(ctx->numThreadMutex);
ctx->ntcvs.wait(lkt, [ctx]() {return ctx->numThread <  ctx->maxThread; });
ctx->numThread++;

}
}
{
PFrElement aux_dest = &lvar[2];
// load src
Fr_add(&expaux[0],&lvar[2],&circuitConstants[0]); // line circom 30
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[2],&circuitConstants[9]); // line circom 30
}
{
uint aux_dest_index = ((1 * Fr_toInt(&lvar[1])) + 0);
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[1])) + 0)];
// load src
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 0);
{
int aux1 = cmp_index_ref;
int aux2 = 8;
for (int i = 0; i < 1; i++) {
ctx->numThreadMutex.lock();
ctx->numThread--;
ctx->numThreadMutex.unlock();
ctx->ntcvs.notify_one();
std::unique_lock<std::mutex> lk(ctx->componentMemory[mySubcomponents[aux1]].mutexes[aux2 + i]);
ctx->componentMemory[mySubcomponents[aux1]].cvs[aux2 + i].wait(lk, [ctx,mySubcomponents,aux1,aux2, i]() {return ctx->componentMemory[mySubcomponents[aux1]].outputIsSet[aux2 + i];});
std::unique_lock<std::mutex> lkt(ctx->numThreadMutex);
ctx->ntcvs.wait(lkt, [ctx]() {return ctx->numThread <  ctx->maxThread; });
ctx->numThread++;
}
}
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 8]);
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].lock();
ctx->componentMemory[ctx_index].outputIsSet[aux_dest_index]=true;
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].unlock();
ctx->componentMemory[ctx_index].cvs[aux_dest_index].notify_all();
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
Fr_add(&expaux[0],&lvar[1],&circuitConstants[0]); // line circom 21
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[9]); // line circom 21
}
{
for (uint i = 0; i < 9; i++) {
if (ctx->componentMemory[ctx_index].sbct[i].joinable()) {
ctx->componentMemory[ctx_index].sbct[i].join();
}
}
}
for (uint i = 0; i < 9; i++) {
ctx->componentMemory[ctx_index].mutexes[i].lock();
ctx->componentMemory[ctx_index].outputIsSet[i]=true;
ctx->componentMemory[ctx_index].mutexes[i].unlock();
ctx->componentMemory[ctx_index].cvs[i].notify_all();
}
ctx->numThreadMutex.lock();
ctx->numThread--;
ctx->numThreadMutex.unlock();
ctx->ntcvs.notify_one();
for (uint i = 0; i < 9; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void Main_18_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 18;
ctx->componentMemory[coffset].templateName = "Main";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[10]{0};
ctx->componentMemory[coffset].sbct = new std::thread[10];
ctx->componentMemory[coffset].subcomponentsParallel = new bool[10];
}

void Main_18_run(uint ctx_index,Circom_CalcWit* ctx){
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
FrElement lvar[2];
uint sub_component_aux;
uint index_multiple_eq;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[10]);
}
{
uint aux_create = 1;
int aux_cmp_num = 0+ctx_index+1;
uint csoffset = mySignalStart+11;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "c_aux[1]";
MultiAux_1_create_parallel(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 0 ;
aux_cmp_num += 0;
}
}
{
uint aux_create = 2;
int aux_cmp_num = 2+ctx_index+1;
uint csoffset = mySignalStart+15;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "c_aux[2]";
MultiAux_3_create_parallel(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 0 ;
aux_cmp_num += 0;
}
}
{
uint aux_create = 3;
int aux_cmp_num = 5+ctx_index+1;
uint csoffset = mySignalStart+26;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "c_aux[3]";
MultiAux_5_create_parallel(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 0 ;
aux_cmp_num += 0;
}
}
{
uint aux_create = 4;
int aux_cmp_num = 9+ctx_index+1;
uint csoffset = mySignalStart+48;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "c_aux[4]";
MultiAux_7_create_parallel(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 0 ;
aux_cmp_num += 0;
}
}
{
uint aux_create = 5;
int aux_cmp_num = 14+ctx_index+1;
uint csoffset = mySignalStart+85;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "c_aux[5]";
MultiAux_9_create_parallel(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 0 ;
aux_cmp_num += 0;
}
}
{
uint aux_create = 6;
int aux_cmp_num = 20+ctx_index+1;
uint csoffset = mySignalStart+141;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "c_aux[6]";
MultiAux_11_create_parallel(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 0 ;
aux_cmp_num += 0;
}
}
{
uint aux_create = 7;
int aux_cmp_num = 27+ctx_index+1;
uint csoffset = mySignalStart+220;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "c_aux[7]";
MultiAux_13_create_parallel(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 0 ;
aux_cmp_num += 0;
}
}
{
uint aux_create = 8;
int aux_cmp_num = 35+ctx_index+1;
uint csoffset = mySignalStart+326;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "c_aux[8]";
MultiAux_15_create_parallel(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 0 ;
aux_cmp_num += 0;
}
}
{
uint aux_create = 9;
int aux_cmp_num = 44+ctx_index+1;
uint csoffset = mySignalStart+463;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "c_aux[9]";
MultiAux_17_create_parallel(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 0 ;
aux_cmp_num += 0;
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[10]); // line circom 48
while(Fr_isTrue(&expaux[0])){
Fr_mod(&expaux[1],&lvar[1],&circuitConstants[2]); // line circom 49
Fr_eq(&expaux[0],&expaux[1],&circuitConstants[1]); // line circom 49
if(Fr_isTrue(&expaux[0])){

}
{
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 0);
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[1].offset];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 10]);
}
// run sub component if needed
if(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1)){
ctx->componentMemory[ctx_index].sbct[cmp_index_ref] = std::thread((*_functionTableParallel[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId]),mySubcomponents[cmp_index_ref],ctx);
std::unique_lock<std::mutex> lkt(ctx->numThreadMutex);
ctx->ntcvs.wait(lkt, [ctx]() {return ctx->numThread <  ctx->maxThread; });
ctx->numThread++;

}
}
{
PFrElement aux_dest = &lvar[1];
// load src
Fr_add(&expaux[0],&lvar[1],&circuitConstants[0]); // line circom 48
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[10]); // line circom 48
}
{
PFrElement aux_dest = &signalValues[mySignalStart + 0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[10]); // line circom 58
while(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[1])) + 0)];
// load src
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 0);
Fr_sub(&expaux[0],&lvar[1],&circuitConstants[0]); // line circom 59
{
int aux1 = cmp_index_ref;
int aux2 = ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[0].offset+(Fr_toInt(&expaux[0]))*ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[0].size;
for (int i = 0; i < 1; i++) {
ctx->numThreadMutex.lock();
ctx->numThread--;
ctx->numThreadMutex.unlock();
ctx->ntcvs.notify_one();
std::unique_lock<std::mutex> lk(ctx->componentMemory[mySubcomponents[aux1]].mutexes[aux2 + i]);
ctx->componentMemory[mySubcomponents[aux1]].cvs[aux2 + i].wait(lk, [ctx,mySubcomponents,aux1,aux2, i]() {return ctx->componentMemory[mySubcomponents[aux1]].outputIsSet[aux2 + i];});
std::unique_lock<std::mutex> lkt(ctx->numThreadMutex);
ctx->ntcvs.wait(lkt, [ctx]() {return ctx->numThread <  ctx->maxThread; });
ctx->numThread++;
}
}
// end load src
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[0].offset+(Fr_toInt(&expaux[0]))*ctx->templateInsId2IOSignalInfo[ctx->componentMemory[mySubcomponents[cmp_index_ref]].templateId].defs[0].size]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
Fr_add(&expaux[0],&lvar[1],&circuitConstants[0]); // line circom 58
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[10]); // line circom 58
}
{
for (uint i = 0; i < 10; i++) {
if (ctx->componentMemory[ctx_index].sbct[i].joinable()) {
ctx->componentMemory[ctx_index].sbct[i].join();
}
}
}
for (uint i = 0; i < 10; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void run(Circom_CalcWit* ctx){
Main_18_create(1,0,ctx,"main",0);
Main_18_run(0,ctx);
}

