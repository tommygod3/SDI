#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
	this->setFixedSize(900, 600);
	backend = new SDI::controller();
}

MainWindow::~MainWindow()
{
    delete ui;
	delete backend;
}

void MainWindow::on_buttonToAddProjects_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_buttonToBrowseProjects_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

	ui->comboBrowseProjProjResults->clear();
	std::vector<unsigned long long> idAlpha = backend->getAlphabeticProjects();
	for (unsigned int i = 0; i < idAlpha.size(); i++)
	{
		ui->comboBrowseProjProjResults->addItem(QString::fromStdString(backend->getNameFromId(idAlpha.at(i))), QVariant((idAlpha.at(i))));
	}
	ui->comboBrowseProjProjResults->setCurrentIndex(0);
	unsigned long long currentId = ui->comboBrowseProjProjResults->itemData(ui->comboBrowseProjProjResults->currentIndex()).toULongLong();
	backend->setCurrentProject(currentId);
}

void MainWindow::on_buttonToMaintenance_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_buttonAddProjHome_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_buttonHomeAddMaterials_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_buttonHomeBrowseProj_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_buttonHomeMaintenance_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_radioButtonAddProjUnreleased_clicked()
{
    ui->labelAddProjTicketSale->setVisible(false);
    ui->spinBoxAddProjTicketSale->setVisible(false);
}

void MainWindow::on_radioButtonAddProjReleased_clicked()
{
    ui->labelAddProjTicketSale->setVisible(false);
    ui->spinBoxAddProjTicketSale->setVisible(false);
}

void MainWindow::on_radioButtonAddProjNowPlaying_clicked()
{
    ui->labelAddProjTicketSale->setVisible(true);
    ui->spinBoxAddProjTicketSale->setVisible(true);
}

void MainWindow::on_radioButtonAddMaterialsVHS_clicked()
{
    ui->frameAddMaterialsAdditional->setVisible(false);
    ui->frameAddMaterialsSides->setVisible(false);
    ui->frameAddMaterialsSidesMovieList->setVisible(false);
    ui->buttonAddMaterialsSave->setGeometry(680,250,130,40);
    ui->comboAddMaterialsPackaging->clear();
    ui->comboAddMaterialsPackaging->addItem("Cardboard box");
    ui->comboAddMaterialsPackaging->addItem("Plastic box");
}

void MainWindow::on_radioButtonAddMaterialsDVD_clicked()
{
    ui->frameAddMaterialsAdditional->setVisible(true);
    ui->frameAddMaterialsSides->setVisible(false);
    ui->frameAddMaterialsSidesMovieList->setVisible(false);
    ui->buttonAddMaterialsSave->setGeometry(680,250,130,40);
    ui->comboAddMaterialsPackaging->clear();
    ui->comboAddMaterialsPackaging->addItem("Plastic box");

}

void MainWindow::on_radioButtonAddMaterialsBluray_clicked()
{
    ui->frameAddMaterialsAdditional->setVisible(true);
    ui->frameAddMaterialsSides->setVisible(false);
    ui->frameAddMaterialsSidesMovieList->setVisible(false);
    ui->buttonAddMaterialsSave->setGeometry(680,250,130,40);
    ui->comboAddMaterialsPackaging->clear();
    ui->comboAddMaterialsPackaging->addItem("Plastic box");
}

void MainWindow::on_radioButtonAddMaterialsDoubleDVD_clicked()
{
    ui->frameAddMaterialsAdditional->setVisible(true);
    ui->frameAddMaterialsSides->setVisible(true);
    ui->frameAddMaterialsSidesMovieList->setVisible(true);
    ui->frameAddMaterialsSidesMovieList->setGeometry(500,380,131,111);
    ui->buttonAddMaterialsSave->setGeometry(680,450,130,40);
    ui->comboAddMaterialsPackaging->clear();
    ui->comboAddMaterialsPackaging->addItem("Plastic box");
}

void MainWindow::on_radioButtonAddMaterialsCombo_clicked()
{
    ui->frameAddMaterialsAdditional->setVisible(true);
    ui->frameAddMaterialsSides->setVisible(false);
    ui->frameAddMaterialsSidesMovieList->setVisible(true);
    ui->frameAddMaterialsSidesMovieList->setGeometry(500,250,131,111);
    ui->buttonAddMaterialsSave->setGeometry(680,320,130,40);
    ui->comboAddMaterialsPackaging->clear();
    ui->comboAddMaterialsPackaging->addItem("Cardboard box");
}

void MainWindow::on_buttonBrowseProjSearchByProj_clicked()
{
	//Filter by actor
	ui->comboBrowseProjProjResults->clear();
	std::vector<unsigned long long> idAlpha = backend->getAlphabeticProjects();
	std::string filterActor = ui->textBrowseProjSearchByActor->text().toStdString();
	std::vector<unsigned long long> idFiltered = backend->getProjectsActorFilter(filterActor, idAlpha);
	//Then filter by title on top
	std::string filterTitle = ui->textBrowseProjSearchByProj->text().toStdString();
	idFiltered = backend->getProjectsTitleFilter(filterTitle, idFiltered);
	for (unsigned int i = 0; i < idFiltered.size(); i++)
	{
		ui->comboBrowseProjProjResults->addItem(QString::fromStdString(backend->getNameFromId(idFiltered.at(i))), QVariant((idFiltered.at(i))));
	}
	ui->comboBrowseProjProjResults->setCurrentIndex(0);
	unsigned long long currentId = ui->comboBrowseProjProjResults->itemData(ui->comboBrowseProjProjResults->currentIndex()).toULongLong();
	backend->setCurrentProject(currentId);
}

