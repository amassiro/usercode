model in DY-complex-Combine.bug
data in DY-complex.dat
compile, nchains(3)
#   parameters in DY-complex.par

initialize

update 1000


monitor set peeB,   thin(10)
monitor set pemuB,  thin(10)
monitor set pmueB,  thin(10)
monitor set pmumuB, thin(10)

monitor set peeA,   thin(10)
monitor set pemuA,  thin(10)
monitor set pmueA,  thin(10)
monitor set pmumuA, thin(10)

monitor set Ree, thin(10)
monitor set Rmumu, thin(10)

monitor set ReeSimple, thin(10)
monitor set RmumuSimple, thin(10)

monitor set e1A,  thin(10)
monitor set e2A,  thin(10)
monitor set mu1A, thin(10)
monitor set mu2A, thin(10)



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

monitor set ReeToUse,     thin(10)
monitor set RmumuToUse,   thin(10)



update 10000
coda *
data to useddata
samplers to usedsamplers

 
  
