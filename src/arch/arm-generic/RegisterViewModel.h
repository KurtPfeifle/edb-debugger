/*
Copyright (C) 2017 - 2017 Evan Teran
                          evan.teran@gmail.com
Copyright (C) 2017 - 2017 Ruslan Kabatsayev
                          b7.10110111@gmail.com

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef REGISTER_VIEW_MODEL_ARM_20170813
#define REGISTER_VIEW_MODEL_ARM_20170813

#include "RegisterViewModelBase.h"
#include "Types.h"

class RegisterViewModel : public RegisterViewModelBase::Model
{
	Q_OBJECT

private:
	RegisterViewModelBase::Category* gprs;
	RegisterViewModelBase::Category* genStatusRegs;
	RegisterViewModelBase::Category* vfpRegs;
public:
	enum class CPUMode
	{
		UNKNOWN,
		Defined,
	};
public:
	RegisterViewModel(int CPUFeaturesPresent, QObject* parent = nullptr);
	QVariant data(QModelIndex const& index, int role=Qt::DisplayRole) const override;
	void setCPUMode(CPUMode mode);
	// NOTE: all these functions only change data, they don't emit dataChanged!
	// Use dataUpdateFinished() to have dataChanged emitted.
	void updateGPR(std::size_t i, edb::value32 val, QString const& comment=QString());
	void updateCPSR(edb::value32 val, QString const& comment=QString());
	void updateFPSCR(edb::value32 val, QString const& comment=QString());
private:
	void showAll();
	CPUMode mode=static_cast<CPUMode>(-1);
};

#endif
