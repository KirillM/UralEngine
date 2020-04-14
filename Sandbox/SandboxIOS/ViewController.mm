//
//  ViewController.m
//  SandboxIOS
//
//  Created by Кирилл Мезрин on 13.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#import "ViewController.h"
#include "Sandbox.mm"

#define GLES_SILENCE_DEPRECATION

Ural::Application* Ural::CreateApplication()
{
    return new Sandbox();
}

@interface ViewController () {
    Ural::Application* app;
}

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    GLKView *view = (GLKView *)self.view;
    view.context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES3];
    view.drawableDepthFormat = GLKViewDrawableDepthFormat16;
    [EAGLContext setCurrentContext:view.context];

    Ural::Log::Init();
    app = Ural::CreateApplication();
}

- (void)update {
    app->Run();
}

@end
