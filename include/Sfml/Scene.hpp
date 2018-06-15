//
// EPITECH PROJECT, 2018
// ProjectName
// File description:
// SceneManager
//

#pragma once

#include <stack>
#include <vector>
#include <unordered_map>


class AScene;

class SceneManager {
public:
    bool frameStarted(float timeSinceLastFrame);
    bool frameRenderingQueued(float timeSinceLastFrame);
};
//
//class AScene;
//
//class SceneManager : public Ogre::FrameListener, public OgreBites::InputListener {
//public:
//    void setup(Ogre::Root *root, Ogre::RenderWindow *win, Ogre::OverlaySystem *sys);
//    /*
//     * From FrameListener
//     */
//    bool frameStarted(const Ogre::FrameEvent &fe) override;
//    bool frameRenderingQueued(const Ogre::FrameEvent &fe) override;
//
//    /*
//     * From InputListener
//     */
//    bool keyPressed(const OgreBites::KeyboardEvent &evt) override;
//    bool keyReleased(const OgreBites::KeyboardEvent &evt) override;
//	bool mouseMoved(const OgreBites::MouseMotionEvent& evt) override;
//	bool mousePressed(const OgreBites::MouseButtonEvent &evt) override;
//	bool mouseReleased(const OgreBites::MouseButtonEvent &evt) override;
//
//    /*
//     * Scenes Handlers
//     */
//    void changeScene(AScene *scene);
//    void pushScene(AScene *scene);
//    void popScene();
//    void pauseScene();
//    void resumeScene();
//    void popAllAndPushScene(AScene *scene);
//
//    /*
//     * Getters
//     */
//    Ogre::Root *getRoot() const noexcept { return root_; }
//    Ogre::RenderWindow *getRenderWindow() const noexcept { return win_; }
//    Ogre::OverlaySystem *getOverlaySystem() const noexcept { return sys_; }
//    AScene *top() const noexcept { return scenes_.top(); }
//private:
//    Ogre::Root *root_;
//    Ogre::RenderWindow *win_;
//    Ogre::OverlaySystem *sys_;
//    std::stack<AScene *> scenes_;
//};
//
//
//class AScene : public OgreBites::TrayManager {
//protected:
//    AScene(std::string &&name, SceneManager *parent)
//	    : OgreBites::TrayManager(name, parent->getRenderWindow(), this),
//	      parent_(parent),
//	      root_(parent->getRoot()),
//	      window_(parent->getRenderWindow()),
//	      sys_(parent->getOverlaySystem()),
//	      scene_(root_->createSceneManager())
//    {
//	    shaderG_ = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
//	    shaderG_->addSceneManager(scene_);
//	    scene_->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_MODULATIVE);
//    }
//
//public:
//    virtual void enter()
//    {
//	    window_->removeAllViewports();
//	    window_->addViewport(camMgr_.getCamera());
//	    /*
//	     * Overlay to the current SceneManager
//	     */
//	    scene_->addRenderQueueListener(sys_);
//    }
//
//    virtual void exit()
//    {
//	    scene_->removeRenderQueueListener(sys_);
//	    scene_->destroyCamera(camMgr_.getCamera());
//    }
//
//    virtual void pause() { music_.pause(); }
//    virtual void resume()
//    {
//	    window_->removeAllViewports();
//	    window_->addViewport(camMgr_.getCamera());
//	    music_.play();
//    }
//
//    virtual void update(double timeSinceLastFrame) = 0;
//
//    /*
//     * Events
//     */
//    bool keyPressed(const OgreBites::KeyboardEvent &evt) override = 0;
//    bool keyReleased(const OgreBites::KeyboardEvent &evt) override = 0;
//	bool mouseMoved(const OgreBites::MouseMotionEvent &evt) override = 0;
//	bool mousePressed(const OgreBites::MouseButtonEvent &evt) override = 0;
//	bool mouseReleased(const OgreBites::MouseButtonEvent &evt) override = 0;
//
//    /*
//     * From TrayListener
//     */
//	void buttonHit(OgreBites::Button* button) override = 0;
//
//    /*
//     * Create a scene
//     */
//    template<typename T>
//    static void create(std::string &&name, SceneManager *parent) {
//	    auto *scene = new T(std::move(name), parent);
//	    parent->pushScene(scene);
//    }
//
//    // A scene is also a World
//    Entity &createEntity()
//    {
//    	entities_.emplace_back();
//    	return entities_.back();
//    }
//
//    void refresh()
//    {
//	    for (auto &sys : systems_) {
//		    sys.get().clear();
//		    for (auto ent = entities_.begin(); ent != entities_.end();) {
//			    if (ent->isDesactivated())
//				    ent = entities_.erase(ent);
//			    else {
//				    if (matchFilter(*ent, sys.get().getFilter()))
//					    sys.get().addEntity(*ent);
//				    ++ent;
//			    }
//		    }
//	    }
//    }
//
//    void addSystem(BaseSystem &system)
//    {
//	    systems_.emplace_back(system);
//    }
//
//    Ogre::SceneManager *getSceneManager() { return scene_; }
//protected:
//    SceneManager *parent_;
//    Ogre::Root *root_;
//    Ogre::RenderWindow *window_;
//    Ogre::OverlaySystem *sys_;
//    Ogre::SceneManager *scene_;
//
//    CameraManager camMgr_;
//    std::vector<Entity> entities_;
//    std::vector<std::reference_wrapper<BaseSystem>> systems_;
//
//    sf::Music music_;
//private:
//    Ogre::RTShader::ShaderGenerator *shaderG_;
//};
