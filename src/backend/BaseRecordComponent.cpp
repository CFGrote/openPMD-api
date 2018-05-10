#include "openPMD/backend/BaseRecordComponent.hpp"


namespace openPMD
{
double
BaseRecordComponent::unitSI() const
{
    return getAttribute("unitSI").get< double >();
}

BaseRecordComponent&
BaseRecordComponent::resetDatatype(Datatype d)
{
    if( written )
        throw std::runtime_error("A Records Datatype can not (yet) be changed after it has been written.");

    m_dataset->dtype = d;
    return *this;
}

BaseRecordComponent::BaseRecordComponent()
        : m_dataset{std::make_shared< Dataset >(Dataset(Datatype::UNDEFINED, {}))},
          m_isConstant{std::make_shared< bool >(false)}
{ }

Datatype
BaseRecordComponent::getDatatype() const
{
    return m_dataset->dtype;
}
} // openPMD
