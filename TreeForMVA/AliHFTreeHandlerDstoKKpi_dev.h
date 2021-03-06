#ifndef ALIHFTREEHANDLERDSTOKKPI_DEV_H
#define ALIHFTREEHANDLERDSTOKKPI_DEV_H

/* Copyright(c) 1998-2008, ALICE Experiment at CERN, All rights reserved. *
 * See cxx source for full Copyright notice                               */

/* $Id$ */

//*************************************************************************
// \class AliHFTreeHandlerDstoKKpi_dev
// \brief helper class to handle a tree for D+ cut optimisation and MVA analyses
// \authors:
// F. Catalano, fabio.catalano@cern.ch
// A. Festanti, andrea.festanti@cern.ch
// F. Grosa, fabrizio.grosa@cern.ch
// G. Innocenti, gian.michele.innocenti@cern.ch
// F. Prino, prino@to.infn.it
// L. Vermunt, luuk.vermunt@cern.ch
// L. van Doremalen, lennart.van.doremalen@cern.ch
// J. Norman, jaime.norman@cern.ch
/////////////////////////////////////////////////////////////

#include "AliHFTreeHandler_dev.h"

class AliHFTreeHandlerDstoKKpi_dev : public AliHFTreeHandler_dev
{
  public:

    enum massKKopt {kMassKK,kDeltaMassKKPhi};

    static const int kDplustoKKpi = BIT(6);

    AliHFTreeHandlerDstoKKpi_dev();
    AliHFTreeHandlerDstoKKpi_dev(int PIDopt);

    virtual ~AliHFTreeHandlerDstoKKpi_dev();

    virtual TTree* BuildTree(TString name="tree", TString title="tree");
    virtual bool SetVariables(AliAODRecoDecayHF* cand, float bfield, int masshypo=0, AliPIDResponse* pidrespo=0x0);
    virtual void FillTree();

    void SetMassKKOption(int opt) {fMassKKOpt=opt;}
    void SetIsDplustoKKpi(bool isDplus) {
      if(isDplus) fCandTypeMap |= kDplustoKKpi;
      else fCandTypeMap &= ~kDplustoKKpi;
    }
  
    static bool IsDplustoKKpi(int candtype) {
      if(candtype>>6&1) return true;
      return false;
    }

  private:

    vector<float> fImpParProng[knMaxProngs]; ///vectors of prong impact parameter
    vector<float> fSigmaVertex; /// vector of candidate sigma vertex
    vector<float> fMassKK; /// vector of candidate massKK
    vector<float> fCosPiDs; /// vector of candidate cos3piDs
    vector<float> fCosPiKPhi; /// vector of candidate cospiKphi
    vector<float> fNormd0MeasMinusExp; ///vector of candidate topomatic variable
    int fMassKKOpt; /// option for massKK variable (mass or delta mass wrt phi)

    /// \cond CLASSIMP
    ClassDef(AliHFTreeHandlerDstoKKpi_dev,1); /// 
    /// \endcond
};
#endif
