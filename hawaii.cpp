#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkStructuredGrid.h>
#include <vtkStructuredGridReader.h>
#include <vtkStructuredGridGeometryFilter.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkDataSet.h>
#include <vtkArrowSource.h>
#include <vtkGlyph3D.h>
#include <vtkPlane.h>
#include <vtkProp3D.h>
#include <vtkPolyData.h>
#include <vtkCutter.h>
#include <vtkProperty.h>
#include <vtkClipDataSet.h>
#include <vtkClipPolyData.h>
#include <sstream>
#include <vtkDataObject.h>
#include <vtkDataReader.h>
#include <vtkIdTypeArray.h>
#include <vtkSelection.h>
#include <vtkSelectionNode.h>
#include <vtkExtractSelection.h>
#include <vtkInformation.h>
#include <vtkDataSetMapper.h>
 
 vtkIdType numberOfPoints;
 vtkIdType numberOfCells;
 vtkIdType id;
 int dataTypeID;
 double big_bounds[6];
 
int main (int, char *[])
{
	  double x, y, z;
	vtkSmartPointer<vtkStructuredGridReader> reader =
    vtkSmartPointer<vtkStructuredGridReader>::New();
  reader->SetFileName("C:/Users/hannaLee/Desktop/이한나/VTK_과제/glider_하나짜리/density.vtk");
 
  reader->Update();
  //파일을 읽어와서
 /*
   float centerPos[3];
  reader->GetOutput()->GetCenter(centerPos);
  if ( reader->GetOutput()->GetPointData()->GetScalars() )
    {
    reader->GetOutput()->GetPointData()->GetScalars()->GetRange(range);
    }
  if ( reader->GetOutput()->GetPointData()->GetVectors() )
    {
   
    }
 

			  std::string filename = "C:/Users/hannaLee/Desktop/이한나/VTK_과제/glider_하나짜리/density.vtk";
			  std::ifstream filestream(filename.c_str());
 
 
			  std::string line;
			  vtkSmartPointer<vtkPoints> points =
				vtkSmartPointer<vtkPoints>::New();
 
			 
			  
			numberOfPoints = reader->GetOutput()->GetNumberOfPoints(); 
			numberOfCells = reader->GetOutput()->GetNumberOfCells();

			reader->GetOutput()->GetExtent();
			reader->GetOutput()->GetDimensions();
			std::cout << "numberOfPoints : " << numberOfPoints  << std::endl;
			std::cout << "numberOfScalar : " << numberOfCells << std::endl;
 

 */


  reader->GetOutput()->GetBounds(big_bounds);
	
  std::cout << "\n"  
			 << "xmin: " << big_bounds[0] << " " 
             << "xmax: " << big_bounds[1] << std::endl
             << "ymin: " << big_bounds[2] << " " 
             << "ymax: " << big_bounds[3] << std::endl
             << "zmin: " << big_bounds[4] << " " 
             << "zmax: " << big_bounds[5] << std::endl;

    std::cout << "There are " << reader->GetOutput()->GetNumberOfPoints()
            << " input points." << std::endl;
  std::cout << "There are " << reader->GetOutput()->GetNumberOfCells()
            << " input cells." << std::endl;
/*
  vtkSmartPointer<vtkIdTypeArray> ids =
    vtkSmartPointer<vtkIdTypeArray>::New();
  ids->SetNumberOfComponents(1);
    for(vtkIdType i = 0; i < reader->GetOutput()->GetNumberOfPoints()-15; i++)
    {
    ids->InsertNextValue(i);
    }

	vtkSmartPointer<vtkSelectionNode> selectionNode =
    vtkSmartPointer<vtkSelectionNode>::New();
  selectionNode->SetFieldType(vtkSelectionNode::POINT);
  selectionNode->SetContentType(vtkSelectionNode::INDICES);
  selectionNode->SetSelectionList(ids);
  selectionNode->GetProperties()->Set(vtkSelectionNode::CONTAINING_CELLS(), 1);
 
  vtkSmartPointer<vtkSelection> selection =
    vtkSmartPointer<vtkSelection>::New();
  selection->AddNode(selectionNode);
 
  vtkSmartPointer<vtkExtractSelection> extractSelection =
    vtkSmartPointer<vtkExtractSelection>::New();
 

    extractSelection->SetInputConnection(0, reader->GetOutputPort());
#if VTK_MAJOR_VERSION <= 5
  extractSelection->SetInput(1, selection);
#else
  extractSelection->SetInputData(1, selection);
#endif
  extractSelection->Update();


  vtkSmartPointer<vtkStructuredGrid> selected =
    vtkSmartPointer<vtkStructuredGrid>::New();
  selected->ShallowCopy(extractSelection->GetOutput());
 
  std::cout << "There are " << selected->GetNumberOfPoints()
            << " points in the selection." << std::endl;
  std::cout << "There are " << selected->GetNumberOfCells()
            << " cells in the selection." << std::endl;


    selectionNode->GetProperties()->Set(vtkSelectionNode::INVERSE(), 1); //invert the selection
  extractSelection->Update();
 
  vtkSmartPointer<vtkStructuredGrid> notSelected =
    vtkSmartPointer<vtkStructuredGrid>::New();
  notSelected->ShallowCopy(extractSelection->GetOutput());
 
  std::cout << "There are " << notSelected->GetNumberOfPoints()
            << " points NOT in the selection." << std::endl;
  std::cout << "There are " << notSelected->GetNumberOfCells()
            << " cells NOT in the selection." << std::endl;

   vtkSmartPointer<vtkDataSetMapper> inputMapper =
    vtkSmartPointer<vtkDataSetMapper>::New();
  inputMapper->SetInputConnection(reader->GetOutputPort());
  vtkSmartPointer<vtkActor> inputActor =
    vtkSmartPointer<vtkActor>::New();
  inputActor->SetMapper(inputMapper);
 
  vtkSmartPointer<vtkDataSetMapper> selectedMapper =
    vtkSmartPointer<vtkDataSetMapper>::New();
#if VTK_MAJOR_VERSION <= 5
  selectedMapper->SetInputConnection(selected->GetProducerPort());
#else
  selectedMapper->SetInputData(selected);
#endif
  vtkSmartPointer<vtkActor> selectedActor =
    vtkSmartPointer<vtkActor>::New();
  selectedActor->SetMapper(selectedMapper);
 
  vtkSmartPointer<vtkDataSetMapper> notSelectedMapper =
    vtkSmartPointer<vtkDataSetMapper>::New();
#if VTK_MAJOR_VERSION <= 5
  notSelectedMapper->SetInputConnection(notSelected->GetProducerPort());
#else
  notSelectedMapper->SetInputData(notSelected);
#endif
  vtkSmartPointer<vtkActor> notSelectedActor =
    vtkSmartPointer<vtkActor>::New();
  notSelectedActor->SetMapper(notSelectedMapper);
  */

  vtkArrowSource *arrow = vtkArrowSource :: New();
			arrow->SetTipResolution(3);
			arrow->SetTipRadius(0.1);
			arrow->SetTipLength(0.35);
			arrow->SetShaftResolution(3);
			arrow->SetShaftRadius(0.03);
		
			
			vtkGlyph3D	*glyph = vtkGlyph3D::New();
			glyph->SetInputConnection(0, reader->GetOutputPort());
			glyph->SetInputConnection(1, arrow->GetOutputPort());
			glyph->SetColorModeToColorByScalar();
			glyph->OrientOn();
			glyph->SetVectorModeToUseVector();
 
			vtkPolyDataMapper *glyphMapper = vtkPolyDataMapper::New(); 
			glyphMapper->SetInputConnection(glyph->GetOutputPort());
			glyphMapper->ScalarVisibilityOn();
			glyphMapper->SetScalarModeToUsePointData();
 
			vtkActor *glyphActor = vtkActor::New();
			glyphActor->SetMapper(glyphMapper);
 
 
 
  vtkSmartPointer<vtkStructuredGridGeometryFilter> geometryFilter =
    vtkSmartPointer<vtkStructuredGridGeometryFilter>::New();
  geometryFilter->SetInputConnection(reader->GetOutputPort());
  geometryFilter->Update();
 
  // Visualize
  vtkSmartPointer<vtkPolyDataMapper> mapper =
    vtkSmartPointer<vtkPolyDataMapper>::New();
  mapper->SetInputConnection(geometryFilter->GetOutputPort());
 
  vtkSmartPointer<vtkActor> actor =
    vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);
 
 
  vtkSmartPointer<vtkRenderer> renderer =
    vtkSmartPointer<vtkRenderer>::New();
  vtkSmartPointer<vtkRenderWindow> renderWindow =
    vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);
  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
    vtkSmartPointer<vtkRenderWindowInteractor>::New();
  renderWindowInteractor->SetRenderWindow(renderWindow);
 
 
  renderWindow->SetSize(500,500);
  renderer->AddActor(actor);
  //  renderer->AddActor(selectedActor);
 renderer->AddActor(glyphActor);
 // renderer->AddActor(clipActor);
  renderer->SetBackground(0.5, 0.5, 0.6); // Background color green
 
  renderWindow->Render();
  renderWindowInteractor->Start();
}