model in DY-complex-Not-Combine.bug
# data in DY-complex.dat
data in DY-complex-Not-Combine.dat
compile, nchains(1)

#compile, nchains(3)
#   parameters in DY-complex.par

initialize

update 20000

monitor set peeB,   thin(10)
monitor set pemuB,  thin(10)
monitor set pmueB,  thin(10)
monitor set pmumuB, thin(10)

monitor set peeA,   thin(10)
monitor set pemuA,  thin(10)
monitor set pmueA,  thin(10)
monitor set pmumuA, thin(10)

monitor set peeBmet,   thin(10)
monitor set pemuBmet,  thin(10)
monitor set pmueBmet,  thin(10)
monitor set pmumuBmet, thin(10)

monitor set peeAmet,   thin(10)
monitor set pemuAmet,  thin(10)
monitor set pmueAmet,  thin(10)
monitor set pmumuAmet, thin(10)

monitor set totPBmet, thin(10)
monitor set totPAmet, thin(10)
monitor set totP, thin(10)

monitor set pmumuAmetFinal, thin(10)
monitor set pmumuBmetFinal, thin(10)

monitor set peeAmetFinal, thin(10)
monitor set peeBmetFinal, thin(10)


monitor set pA, thin(10)
monitor set pB, thin(10)

monitor set Ree, thin(10)
monitor set Rmumu, thin(10)

monitor set ReeSimple, thin(10)
monitor set RmumuSimple, thin(10)

monitor set e1A,  thin(10)
monitor set e2A,  thin(10)
monitor set mu1A, thin(10)
monitor set mu2A, thin(10)

monitor set e1Amet,  thin(10)
monitor set e2Amet,  thin(10)
monitor set mu1Amet, thin(10)
monitor set mu2Amet, thin(10)

monitor set e1AOther,  thin(10)
monitor set e2AOther,  thin(10)
monitor set mu1AOther, thin(10)
monitor set mu2AOther, thin(10)

monitor set e1AmetOther,  thin(10)
monitor set e2AmetOther,  thin(10)
monitor set mu1AmetOther, thin(10)
monitor set mu2AmetOther, thin(10)

monitor set e1B,  thin(10)
monitor set e2B,  thin(10)
monitor set mu1B, thin(10)
monitor set mu2B, thin(10)

monitor set e1Bmet,  thin(10)
monitor set e2Bmet,  thin(10)
monitor set mu1Bmet, thin(10)
monitor set mu2Bmet, thin(10)

monitor set e1BOther,  thin(10)
monitor set e2BOther,  thin(10)
monitor set mu1BOther, thin(10)
monitor set mu2BOther, thin(10)

monitor set e1BmetOther,  thin(10)
monitor set e2BmetOther,  thin(10)
monitor set mu1BmetOther, thin(10)
monitor set mu2BmetOther, thin(10)


monitor set meanNtotABeemet, thin(10)
monitor set NtotABeemet, thin(10)
monitor set NtotABeemetOther, thin(10)
monitor set NtotABeemetDY, thin(10)
monitor set NAeemetDY, thin(10)
monitor set meanNAeemetDY, thin(10)
monitor set NAeemetDYSimple, thin(10)
monitor set NAeemetDYSimpleSimple, thin(10)


monitor set meanNtotABmumumet, thin(10)
monitor set NtotABmumumet, thin(10)
monitor set NtotABmumumetOther, thin(10)
monitor set NtotABmumumetDY, thin(10)
monitor set NAmumumetDY, thin(10)
monitor set meanNAmumumetDY, thin(10)
monitor set NAmumumetDYSimple, thin(10)
monitor set NAmumumetDYSimpleSimple, thin(10)


monitor set NAeemetDYM,   thin(10)
monitor set NAmumumetDYM, thin(10)

monitor set peeBFinal,   thin(10)
monitor set pmumuBFinal, thin(10)

monitor set pAmet, thin(10)
monitor set peeAmet, thin(10)
monitor set pmumuAmet, thin(10)

monitor set NAeemetAllM,   thin(10)
monitor set NAmumumetAllM, thin(10)

monitor set NAeemetDYexact,     thin(10)
monitor set NAmumumetDYexact,   thin(10)

monitor set NeeBmetDYOther,     thin(10)
monitor set NmumuBmetDYOther,   thin(10)


monitor set NDYeeA,     thin(10)
monitor set NDYmumuA,   thin(10)
monitor set NDYeeB,     thin(10)
monitor set NDYmumuB,   thin(10)


