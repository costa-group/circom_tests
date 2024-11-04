#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "circom.hpp"
#include "calcwit.hpp"
void Main_0_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Main_0_run(uint ctx_index,Circom_CalcWit* ctx);
void EscalarMulW4Table_0(Circom_CalcWit* ctx,FrElement* lvar,uint componentFather,FrElement* destination,int destination_size);
void pointAdd_1(Circom_CalcWit* ctx,FrElement* lvar,uint componentFather,FrElement* destination,int destination_size);
Circom_TemplateFunction _functionTable[1] = { 
Main_0_run };
Circom_TemplateFunction _functionTableParallel[1] = { 
NULL };
uint get_main_input_signal_start() {return 33;}

uint get_main_input_signal_no() {return 0;}

uint get_total_signal_no() {return 33;}

uint get_number_of_components() {return 1;}

uint get_size_of_input_hashmap() {return 256;}

uint get_size_of_witness() {return 33;}

uint get_size_of_constants() {return 21;}

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
void EscalarMulW4Table_0(Circom_CalcWit* ctx,FrElement* lvar,uint componentFather,FrElement* destination,int destination_size){
FrElement* circuitConstants = ctx->circuitConstants;
FrElement expaux[4];
std::string myTemplateName = "EscalarMulW4Table";
u64 myId = componentFather;
{
PFrElement aux_dest = &lvar[35];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
{
PFrElement aux_dest = &lvar[36];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
{
PFrElement aux_dest = &lvar[3];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[35],2);
}
{
PFrElement aux_dest = &lvar[5];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[35],2);
}
{
PFrElement aux_dest = &lvar[7];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[35],2);
}
{
PFrElement aux_dest = &lvar[9];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[35],2);
}
{
PFrElement aux_dest = &lvar[11];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[35],2);
}
{
PFrElement aux_dest = &lvar[13];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[35],2);
}
{
PFrElement aux_dest = &lvar[15];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[35],2);
}
{
PFrElement aux_dest = &lvar[17];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[35],2);
}
{
PFrElement aux_dest = &lvar[19];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[35],2);
}
{
PFrElement aux_dest = &lvar[21];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[35],2);
}
{
PFrElement aux_dest = &lvar[23];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[35],2);
}
{
PFrElement aux_dest = &lvar[25];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[35],2);
}
{
PFrElement aux_dest = &lvar[27];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[35],2);
}
{
PFrElement aux_dest = &lvar[29];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[35],2);
}
{
PFrElement aux_dest = &lvar[31];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[35],2);
}
{
PFrElement aux_dest = &lvar[33];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[35],2);
}
{
PFrElement aux_dest = &lvar[37];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
{
PFrElement aux_dest = &lvar[38];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
{
PFrElement aux_dest = &lvar[39];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
{
PFrElement aux_dest = &lvar[40];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
{
PFrElement aux_dest = &lvar[41];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
{
PFrElement aux_dest = &lvar[40];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[0],2);
}
{
PFrElement aux_dest = &lvar[37];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
Fr_mul(&expaux[1],&lvar[2],&circuitConstants[6]); // line circom 39
Fr_lt(&expaux[0],&lvar[37],&expaux[1]); // line circom 39
while(Fr_isTrue(&expaux[0])){
{

// start of call bucket
FrElement lvarcall[8];
// copying argument 0
Fr_copy(&lvarcall[0],&lvar[40]);
// end copying argument 0
// copying argument 1
Fr_copy(&lvarcall[1],&lvar[41]);
// end copying argument 1
// copying argument 2
Fr_copy(&lvarcall[2],&lvar[40]);
// end copying argument 2
// copying argument 3
Fr_copy(&lvarcall[3],&lvar[41]);
// end copying argument 3
pointAdd_1(ctx,lvarcall,myId,&lvar[40],2);
// end call bucket
}

{
PFrElement aux_dest = &lvar[37];
// load src
Fr_add(&expaux[0],&lvar[37],&circuitConstants[1]); // line circom 39
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_mul(&expaux[1],&lvar[2],&circuitConstants[6]); // line circom 39
Fr_lt(&expaux[0],&lvar[37],&expaux[1]); // line circom 39
}
{
PFrElement aux_dest = &lvar[3];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
{
PFrElement aux_dest = &lvar[4];
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
Fr_lt(&expaux[0],&lvar[37],&circuitConstants[18]); // line circom 45
while(Fr_isTrue(&expaux[0])){
{

// start of call bucket
FrElement lvarcall[8];
// copying argument 0
Fr_sub(&expaux[1],&lvar[37],&circuitConstants[1]); // line circom 46
Fr_copy(&lvarcall[0],&lvar[(((2 * Fr_toInt(&expaux[1])) + 0) + 3)]);
// end copying argument 0
// copying argument 1
Fr_sub(&expaux[2],&lvar[37],&circuitConstants[1]); // line circom 46
Fr_copy(&lvarcall[1],&lvar[(((2 * Fr_toInt(&expaux[2])) + 1) + 3)]);
// end copying argument 1
// copying argument 2
Fr_copy(&lvarcall[2],&lvar[40]);
// end copying argument 2
// copying argument 3
Fr_copy(&lvarcall[3],&lvar[41]);
// end copying argument 3
pointAdd_1(ctx,lvarcall,myId,&lvar[38],2);
// end call bucket
}

{
PFrElement aux_dest = &lvar[(((2 * Fr_toInt(&lvar[37])) + 0) + 3)];
// load src
// end load src
Fr_copy(aux_dest,&lvar[38]);
}
{
PFrElement aux_dest = &lvar[(((2 * Fr_toInt(&lvar[37])) + 1) + 3)];
// load src
// end load src
Fr_copy(aux_dest,&lvar[39]);
}
{
PFrElement aux_dest = &lvar[37];
// load src
Fr_add(&expaux[0],&lvar[37],&circuitConstants[1]); // line circom 45
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[37],&circuitConstants[18]); // line circom 45
}
// return bucket
Fr_copyn(destination,&lvar[3],std::min(32,destination_size));
return;
}

void pointAdd_1(Circom_CalcWit* ctx,FrElement* lvar,uint componentFather,FrElement* destination,int destination_size){
FrElement* circuitConstants = ctx->circuitConstants;
FrElement expaux[9];
std::string myTemplateName = "pointAdd";
u64 myId = componentFather;
{
PFrElement aux_dest = &lvar[4];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[19]);
}
{
PFrElement aux_dest = &lvar[5];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[20]);
}
{
PFrElement aux_dest = &lvar[6];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
{
PFrElement aux_dest = &lvar[7];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
{
PFrElement aux_dest = &lvar[6];
// load src
Fr_mul(&expaux[2],&lvar[0],&lvar[3]); // line circom 26
Fr_mul(&expaux[3],&lvar[1],&lvar[2]); // line circom 26
Fr_add(&expaux[1],&expaux[2],&expaux[3]); // line circom 26
Fr_mul(&expaux[7],&circuitConstants[20],&lvar[0]); // line circom 26
Fr_mul(&expaux[6],&expaux[7],&lvar[2]); // line circom 26
Fr_mul(&expaux[5],&expaux[6],&lvar[1]); // line circom 26
Fr_mul(&expaux[4],&expaux[5],&lvar[3]); // line circom 26
Fr_add(&expaux[2],&circuitConstants[1],&expaux[4]); // line circom 26
Fr_div(&expaux[0],&expaux[1],&expaux[2]); // line circom 26
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{
PFrElement aux_dest = &lvar[7];
// load src
Fr_mul(&expaux[2],&lvar[1],&lvar[3]); // line circom 27
Fr_mul(&expaux[4],&circuitConstants[19],&lvar[0]); // line circom 27
Fr_mul(&expaux[3],&expaux[4],&lvar[2]); // line circom 27
Fr_sub(&expaux[1],&expaux[2],&expaux[3]); // line circom 27
Fr_mul(&expaux[7],&circuitConstants[20],&lvar[0]); // line circom 27
Fr_mul(&expaux[6],&expaux[7],&lvar[2]); // line circom 27
Fr_mul(&expaux[5],&expaux[6],&lvar[1]); // line circom 27
Fr_mul(&expaux[4],&expaux[5],&lvar[3]); // line circom 27
Fr_sub(&expaux[2],&circuitConstants[1],&expaux[4]); // line circom 27
Fr_div(&expaux[0],&expaux[1],&expaux[2]); // line circom 27
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
// return bucket
Fr_copyn(destination,&lvar[6],std::min(2,destination_size));
return;
}

// template declarations
void Main_0_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 0;
ctx->componentMemory[coffset].templateName = "Main";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 0;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
Main_0_run(coffset,ctx);
}

void Main_0_run(uint ctx_index,Circom_CalcWit* ctx){
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
FrElement lvar[37];
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
Fr_copy(aux_dest,&circuitConstants[0]);
}
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
PFrElement aux_dest = &lvar[34];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
{
PFrElement aux_dest = &lvar[35];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
{
PFrElement aux_dest = &lvar[2];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[34],2);
}
{
PFrElement aux_dest = &lvar[4];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[34],2);
}
{
PFrElement aux_dest = &lvar[6];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[34],2);
}
{
PFrElement aux_dest = &lvar[8];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[34],2);
}
{
PFrElement aux_dest = &lvar[10];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[34],2);
}
{
PFrElement aux_dest = &lvar[12];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[34],2);
}
{
PFrElement aux_dest = &lvar[14];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[34],2);
}
{
PFrElement aux_dest = &lvar[16];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[34],2);
}
{
PFrElement aux_dest = &lvar[18];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[34],2);
}
{
PFrElement aux_dest = &lvar[20];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[34],2);
}
{
PFrElement aux_dest = &lvar[22];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[34],2);
}
{
PFrElement aux_dest = &lvar[24];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[34],2);
}
{
PFrElement aux_dest = &lvar[26];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[34],2);
}
{
PFrElement aux_dest = &lvar[28];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[34],2);
}
{
PFrElement aux_dest = &lvar[30];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[34],2);
}
{
PFrElement aux_dest = &lvar[32];
// load src
// end load src
Fr_copyn(aux_dest,&lvar[34],2);
}
{

// start of call bucket
FrElement lvarcall[42];
// copying argument 0
Fr_copyn(&lvarcall[0],&lvar[0],2);
// end copying argument 0
// copying argument 1
Fr_copy(&lvarcall[2],&circuitConstants[0]);
// end copying argument 1
EscalarMulW4Table_0(ctx,lvarcall,myId,&lvar[2],32);
// end call bucket
}

{
PFrElement aux_dest = &lvar[36];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
Fr_lt(&expaux[0],&lvar[36],&circuitConstants[18]); // line circom 14
while(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &signalValues[mySignalStart + (((2 * Fr_toInt(&lvar[36])) + 0) + 0)];
// load src
// end load src
Fr_copy(aux_dest,&lvar[(((2 * Fr_toInt(&lvar[36])) + 0) + 2)]);
}
{
PFrElement aux_dest = &signalValues[mySignalStart + (((2 * Fr_toInt(&lvar[36])) + 1) + 0)];
// load src
// end load src
Fr_copy(aux_dest,&lvar[(((2 * Fr_toInt(&lvar[36])) + 1) + 2)]);
}
{
PFrElement aux_dest = &lvar[36];
// load src
Fr_add(&expaux[0],&lvar[36],&circuitConstants[1]); // line circom 14
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[36],&circuitConstants[18]); // line circom 14
}
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void run(Circom_CalcWit* ctx){
Main_0_create(1,0,ctx,"main",0);
// no input signals, the creation will automatically execute
}

