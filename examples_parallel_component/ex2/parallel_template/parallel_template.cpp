#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "circom.hpp"
#include "calcwit.hpp"
void Aux_0_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Aux_0_run_parallel(uint ctx_index,Circom_CalcWit* ctx);
void MultiAux_1_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void MultiAux_1_run_parallel(uint ctx_index,Circom_CalcWit* ctx);
void Main_2_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Main_2_run(uint ctx_index,Circom_CalcWit* ctx);
Circom_TemplateFunction _functionTable[3] = { 
NULL,
NULL,
Main_2_run };
Circom_TemplateFunction _functionTableParallel[3] = { 
Aux_0_run_parallel,
MultiAux_1_run_parallel,
NULL };
uint get_main_input_signal_start() {return 4;}

uint get_main_input_signal_no() {return 1;}

uint get_total_signal_no() {return 27;}

uint get_number_of_components() {return 5;}

uint get_size_of_input_hashmap() {return 256;}

uint get_size_of_witness() {return 27;}

uint get_size_of_constants() {return 3;}

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
void Aux_0_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 0;
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
FrElement expaux[3];
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
Fr_copy(aux_dest,&circuitConstants[2]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[0]); // line circom 7
while(Fr_isTrue(&expaux[0])){
{
uint aux_dest_index = ((1 * Fr_toInt(&lvar[1])) + 0);
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[1])) + 0)];
// load src
Fr_sub(&expaux[1],&lvar[1],&circuitConstants[2]); // line circom 8
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
Fr_add(&expaux[0],&lvar[1],&circuitConstants[2]); // line circom 7
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[0]); // line circom 7
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

void MultiAux_1_create_parallel(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 1;
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
uint csoffset = mySignalStart+4;
uint aux_dimensions[1] = {3};
for (uint i = 0; i < 3; i++) {
std::string new_cmp_name = "c_aux"+ctx->generate_position_array(aux_dimensions, 1, i);
Aux_0_create_parallel(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
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
Fr_lt(&expaux[0],&lvar[2],&circuitConstants[0]); // line circom 26
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
ctx->componentMemory[ctx_index].sbct[cmp_index_ref] = std::thread(Aux_0_run_parallel,mySubcomponents[cmp_index_ref],ctx);
std::unique_lock<std::mutex> lkt(ctx->numThreadMutex);
ctx->ntcvs.wait(lkt, [ctx]() {return ctx->numThread <  ctx->maxThread; });
ctx->numThread++;

}
}
{
PFrElement aux_dest = &lvar[2];
// load src
Fr_add(&expaux[0],&lvar[2],&circuitConstants[2]); // line circom 26
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[2],&circuitConstants[0]); // line circom 26
}
{
uint aux_dest_index = ((1 * Fr_toInt(&lvar[1])) + 0);
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[1])) + 0)];
// load src
uint cmp_index_ref = ((1 * Fr_toInt(&lvar[1])) + 0);
{
int aux1 = cmp_index_ref;
int aux2 = ((1 * Fr_toInt(&lvar[1])) + 0);
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
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ((1 * Fr_toInt(&lvar[1])) + 0)]);
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].lock();
ctx->componentMemory[ctx_index].outputIsSet[aux_dest_index]=true;
ctx->componentMemory[ctx_index].mutexes[aux_dest_index].unlock();
ctx->componentMemory[ctx_index].cvs[aux_dest_index].notify_all();
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
Fr_add(&expaux[0],&lvar[1],&circuitConstants[2]); // line circom 21
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[0]); // line circom 21
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

void Main_2_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 2;
ctx->componentMemory[coffset].templateName = "Main";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
ctx->componentMemory[coffset].sbct = new std::thread[1];
ctx->componentMemory[coffset].subcomponentsParallel = new bool[1];
}

void Main_2_run(uint ctx_index,Circom_CalcWit* ctx){
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
Fr_copy(aux_dest,&circuitConstants[0]);
}
{
uint aux_create = 0;
int aux_cmp_num = 0+ctx_index+1;
uint csoffset = mySignalStart+4;
for (uint i = 0; i < 1; i++) {
std::string new_cmp_name = "c_aux";
MultiAux_1_create_parallel(csoffset,aux_cmp_num,ctx,new_cmp_name,myId);
mySubcomponents[aux_create+i] = aux_cmp_num;
csoffset += 22 ;
aux_cmp_num += 4;
}
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
{
uint cmp_index_ref = 0;
{
PFrElement aux_dest = &ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3];
// load src
// end load src
Fr_copy(aux_dest,&signalValues[mySignalStart + 3]);
}
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
ctx->componentMemory[ctx_index].sbct[cmp_index_ref] = std::thread(MultiAux_1_run_parallel,mySubcomponents[cmp_index_ref],ctx);
std::unique_lock<std::mutex> lkt(ctx->numThreadMutex);
ctx->ntcvs.wait(lkt, [ctx]() {return ctx->numThread <  ctx->maxThread; });
ctx->numThread++;
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[0]); // line circom 49
while(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[1])) + 0)];
// load src
uint cmp_index_ref = 0;
{
int aux1 = cmp_index_ref;
int aux2 = ((1 * Fr_toInt(&lvar[1])) + 0);
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
Fr_copy(aux_dest,&ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ((1 * Fr_toInt(&lvar[1])) + 0)]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
Fr_add(&expaux[0],&lvar[1],&circuitConstants[2]); // line circom 49
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[1],&circuitConstants[0]); // line circom 49
}
{
for (uint i = 0; i < 1; i++) {
if (ctx->componentMemory[ctx_index].sbct[i].joinable()) {
ctx->componentMemory[ctx_index].sbct[i].join();
}
}
}
for (uint i = 0; i < 1; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void run(Circom_CalcWit* ctx){
Main_2_create(1,0,ctx,"main",0);
Main_2_run(0,ctx);
}