monitor set NeeAmet,     thin(10)
monitor set NemuAmet,    thin(10)
monitor set NmueAmet,    thin(10)
monitor set NmumuAmet,   thin(10)
monitor set NeeBmet,     thin(10)
monitor set NemuBmet,    thin(10)
monitor set NmueBmet,    thin(10)
monitor set NmumuBmet,   thin(10)

monitor set NeeA,     thin(10)
monitor set NemuA,    thin(10)
monitor set NmueA,    thin(10)
monitor set NmumuA,   thin(10)
monitor set NeeB,     thin(10)
monitor set NemuB,    thin(10)
monitor set NmueB,    thin(10)
monitor set NmumuB,   thin(10)


monitor set e1BmetOther,     thin(10)
monitor set e2BmetOther,     thin(10)
monitor set mu1BmetOther,    thin(10)
monitor set mu2BmetOther,   thin(10)

monitor set e1BOther,     thin(10)
monitor set e2BOther,     thin(10)
monitor set mu1BOther,    thin(10)
monitor set mu2BOther,   thin(10)
monitor set e1AOther,     thin(10)
monitor set e2AOther,     thin(10)
monitor set mu1AOther,    thin(10)
monitor set mu2AOther,   thin(10)

monitor set ReeToUse,     thin(10)
monitor set RmumuToUse,   thin(10)

monitor set OtherBmetInit,   thin(10)
monitor set OtherAmetInit,   thin(10)
monitor set OtherBInit,   thin(10)
monitor set OtherAInit,   thin(10)

monitor set NtotA,   thin(10)
monitor set NtotB,   thin(10)
monitor set Ntot,    thin(10)

monitor set NDYMCAmet,   thin(10)
monitor set NDYMCBmet,   thin(10)
monitor set NotherMCAmet,   thin(10)
monitor set NotherMCBmet,   thin(10)

monitor set NDYMCA,   thin(10)
monitor set NDYMCB,   thin(10)
monitor set NotherMCA,   thin(10)
monitor set NotherMCB,   thin(10)

monitor set DYAInit,      thin(10)
monitor set DYBInit,      thin(10)

monitor set DYAmetInit,      thin(10)
monitor set DYBmetInit,      thin(10)

monitor set NtotAmet,      thin(10)
monitor set NtotBmet,      thin(10)

monitor set NtotA,      thin(10)
monitor set NtotB,      thin(10)

monitor set NDYmumuADYM,    thin(10)
monitor set NDYeeADYM,      thin(10)


monitor set fakeDYAmetInit,      thin(10)
monitor set fakeOtherAmetInit,   thin(10)

monitor set fakeDYAInit,      thin(10)
monitor set fakeOtherAInit,   thin(10)
monitor set fakeDYBInit,      thin(10)
monitor set fakeOtherBInit,   thin(10)

monitor set fakee1A,  thin(10)
monitor set fakee2A,  thin(10)
monitor set fakemu1A, thin(10)
monitor set fakemu2A, thin(10)

monitor set fakee1Amet,  thin(10)
monitor set fakee2Amet,  thin(10)
monitor set fakemu1Amet, thin(10)
monitor set fakemu2Amet, thin(10)

monitor set fakee1AOther,  thin(10)
monitor set fakee2AOther,  thin(10)
monitor set fakemu1AOther, thin(10)
monitor set fakemu2AOther, thin(10)

monitor set fakee1AmetOther,  thin(10)
monitor set fakee2AmetOther,  thin(10)
monitor set fakemu1AmetOther, thin(10)
monitor set fakemu2AmetOther, thin(10)

monitor set fakee1B,  thin(10)
monitor set fakee2B,  thin(10)
monitor set fakemu1B, thin(10)
monitor set fakemu2B, thin(10)

monitor set fakee1Bmet,  thin(10)
monitor set fakee2Bmet,  thin(10)
monitor set fakemu1Bmet, thin(10)
monitor set fakemu2Bmet, thin(10)

monitor set fakee1BOther,  thin(10)
monitor set fakee2BOther,  thin(10)
monitor set fakemu1BOther, thin(10)
monitor set fakemu2BOther, thin(10)

monitor set fakee1BmetOther,  thin(10)
monitor set fakee2BmetOther,  thin(10)
monitor set fakemu1BmetOther, thin(10)
monitor set fakemu2BmetOther, thin(10)



update 100000
coda *
data to useddata
samplers to usedsamplers

 
  