void MainWindow::on_buttonBrowseProjSearchByActor_clicked()
{
	//Filter by title
	ui->comboBrowseProjProjResults->clear();
	std::vector<unsigned long long> idAlpha = backend->getAlphabeticProjects();
	std::string filterTitle = ui->textBrowseProjSearchByProj->text().toStdString();
	std::vector<unsigned long long> idFiltered = backend->getProjectsTitleFilter(filterTitle, idAlpha);
	//Then filter by actor on top
	std::string filterActor = ui->textBrowseProjSearchByActor->text().toStdString();
	idFiltered = backend->getProjectsActorFilter(filterActor, idFiltered);
	for (unsigned int i = 0; i < idFiltered.size(); i++)
	{
		ui->comboBrowseProjProjResults->addItem(QString::fromStdString(backend->getNameFromId(idFiltered.at(i))), QVariant((idFiltered.at(i))));
	}
	ui->comboBrowseProjProjResults->setCurrentIndex(0);
	unsigned long long currentId = ui->comboBrowseProjProjResults->itemData(ui->comboBrowseProjProjResults->currentIndex()).toULongLong();
	backend->setCurrentProject(currentId);
}

void MainWindow::on_buttonBrowseProjAddMaterial_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_buttonBrowseProjViewProj_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_buttonHomeEditProj_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_buttonHomeEditMaterials_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_buttonBrowseProjEditMaterial_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_radioButtonEditProjNowPlaying_clicked()
{
    ui->labelEditProjTicketSale->setVisible(true);
    ui->spinBoxEditProjTicketSale->setVisible(true);
}

void MainWindow::on_radioButtonEditProjUneleased_clicked()
{
    ui->labelEditProjTicketSale->setVisible(false);
    ui->spinBoxEditProjTicketSale->setVisible(false);
}

void MainWindow::on_radioButtonEditProjReleased_clicked()
{
    ui->labelEditProjTicketSale->setVisible(false);
    ui->spinBoxEditProjTicketSale->setVisible(false);
}

void MainWindow::on_radioButtonlEditMaterialsDVD_clicked()
{
    ui->frameEditMaterialsAdditional->setVisible(true);
    ui->frameEditMaterialsSides->setVisible(false);
    ui->frameEditMaterialsMovieList->setVisible(false);
    ui->buttonEditMaterialsSave->setGeometry(680,250,130,40);
    ui->comboEditMaterialPackaging->clear();
    ui->comboEditMaterialPackaging->addItem("Plastic box");
}

void MainWindow::on_radioButtonlEditMaterialsDoubleDVD_clicked()
{
    ui->frameEditMaterialsAdditional->setVisible(true);
    ui->frameEditMaterialsMovieList->setVisible(true);
    ui->frameEditMaterialsSides->setVisible(true);
    ui->frameEditMaterialsSides->setGeometry(500,380,131,111);
    ui->buttonEditMaterialsSave->setGeometry(680,450,130,40);
    ui->comboEditMaterialPackaging->clear();
    ui->comboEditMaterialPackaging->addItem("Plastic box");
}

void MainWindow::on_radioButtonlEditMaterialsCombo_clicked()
{
    ui->frameEditMaterialsAdditional->setVisible(true);
    ui->frameEditMaterialsSides->setVisible(false);
    ui->frameEditMaterialsMovieList->setVisible(true);
    ui->frameEditMaterialsMovieList->setGeometry(500,250,131,111);
    ui->buttonEditMaterialsSave->setGeometry(680,320,130,40);
    ui->comboEditMaterialPackaging->clear();
    ui->comboEditMaterialPackaging->addItem("Cardboard box");
}

void MainWindow::on_radioButtonlEditMaterialsVHS_clicked()
{

    ui->frameEditMaterialsAdditional->setVisible(false);
    ui->frameEditMaterialsSides->setVisible(false);
    ui->frameEditMaterialsMovieList->setVisible(false);
    ui->buttonEditMaterialsSave->setGeometry(680,250,130,40);
    ui->comboEditMaterialPackaging->clear();
    ui->comboEditMaterialPackaging->addItem("Cardboard box");
    ui->comboEditMaterialPackaging->addItem("Plastic box");
}

void MainWindow::on_radioButtonlEditMaterialBluray_clicked()
{
    ui->frameEditMaterialsAdditional->setVisible(true);
    ui->frameEditMaterialsSides->setVisible(false);
    ui->frameEditMaterialsMovieList->setVisible(false);
    ui->buttonEditMaterialsSave->setGeometry(680,250,130,40);
    ui->comboEditMaterialPackaging->clear();
    ui->comboEditMaterialPackaging->addItem("Plastic box");
}

void MainWindow::on_buttonAddProjectsSave_clicked()
{
	//Making new project
	SDI::project* current = new SDI::project(backend->getNextProjectId(), false);
	
	std::string date = QString(ui->dateAddProjReleaseDate->date().toString("dd.MM.yyyy")).toStdString();
	current->setReleaseDate(date);
}

void MainWindow::on_buttonAddMaterialsSave_clicked()
{

}

void MainWindow::on_buttonEditProjSave_clicked()
{

}

void MainWindow::on_buttonEditMaterialsSave_clicked()
{

}

void MainWindow::on_buttonBrowseProjDeleteProj_clicked()
{

}

void MainWindow::on_buttonBrowseProjDeleteMaterial_clicked()
{

}
