#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include "abstractmodelmanager.h"
#include "abstractmodel.h"

#include <QOpenGLShaderProgram>
#include <QSharedPointer>

typedef QSharedPointer<QOpenGLShaderProgram> QOpenGLShaderProgramPtr;

using namespace std;

class Model;
class AbstractModel;

class ModelManager : public AbstractModelManager
{

public:
    ModelManager(const QOpenGLShaderProgramPtr& shader);
    virtual ~ModelManager();

    virtual AbstractModel* getModel(const string& name);
    virtual void loadModel(const string& name, const string& filename);
    virtual unique_ptr<AbstractModel> createModel(const string& name);

    // virtual unique_ptr<AbstractModel> createModel(Mesh* mesh);
    // virtual unique_ptr<AbstractModel> createModel(vector<shared_ptr<ModelData>> modelData);

private:
    map<string, unique_ptr<Model>> m_models;
    QOpenGLShaderProgramPtr m_shader;
};

#endif // MODELMANAGER_H