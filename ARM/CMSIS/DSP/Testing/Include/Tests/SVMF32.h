#include "Test.h"
#include "Pattern.h"
class SVMF32:public Client::Suite
    {
        public:
            SVMF32(Testing::testID_t id);
            virtual void setUp(Testing::testID_t,std::vector<Testing::param_t>& params,Client::PatternMgr *mgr);
            virtual void tearDown(Testing::testID_t,Client::PatternMgr *mgr);
        private:
            #include "SVMF32_decl.h"
            Client::Pattern<float32_t> samples;
            Client::Pattern<int16_t> dims;
            Client::Pattern<float32_t> params;

            Client::RefPattern<int32_t> ref;
            Client::LocalPattern<int32_t> output;

            arm_svm_linear_instance_f32 linear;
            arm_svm_polynomial_instance_f32 poly;
            arm_svm_rbf_instance_f32 rbf;
            arm_svm_sigmoid_instance_f32 sigmoid;

            int vecDim,nbSupportVectors,nbTestSamples,degree;
            int32_t classes[2]={0,0};
            float32_t intercept;
            const float32_t *supportVectors;
            const float32_t *dualCoefs;
            float32_t coef0, gamma;

            enum {
                LINEAR=1,
                POLY=2,
                RBF=3,
                SIGMOID=4
            } kind;

            
    };
